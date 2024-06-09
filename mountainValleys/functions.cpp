#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if ((a >= 10) && (a <= b) && (b < 10000)) {
		return true;
	}
	return false;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	int temp = 0;
	int dout = 0;
	int size = 0;
	int comp = 0;
	int secondDig = 0 ;
	bool alt = true;
	bool alt1 = true;

	while (number != 0) {
		dout = number % 10;
		number /= 10;
		size++;
		
		// only for first iteration 
		if (size == 1) {
			temp = dout;
			continue;
		}

		if ((dout > temp) && alt) {
			comp++;
			alt = false;
			alt1 = true;
		}
		else if ((dout < temp) && alt1) {
			comp++;
			alt1 = false;
			alt = true;
		}

		secondDig = temp;
		temp = dout;
	}

	// check whether M, V, or N
	if ((size - 1) == comp) {
		if (dout > secondDig) {
			return 'V';
		}
		else if (dout < secondDig) {
			return 'M';
		}
		else {
			return 'N';
		}
	}
	else {
		return 'N';
	}

}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	char check;
	int mcount = 0;
	int vcount = 0;
	for (int i = a; i <= b; i++) {
		check = classify_mv_range_type(i);
		if (check == 'M') {
			mcount++;
		}
		else if (check == 'V') {
			vcount++;
		}
	}
	cout << "There are " << mcount << " mountain ranges and " << vcount << " valley ranges between " << a << " and " << b << "." << endl;
}