#include <iostream>
#include <cstring>
using namespace std;
const unsigned int SIZE = 9;
//const unsigned int STRING_SIZE = 51;


void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
  for (unsigned int i = 0; i < SIZE; i++) {
	ary[i] = 0;
  }
}

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
					if ((timeArray[j] <= min)) {
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


int main() {
   unsigned int rank[SIZE];
   /* double score[] = {
32.7,
36.5,
45.8,
52.34,
76.45,
33.4,
38,
50.1,
60.34
   }; */
    //double score[] = {26, 20, 66, 44, 24, 85, 39, 46, 34};
   //double score[] = {3, 3, 3};
   //double score[] = {85, 65, 37, 61, 74, 93, 28, 97, 84};
//double score[] = {56, 62, 27, 53, 63, 94, 50, 71, 31};
	double score[] = {22.38, 22.09, 87, 29, 44, 70, 26, 20, 53};
   prep_unsigned_int_array(rank);
   for (unsigned int i = 0; i < SIZE; i++) {
      cout << rank[i] << " ";
   }
   cout << endl;
   get_ranking(score, rank);
   for (unsigned int i = 0; i < SIZE; i++) {
      cout << rank[i] << " ";
   }
   cout << endl;
   if (22.38 > 22.09) {
	cout << "false";
   }
   else if (22.38 < 22.09) {
	cout << "true";
   }
   return 0;
}




