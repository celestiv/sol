#include "packet_analyzer.h"

namespace packet_analyzer {

void packetHandler(u_char* param, const struct pcap_pkthdr* header,
                   const u_char* packet) {
  (void)param;
  printf("Packet recieved: %d bytes\n", header->len);
  for (bpf_u_int32 i = 0; i < header->len; i++) {
    printf("%02x", packet[i]);
    if (i % 2 == 1) {
      printf(" ");
    }
  }
  printf("\n");
}

std::vector<std::pair<std::string, std::string>> getOptions(int argc,
                                                            char* argv[]) {
  int opt;
  std::vector<std::pair<std::string, std::string>> options;

  while ((opt = getopt(argc, argv, "i:p:h")) != -1) {
    switch (opt) {
      case 'i':
        std::cout << "found flag -i" << argv[opt] << std::endl;
        options.emplace_back(std::make_pair("-i", argv[opt]));
        break;
      case 'p':
        std::cout << "found flag -p" << argv[opt] << std::endl;
        options.emplace_back(std::make_pair("-p", argv[opt]));
        break;
      case 'h':
        std::cout
            << "Usage: "
            << "./analyzer -p <port number> -i <interface name to analyze>"
            << std::endl;
        break;
      default:
        std::cerr
            << "Usage: "
            << "./analyzer -p <port number> -i <interface name to analyze>"
            << std::endl;
    }
  }
  return options;
}
}  // namespace packet_analyzer