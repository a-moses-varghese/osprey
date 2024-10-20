#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
 *
 * Notes:
 *
 * ignore whitespaces
 * determine sign if the next char is '-' or '+' (I assume  () ())
 *
 *
 * if curr character is non-number, stop reading
 *
 * 0 -> 48
 * 0 -> 57
 * - -> 45
 * + -> 43
 *
 * if char is 43 or 45 -> save sign
 * ignore leading zero after sign
 *
 * if range is not in 48-57
 * stop reading
 *
 * unknown -> how to convert from char to int (yay)
 *
 * if number is 4 digits (1337)
 *
 * 10 ** 3
 *
 * handle case of negative, non-digits, overflow
 *
 // * */
int myAtoi(char* s) {
  int res = 0;

  int sign = 1;
  int i = 0;

  while (s[i] == ' ') {
    i++;
  }

  if (s[i] == '-' || s[i] == '+') {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }

  for (; s[i] != '\0'; i++) {
    if (s[i] < '0' || s[i] > '9') {
      break;
    }

    if (res > (INT_MAX - (s[i] - '0')) / 10) {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }

    res = res * 10 + (s[i] - '0');
  }

  res *= sign;

  return res;
}

int exampleAtoi(char* s) {
  // 1. handle negatives
  // 2. handle non-digits
  // 3. handle overflow
  char expl[] = "748293";
  int length = strlen(expl); // 4
  printf("char string: ");
  for (int i=0; i<length; i++) {
    printf("%c", expl[i]);
  }
  printf("\n");

  int res = 0;
  int currIndex = expl[length-1] - '0';
  res += currIndex;

  int tenInd = 1;
  for (int i=0; i<length-1; i++) {
    tenInd *= 10;
  }

  for (int i=0; i<length-1; i++) {
    currIndex = expl[i] - '0';
    currIndex *= tenInd;
    res += currIndex;
    tenInd /= 10;
  }
  // printf("%d \n", tenInd);
  printf("res integer: %d \n", res);


  return 0;
}

int exampleAtoi2(char* s) {
  char expl[] = "-748293";
  int length = strlen(expl); // 4
  for (int i=0; i<length; i++) {
    printf("%c", expl[i]);
  }
  printf("\n");

  return 0;
}

int main() {
  //printf("Hello, World!\n");

  // char s[] = "words and 987";
  char s[] = "2864";
  int res = myAtoi(s);
  printf("result: %d \n", res);

  // exampleAtoi(s);

  // exampleAtoi2(s);

  return 0;
}

/*
 Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
    Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
    Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

Return the integer as the final result.



Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^

Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^

Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^

Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^

Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.



Constraints:

    0 <= s.length <= 200
    s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.


 * */
