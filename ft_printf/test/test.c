#include "../src/ft_printf.h"

void printReturnedValue(int r1, int r2) {
  printf("returned: %d\n", r1);
  printf("returned: %d\n\n", r2);
}

int main() {
  int r1, r2;

  // ただの文字列の出力
  printf("string\n");
  r1 = ft_printf("Hello, World!\n");
  r2 = printf("Hello, World!\n");
  printReturnedValue(r1, r2);

  // %の出力
  printf("percent\n");
  r1 = ft_printf("%%\n");
  r2 = printf("%%\n");
  printReturnedValue(r1, r2);

  // %１つの出力
  // printf("single percent input\n");
  // r1 = ft_printf("%\n"); // TODO: エラーが出るべき
  // r2 = printf("%\n");
  // printReturnedValue(r1, r2);

  // charの出力
  printf("char\n");
  char c = 'a';
  r1 = ft_printf("%c\n", c);
  r2 = printf("%c\n", c);
  printReturnedValue(r1, r2);

  // stringの出力
  printf("char\n");
  char* s = "abcdefg";
  r1 = ft_printf("%s\n", s);
  r2 = printf("%s\n", s);
  printReturnedValue(r1, r2);

  // ポインタの出力
  printf("pointer\n");
  int value = 10;
  int* addr = &value;
  r1 = ft_printf("%p\n", addr);
  r2 = printf("%p\n", addr);
  printReturnedValue(r1, r2);

  // ヌルポインタの出力
  printf("null pointer\n");
  int* nullptr = NULL;
  r1 = ft_printf("%p\n", nullptr);
  r2 = printf("%p\n", nullptr);
  printReturnedValue(r1, r2);

  // 整数int(i)の出力
  printf("integer(i)\n");
  int integer = 0;
  r1 = ft_printf("%i\n", integer);
  r2 = printf("%i\n", integer);
  printReturnedValue(r1, r2);

  // 整数int(i)の最大値の出力
  printf("int max(i)\n");
  int intMax = INT_MAX;
  r1 = ft_printf("%i\n", intMax);
  r2 = printf("%i\n", intMax);
  printReturnedValue(r1, r2);

  // 整数int(i)の最小値の出力
  printf("int min(i)\n");
  int intMin = INT_MIN;
  r1 = ft_printf("%i\n", intMin);
  r2 = printf("%i\n", intMin);
  printReturnedValue(r1, r2);

  // 整数int(d)の出力
  printf("integer(d)\n");
  int decimal = 0;
  r1 = ft_printf("%d\n", decimal);
  r2 = printf("%d\n", decimal);
  printReturnedValue(r1, r2);

  // 整数int(d)の最大値の出力
  printf("int max(d)\n");
  int decimalMax = INT_MAX;
  r1 = ft_printf("%d\n", decimalMax);
  r2 = printf("%d\n", decimalMax);
  printReturnedValue(r1, r2);

  // 整数int(d)の最小値の出力
  printf("int min(d)\n");
  int decimalMin = INT_MIN;
  r1 = ft_printf("%d\n", decimalMin);
  r2 = printf("%d\n", decimalMin);
  printReturnedValue(r1, r2);

  // 符号なし整数の出力
  printf("unsigned int\n");
  unsigned int uint = 12345;
  r1 = ft_printf("%u\n", uint);
  r2 = printf("%u\n", uint);
  printReturnedValue(r1, r2);

  // 符号なし整数の最大値の出力
  printf("unsigned int max\n");
  unsigned int uintMax = UINT_MAX;
  r1 = ft_printf("%u\n", uintMax);
  r2 = printf("%u\n", uintMax);
  printReturnedValue(r1, r2);

  // 符号なし整数の最小値の出力
  printf("unsigned int\n");
  unsigned int uintMin = INT_MIN;
  r1 = ft_printf("%u\n", uintMin);
  r2 = printf("%u\n", uintMin);
  printReturnedValue(r1, r2);

  // 16進数(小文字)の出力1
  printf("lower hex 1\n");
  int lowerHex1 = 0;
  r1 = ft_printf("%x\n", lowerHex1);
  r2 = printf("%x\n", lowerHex1);
  printReturnedValue(r1, r2);

  // 16進数(小文字)の出力2
  printf("lower hex 2\n");
  int lowerHex2 = 16;
  r1 = ft_printf("%x\n", lowerHex2);
  r2 = printf("%x\n", lowerHex2);
  printReturnedValue(r1, r2);

  // 16進数(小文字)の出力3
  printf("lower hex 3\n");
  int lowerHex3 = INT_MAX;
  r1 = ft_printf("%x\n", lowerHex3);
  r2 = printf("%x\n", lowerHex3);
  printReturnedValue(r1, r2);

  // 16進数(小文字)の出力4
  printf("lower hex 4\n");
  int lowerHex4 = -12;
  r1 = ft_printf("%x\n", lowerHex4);
  r2 = printf("%x\n", lowerHex4);
  printReturnedValue(r1, r2);

   // 16進数(大文字)の出力1
  printf("upper hex 1\n");
  int upperHex1 = 0;
  r1 = ft_printf("%X\n", upperHex1);
  r2 = printf("%X\n", upperHex1);
  printReturnedValue(r1, r2);

  // 16進数(大文字)の出力2
  printf("upper hex 2\n");
  int upperHex2 = 16;
  r1 = ft_printf("%X\n", upperHex2);
  r2 = printf("%X\n", upperHex2);
  printReturnedValue(r1, r2);

  // 16進数(大文字)の出力3
  printf("upper hex 3\n");
  int upperHex3 = INT_MAX;
  r1 = ft_printf("%X\n", upperHex3);
  r2 = printf("%X\n", upperHex3);
  printReturnedValue(r1, r2);

  // 16進数(大文字)の出力4
  printf("upper hex 4\n");
  int upperHex4 = -100;
  r1 = ft_printf("%X\n", upperHex4);
  r2 = printf("%X\n", upperHex4);
  printReturnedValue(r1, r2);



  // printf("upper hex 5\n");
  // long upperHex5 = -100;
  // r1 = ft_printf("%X\n", upperHex5);
  // // r2 = printf("%X\n", upperHex5);
  // printReturnedValue(r1, r2);



  // 引数2つ
  // printf("multiple args%%\n");
  // r1 = ft_printf("%c\n%s\n", c, s); // Segmentation fault: 11
  // r2 = printf("%c\n%s\n", c, s);
  // printReturnedValue(r1, r2);

  // // 複数の引数
  // printf("multiple args%%\n");
  // r1 = ft_printf("%c\n%s\n%p\n%i\n%d\n%u\n%x\n%X\n", c, s, addr, integer, decimal, uint, lowerHex1, upperHex1); // Segmentation fault: 11
  // r2 = printf("%c\n%s\n%p\n%i\n%d\n%u\n%x\n%X\n", c, s, addr, integer, decimal, uint, lowerHex1, upperHex1);
  // printReturnedValue(r1, r2);

  return 0;
}
