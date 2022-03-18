#!/bin/bash

source /opt/tool-imx6q/environment-setup-cortexa9hf-neon-poky-linux-gnueabi
qmake
make clean
make

cp ./QTemperature /tftpboot
