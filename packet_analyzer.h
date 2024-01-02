#ifndef __SOLAR_DNS_PACKET_ANALYZER__
#define __SOLAR_DNS_PACKET_ANALYZER__

#include <pcap/pcap.h>
#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <vector>

namespace packet_analyzer {
class PacketAnalyzer {
 public:
  PacketAnalyzer();
  int initAnalyzer();
  int processPackets(pcap_if_t* d);

  char errbuff[PCAP_ERRBUF_SIZE];
  pcap_if_t** alldevsp;

 private:
};

std::vector<std::pair<std::string, std::string>> getOptions(int argc,
                                                            char* argv[]);
void packetHandler(u_char* param, const struct pcap_pkthdr* header,
                   const u_char* packet);
}  // namespace packet_analyzer

#endif  // __SOLAR_DNS_PACKET_ANALYZER__