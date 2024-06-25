#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
using namespace std;




    



int main() {
	int a = 1;
	int b = 10;
	int count1 = 0;
	int count2 = 0;
	int cl = 0;
	int value = 0;
	try {
		for (int n = a; n <= b; n++) {
    		if (value >= 0 && n > 0 && n > INT32_MAX - value) {
				count1++;
				throw std::overflow_error("");
			}
			else if (value <= 0 && n < 0 && n < INT32_MIN - value) {
				count2++;
				throw std::overflow_error("");
			}
    		else {
      			value = value + n;
   			 }
			 cl++;
			 cout << value << endl;
  		}
		cout << value << endl;
	}
	catch(...) {
		cout << "error" << endl;
		cout << count1 << endl;
		cout << count2 << endl;
		cout << cl;
	}

	
    return 1;
}




