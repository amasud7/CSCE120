#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  for (unsigned int i = 0; i < SIZE; i++) {
	ary[i] = 0.0;
  }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
  for (unsigned int i = 0; i < SIZE; i++) {
	ary[i] = 0;
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	//TODO
	char copy[] = "N/A";
	for (unsigned int row = 0; row < SIZE; row++) {
		strcpy(ary[row], copy);
	}
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
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

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) {
  //TODO
  //validate data
	for (unsigned int i = 0; i < SIZE; i++) {
		cin >> timeArray[i] >> countryArray[i] >> numberArray[i] >> lastnameArray[i];

		if (timeArray[i] < 0) {
			return false;
		}

		if ((numberArray[i] > 99)) {
			return false;
		}

		int count = 0;
		for (size_t j = 0; j < strlen(countryArray[i]); j++) {
			count++;
			if ((!(isupper(countryArray[i][j]))) || (!(isalpha(countryArray[i][j])))) {
				return false;
			}
		}
		if (count != 3) {
			return false;
		}

		trim(lastnameArray[i]);
		if (strlen(lastnameArray[i]) > 1) {
			for (size_t k = 0; k < strlen(lastnameArray[i]); k++) {
				if ((!(isalpha(lastnameArray[i][k])))) {
					if ((!(isspace(lastnameArray[i][k])))) {
						return false;
					}
				}
			}
		}
		else {
			return false;
		}
	}
  return true; // set so it will compile
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[]) {
	//TODO
	double min;
	int place = 1;
	unsigned int j;
	int temp = 0;
	bool check = false;
	for (unsigned int c = 0; c < SIZE; c++) {
		for (unsigned int i = 0; i < SIZE; i++) {
			min = timeArray[i];
			for (j = 0; j < SIZE; j++) {
				if (rankArray[j] == 0) {
					if (timeArray[j] <= min) {
						min = timeArray[j];
						temp = j;
						check = true;
					}
				}
			}
			if (!check) {
				continue;
				//temp = i;
			}
			rankArray[temp] = place;
			// check duplicates
			for (unsigned int d = 0; d < SIZE; d++) {
				if (timeArray[d] == timeArray[temp]) {
					rankArray[d] = place;
				}
			}

			place++;
			check = false;

		}
	}
	for (unsigned int i = 0; i < SIZE; i++) {
		if (rankArray[i] == 0) {
			rankArray[i] = 9;
		}
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for (unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}