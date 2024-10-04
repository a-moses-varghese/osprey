#include <stdio.h>

int reverse(int x) {
  int res = 0;

  // get the values
  // int max = -1*((1 << 31) + 1);   // INT_MAX = 2147483647
  // int min = (1 << 31);      // INT_MIN = -2147483648
  
  // verify
  // printf("max -> %d \n", max);
  // printf("min -> %d \n", min);

  // hard code them
  int max = 2147483647;
  int min = -2147483648; 
  
  while (x != 0) {
    int digit = x % 10;
    x /= 10;

    if (res > max / 10 || (res == max / 10 && digit > 7)) {
      return 0;
    }
    if (res < min / 10 || (res == min / 10 && digit < -8)) {
      return 0;
    }
    res = res * 10 + digit;
  }
  return res;
}

int main() {
  printf("Hello, World!\n");

  int res = reverse(-65);

  printf("result: %d \n", res);

  return 0;
}
