CFLAGS=-Wall -Werror -Wextra -std=c++17
SRC=${find . -name "*.cc"}
EXECUTABLE=analyzer

all:
	build

build:
	g++ ${CFLAGS} packet_analyzer.cc main.cc handler.cc -o ${EXECUTABLE} -lpcap

style:
	clang-format -style=Google -i *.cc *.h

clean:
	rm -f ${EXECUTABLE} *.o *.a
