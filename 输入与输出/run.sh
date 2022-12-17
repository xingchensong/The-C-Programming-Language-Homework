#!/bin/bash
# Copyright [2022-12-17] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

gcc ./p161_cat.c -o a.out
./a.out ./p161_cat.c
rm -f ./a.out
