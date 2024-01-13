#!/bin/bash

port=80
interface="eth0"

while getopts "i:p:" opt; do
  case $opt in
    i) interface="$OPTARG" ;;
    p) port="$OPTARG" ;;
    *) echo "only -i and -p options available"; exit 1 ;;
  esac
done

make build

if [[ ! -f analyzer ]]; then
    echo "Compilation error"
    exit 1
else
    ./analyzer -i "$interface" -p "$port"
fi
