#!/bin/bash

wget https://archives.boost.io/release/1.92.0/source/boost_1_92_0.tar.bz2
tar -xf boost_1_92_0.tar.bz2

sudo ./boost_1_92_0/bootstrap.sh --prefix=/usr/local
sudo ./b2
sudo ./b2 headers
sudo ./b2 install --prefix=/usr/local
