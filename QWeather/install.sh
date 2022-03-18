#!/bin/bash

source /opt/im6ul-sdk/environment-setup-cortexa7hf-neon-poky-linux-gnueabi
qmake
make clean
make

cp ./QWeather /tftpboot
