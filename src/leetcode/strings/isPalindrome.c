#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 *
 * Notes:
 *
 * strip all characters from the string
 * strip all spaces from the string
 * convert all characters to lowercase
 *
 * if char is not in range of 65-90, 97-122
 * -> remove it
 *
 * (data cleaning)
 * in other words
 * if char is in range 65-90, 97-122
 * -> add to final list
 *
 *  if char is in range 65-90, convert to lower case 
 *  
 *
 *  then use 2 pointers,
 *  fp, bp
 *
 *  check finalS[fp] == finalS[bp]
 *  loop while fp < bp
 *
 * */
bool isPalindrome(char* s) {
  unsigned int size = strlen(s);
  unsigned int checkS[210] = {0};
  unsigned int index = 0;

  for (unsigned int i=0; i<size; i++) {
    unsigned char c = (unsigned char) s[i];
    printf("%d \n", c);

    if (c >= 65 && c <= 122) {
      if (c >= 97 && c <= 122) {
        checkS[index] = c;
      }
      if (c >= 65 && c <= 90) {
        checkS[index] = c+32;
      }
      index++;
    }
  }
  printf("\n");

  if (index == 0) {
    // return true;
  }

  unsigned int fp = 0;
  unsigned int bp = index-1;
  while (fp < bp) {
    if (checkS[fp] != checkS[bp]) {
      return false;
    }
    fp++;
    bp--;
  }
  for (int fp=0; fp<index; fp++) {
    //printf("%c \n", checkS[i]);
  }
 
  return true;
}


int main() {

  //char s[] = "A man, a plan, a canal: Panama";
  //char s[] = " ";
  char s[] = "0P";

  bool res = isPalindrome(s);
  printf("res: %d\n", res);

  printf("\n");

  // a -> 97
  // z -> 122
  // A -> 65
  // Z -> 90
  // range -> 65-90, 97-122

  return 0;
}

/*
 *
 *A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

 

Constraints:

    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.


 * */
