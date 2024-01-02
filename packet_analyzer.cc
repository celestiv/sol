#include "packet_analyzer.h"

namespace packet_analyzer {
PacketAnalyzer::PacketAnalyzer() {}
// PacketAnalyzer::~PacketAnalyzer() {}

int PacketAnalyzer::initAnalyzer() {
  // pcap_init();
  if (pcap_findalldevs(alldevsp, errbuff) == PCAP_ERROR) {
    fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuff);
    return 1;
  }

  if (alldevsp == NULL) {
    fprintf(stderr, "Packet analyzer: no devices found by pcap_findalldevs");
    return 1;
  }

  for (pcap_if_t* d = *alldevsp; d; d = d->next) {
    int ret = processPackets(d);
    printf("Success from loop %d", ret);
  }

  pcap_freealldevs(*alldevsp);
  return 0;
}

int PacketAnalyzer::processPackets(pcap_if_t* d) {
  std::cout << "packet handler works" << std::endl;
  pcap_t* pcap = pcap_open_live(d->name, 65535, 1, 0, errbuff);

  if (pcap == NULL) {
    printf("Error opening device %s: %s\n", d->name, errbuff);
    return 1;
  }

  if (pcap_loop(pcap, 0, packetHandler, NULL) < 0) {
    printf("Error in pcap_loop() for device %s\n", d->name);
    return 1;
  }
  return 0;
}

}  // namespace packet_analyzer