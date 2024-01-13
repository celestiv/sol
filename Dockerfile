FROM debian:latest

WORKDIR /solar_dns/

COPY . .

RUN apt update && \
    apt -y upgrade && \
    apt install -y libpcap-dev

ENTRYPOINT ["bash", "run.sh"]