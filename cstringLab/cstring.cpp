#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  int count  = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    count++;
  }
  
  return count;
}

unsigned int find(char str[], char character) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == character) {
      return i;
    }
    else {
      count++;
    }
  }
  return count;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  int len = 0;
  if (length(str1) > length(str2)) {
    len = length(str1);
  }
  else {
    len = length(str2);
  }

  for (int i = 0; i < len; i++) {
    if (str1[i] == str2[i]) {
      continue;
    }
    else {
      return false;
    }
  }
  return true;
}