#include <iostream>
#include <cstring>
# include <string>
using namespace std;



int SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
	double a;
    double b;
	if (A_correct > A_total) {
		return 5;
	}
	else if (B_correct > B_total) {
		return 6;
	}
	else {
		a = (A_correct / double(A_total)) * 100;
    	b = (B_correct / double(B_total)) * 100;
    	return 100;
	}

	
    
}


int main() {
   cout << SmarterSection(101, 100, 75, 100);
   return 1;
}




