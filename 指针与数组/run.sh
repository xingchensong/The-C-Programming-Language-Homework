echo "p92_sort.c:"
# 编译器自动整合不同c文件中的函数
gcc -I $PWD ./p92_sort.c ./utils/io.c ./utils/qsort.c -o a.out
cat <<EOT >> test_case
1.1
2
3.3
3.1
2.1
1.9
1000.2
100.02
EOT
echo "./a.out < test_case"
./a.out < test_case
echo "./a.out -n < test_case"
./a.out -n < test_case
rm -f ./test_case
rm -f ./a.out

echo ""
echo "p106_dcl.c:"
# 编译器自动整合不同c文件中的函数
gcc -I $PWD/../函数与结构程序 ./p106_dcl.c ./../函数与结构程序/utils/getch.c -o a.out
cat <<EOT >> test_case
int (*daytab)[13]
char **argv
int *daytab[13]
void *comp()
void (*comp)()
char (*(*x())[])()
char (*(*x[3])())[5]
EOT
echo "======="
cat test_case
echo "======="
./a.out < test_case
rm -f ./test_case
rm -f ./a.out

