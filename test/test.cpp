#include <iostream>
#include <cstring>
using namespace std;
// const unsigned int SIZE = 9;
const unsigned int STRING_SIZE = 51;

void trim(char str[STRING_SIZE]) {
	// TODO
   // find first character
   int i = 0;
   while ((str[i] == ' ') || (str[i] == '\t')) {
      i++;
   }

   // find last character
   int j = strlen(str) - 1;
   while ((str[j] == ' ') || (str[j] == '\t')) {
      j--;
   }

   // create new string
   int x;
   for (x = 0; i < j+1; x++) {
      str[x] = str[i];
      i++;
   }

   str[x] = '\0';

}

int main() {
   char str[] = " a ayad a ";
   trim(str);
   cout << str;
   return 0;
}




/*
bool check = false;
   int index = strlen(str);
   // getting rear of string
   int j = strlen(str) - 1;
   if ((str[(strlen(str) - 1)] == ' ') || (str[(strlen(str) - 1)] == '\t')) {
      while ((str[j] == ' ') || (str[(strlen(str) - 1)] == '\t')) {
         j--;
      }
      str[j - 1] = '\0';
      check = true;
   }

	// find first index
   if (str[0] == ' ') {
      int i = 0;
      while ((str[i] == ' ') || (str[i] == '\t')) {
         i++;
      }

      if (!check) {
         index = j + 1;
      }
      
      // shift string
      for (int x = 0; x < index; x++) {
         str[x] = str[i];
         i++;
      }
   }
*/