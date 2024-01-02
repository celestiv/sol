#include "packet_analyzer.h"

int main(int argc, char* argv[]) {
  using namespace packet_analyzer;

  std::vector<std::pair<std::string, std::string>> options =
      getOptions(argc, argv);
  for (const auto& option : options) {
    std::cout << "Опция: " << option.first << ", значение: " << option.second
              << std::endl;
  }
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t* pcap = pcap_open_live("eth0", 65535, 1, 0, errbuf);

  if (pcap == NULL) {
    printf("Error opening device: %s\n", errbuf);
    return 1;
  }

  if (pcap_loop(pcap, 0, packetHandler, NULL) < 0) {
    printf("Error in pcap_loop\n");
    return 1;
  }

  pcap_close(pcap);
  return 0;
}
