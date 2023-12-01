from mininet.topo import Topo

class customTopo(Topo):

  def build(self):
    #Adding hosts and switches
    H1_S1 = self.addHost( 'h1' )
    H2_S1 = self.addHost( 'h2' )
    H3_S2 = self.addHost( 'h3' )
    H4_S2 = self.addHost( 'h4' )
    H5_S2 = self.addHost( 'h5' )
    H6_S3 = self.addHost( 'h6' )
    H7_S3 = self.addHost( 'h7' )
    H8_S3 = self.addHost( 'h8' )
    
    s1_Switch = self.addSwitch( 's1' )
    s2_Switch = self.addSwitch( 's2' )
    s3_Switch = self.addSwitch( 's3' )

    # Add links
    self.addLink( H1_S1, s1_Switch )
    self.addLink( s2_Switch, s1_Switch )
    self.addLink( H2_S1, s1_Switch )

    self.addLink( H3_S2, s2_Switch )
    self.addLink( s2_Switch, s3_Switch )
    self.addLink( H4_S2, s2_Switch )
    self.addLink( H5_S2, s2_Switch )

    self.addLink( H6_S3, s3_Switch )
    self.addLink( H7_S3, s3_Switch )
    self.addLink( H8_S3, s3_Switch )
   
topos = { 'mytopo': ( lambda: customTopo() ) }
