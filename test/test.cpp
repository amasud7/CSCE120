#include <iostream>
using namespace std;

int main() {
   int size = 0;
   int number = 12345;
   while (number != 0) {
      number /= 10;
      size++;
   }
   cout <<  size;
   return 0;
}