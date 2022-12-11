#!/bin/bash
# Copyright [2022-10-15] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

echo "
fsafasd
fghdjsaOULDgfhjdskgafgahsjdfgkj
fghyttfv
fghdjsagfhjdskgafgahsjdfgkjOULD
OULDfghdjsagfhjdskgafgahsjdfgkj
OULDfghdjsagfhjdskgafgahsjdfgkjOULD
fttfv
" > test_case

echo "p67_grep.c:"
gcc ./p67_grep.c
./a.out < test_case

echo ""

echo "p67_grep_right.c:"
gcc ./p67_grep_right.c
./a.out < test_case
rm -f ./a.out
rm -f test_case

echo ""

echo "p74_calculator.c:"
# 编译器自动整合不同c文件中的函数
gcc -I $PWD ./p74_calculator.c ./utils/getch.c ./utils/getop.c ./utils/stack.c ./utils/stack_value.c -o a.out
echo "case1: 1 2 - 4 5 + *"
echo "1 2 - 4 5 + *" > test_case
./a.out < test_case
echo "case2: 1 2.0 - 4.1 5.2 + *"
echo "1 2.0 - 4.1 5.2 + *" > test_case
./a.out < test_case
rm -f ./test_case
rm -f ./a.out

echo ""

echo "练习4-14.c:"
gcc 练习4-14.c
./a.out
rm -f ./a.out
