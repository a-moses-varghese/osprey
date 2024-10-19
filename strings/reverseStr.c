#include <stdio.h>

void reverseString(char* s, int sSize) {
  unsigned short i;
  for (i=0; i<sSize; i++) {
    printf("%c", s[i]);
  }
  printf("\n");


  unsigned short fp, bp; // front, back ptr
  fp = 0;
  bp = sSize-1;

  char temp;
  while (fp < bp) {
    temp = s[fp];
    s[fp] = s[bp];
    s[bp] = temp;
    fp++;
    bp--;
  }

  for (i=0; i<sSize; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
}

int main() {
  printf("hello!\n");

  char s[] = "yaboi";
  int sSize = sizeof(s);

  reverseString(s, sSize);

  return 0;
}
