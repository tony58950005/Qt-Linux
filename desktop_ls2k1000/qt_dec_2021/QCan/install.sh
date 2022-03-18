#!/bin/bash

source /opt/tool-imx6ull/environment-setup-cortexa7hf-neon-poky-linux-gnueabi
qmake
make clean
make

cp ./QCan /tftpboot
