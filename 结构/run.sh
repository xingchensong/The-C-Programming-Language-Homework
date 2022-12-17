echo "p139_tree.c:"
# 编译器自动整合不同c文件中的函数
gcc -I $PWD -I $PWD/../函数与结构程序 ./p139_tree.c ./utils/getword.c ./utils/tree.c ./../函数与结构程序/utils/getch.c -o a.out
cat <<EOT >> test_case
now is the time for all good men to come to the aid of their party
EOT
echo "./a.out < test_case"
./a.out < test_case
rm -f ./test_case
rm -f ./a.out

echo ""
echo "p144_hash.c:"
# 编译器自动整合不同c文件中的函数
gcc -I $PWD ./p144_hash.c ./utils/hash.c -o a.out
./a.out
rm -f ./a.out
