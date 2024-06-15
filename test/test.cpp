#include <iostream>
using namespace std;
const unsigned int SIZE = 9;


int main() {
   double ary[SIZE] = {};
   // prep_double_array(ary);

   for (unsigned int i = 0 ; i < SIZE; i++) {
      cout << ary[i];
   }
   return 0;
}