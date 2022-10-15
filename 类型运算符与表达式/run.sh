#!/bin/bash
# Copyright [2022-10-15] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

echo "p42_atoi"
gcc ./p42_atoi.cc
./a.out
rm -f ./a.out

echo "p47_strcat"
gcc ./p47_strcat.cc
./a.out
rm -f ./a.out
