#include <iostream>
using namespace std;

int main() {
   int ary[3] = {10, 100, 1000};
   int* hello;
   hello = ary;
   *hello = 7;
   cout << ary[0] << endl;
   cout << ary[1];
}