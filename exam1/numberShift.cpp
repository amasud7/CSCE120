#include <iostream>
using namespace std;

// function definition and declaration.

unsigned int number_shift(unsigned int num, int num_to_shift) {
    // holds last num in num
    int last;
    // if num to shift is zero
    if (num_to_shift == 0) {
        // return the num the was input
        return num;
    }
    // else if num to shift is positive
    else if (num_to_shift > 0) {
        // for loop to loop amount of times indicated by num to shift
        for (int i = 0; i < num_to_shift; i++) {
            // gets last number in num
            last = num % 10;
            // enters number at front of num
            num += last;
            // deletes last num
            num / 10;
        }
    }
    // else if num to shift is negative
    else if (num_to_shift < 0) {
        // for loop to loop amount of times indicated by num to shift uses abs to get abs value of neg num to shift
        for (int i = 0; i < abs(num_to_shift); i++) {  
            // gets first number 
            int first = num % 10000;
            // enter first number to back of num 
            num = num + first;
            // delete first number
            num / 10000;
        }
    }


    // return num after shifting
    return num;

}




