#!/bin/bash

port=80
interface="eth0"

while getopts "i:p:" opt; do
  case $opt in
    i) interface="$OPTARG";;
    p) port="$OPTARG";;
  esac
done

make build

if [ ! $? -eq 0 ]; then
    echo "Compilation error"
    exit 1
else
    ./analyzer -i "$interface" -p "$port"
fi
