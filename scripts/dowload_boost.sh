#!/bin/bash

wget https://archives.boost.io/release/1.92.0/source/boost_1_92_0.tar.bz2
tar xf boost_1_92_0.tar.bz2
cd boost_1_92_0.tar.bz2

./boostrap.sh --prefix=/usr/local
./b2
./b2 install