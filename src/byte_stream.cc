#include "byte_stream.hh"

#include <algorithm>
#include<deque>
#include <cstdint>


// You will need to add private members to the class declaration in `byte_stream.hh`

/* Replace all the dummy definitions inside the methods in this file. */


using namespace std;

ByteStream::ByteStream(const size_t capa)
{
 capacity=capa;
 end=false;
 bytes_Write=0;
  bytes_Read=0;
}
size_t ByteStream::write(const string &data) {
 if(input_ended() || _error){
 return 0;
 }
 int written=0;
 for(char Byte : data){
 if(buffer_s.size()<capacity){
 buffer_s.push_back(Byte);
 written++;
 bytes_Write++;}
 //else{
 //return 0;}
 }
 
  return written;
}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
size_t i=min(len,buffer_s.size());
string copy_output;
for(size_t j=0;j<i ; j++){
copy_output+= buffer_s[j];
}
  return copy_output;
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) {
  size_t length = min(len,buffer_s.size());
  if(len> buffer_s.size()){
  set_error();}
  else{
  for(int i=0;i<length;i++){
  buffer_s.pop_front();}
  }
  bytes_Read+= length;
}

//! Read (i.e., copy and then pop) the next "len" bytes of the stream
//! \param[in] len bytes will be popped and returned
//! \returns a string
std::string ByteStream::read(const size_t len) {
  string output_read;
  if(len> buffer_s.size()){
  set_error();}
  output_read=peek_output(len);
  pop_output(len);
  return output_read;
}

void ByteStream::end_input() { 
end=true;
}

bool ByteStream::input_ended() const { return end;}

size_t ByteStream::buffer_size() const {return buffer_s.size(); }

bool ByteStream::buffer_empty() const {return buffer_s.empty(); }

bool ByteStream::eof() const { 
return input_ended() && buffer_empty(); }

size_t ByteStream::bytes_written() const { 

return bytes_Write; 
}

size_t ByteStream::bytes_read() const { return bytes_Read;  }

size_t ByteStream::remaining_capacity() const { return capacity - buffer_s.size(); }
