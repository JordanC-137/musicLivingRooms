#!/bin/bash

wget https://archives.boost.io/release/1.92.0/source/boost_1_92_0.tar.bz2
tar -xf boost_1_92_0.tar.bz2

echo "Present dir: ${PWD}"
echo "List Dirs"
ls -R .
./boost_1_92_0/bootstrap.sh --prefix=/usr/local
./boost_1_92_0/b2
./boost_1_92_0/b2 install
