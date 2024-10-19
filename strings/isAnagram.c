#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/*
 *
 * Notes:
 *
 * for s, make 1 pass and make a note of all the characters, and the number of their occurrences
 * for t, make 1 pass and yeah do the same thing as s 
 *
 * then, for 26, compare each character, if it does not match at any given time, return false
 * else return true
 *
 *
 * */
// speed 74%, memory 74%
bool isAnagram(char* s, char* t) {
  unsigned int occS[26] = {0};
  unsigned int occT[26] = {0};

  unsigned int size = strlen(s);
  if (size != strlen(t)) {
    return false;
  }

  for (int i=0; i<size; i++) {
    char c1 = s[i];
    char c2 = t[i];
    //printf("%c", c2);

    unsigned char cS = (unsigned char) s[i] - 97;
    unsigned char cT = (unsigned char) t[i] - 97;

    occS[cS]++;
    occT[cT]++;
  }

  
  for (int i=0; i<26; i++) {
    if (occS[i] != occT[i]) {
      return false;
    }
  }
  printf("\n");
  
  return true;
}

int main() {

  char s[] = "otatos";
  char t[] = "tomato";

  //char s[] = "anagram";
  //char t[] = "nagaram";
  bool res = isAnagram(s, t);

  printf("res: %b\n", res);

  return 0;
}

/*
 *
 Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

 * */
