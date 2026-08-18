#!/bin/bash

wget --quiet https://archives.boost.io/release/1.92.0/source/boost_1_92_0.tar.bz2
tar -xf boost_1_92_0.tar.bz2

sudo ./boost_1_92_0/bootstrap.sh --prefix=/usr/local
echo "Run b2"
sudo ./b2

echo "Run b2 headers"
sudo ./b2 headers

echo "Run b2 install"
sudo ./b2 install --prefix=/usr/local
