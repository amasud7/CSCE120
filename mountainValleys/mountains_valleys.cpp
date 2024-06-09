#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	int a = 0;
	int b = 0;
	bool pos = false;
	// TODO(student): print prompt for input
	// TODO(student): read the numbers from standard input
	// TODO(student): validate input (and reprompt on invalid input)
	do {
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a >> b;
		if ((a >= 0) && (b >= 0)) {
			pos = true;
		}
		// implement alternating digits??
		if (pos) {
			cout << "Invalid Input" << endl;
		}
	} while (!pos);

	// TODO(student): compute and display solution
	
	return 0;
}