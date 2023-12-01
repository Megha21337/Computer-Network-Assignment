import matplotlib.pyplot as plt
from scapy.all import rdpcap, IP, TCP

def calculate_cwnd(packet):
    cwnd = []
    i = 0
    while i < len(packet):
        pkt = packet[i]
        if TCP in pkt:
            seq_num = pkt[TCP].seq
            ack_num = pkt[TCP].ack
            cwnd.append(ack_num - seq_num)
        i += 1
    return cwnd

capture_file = 'h1_capture.pcap'

packets = rdpcap(capture_file)

congestion_window = calculate_cwnd(packets)

plt.plot(congestion_window)
plt.xlabel('Packet Number')
plt.ylabel('Congestion Window Size (bytes)')
plt.title('TCP Congestion Window Over Time')
plt.show()