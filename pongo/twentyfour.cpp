#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const int RESULT = 24; 
const int COUNT = 4; 

int number[COUNT]; 

bool search(int count)
{
	int i = 0;
	int j = 0;
	if (count == 1) {
		if (number[0] == RESULT) {
			return true;
		} else {
			return false;
		}
	}	
	for (i = 0; i < count; i++) {
		for (j = i + 1; j < count; j++) {
			int a, b;
			a = number[i];
			b = number[j];
			
			number[j] = number[count - 1];

			number[i] = a + b;
			if (search(count - 1)) { 
				return true;
			}

			number[i] = a - b;
			if (search(count - 1)) { 
				return true;
			}


			number[i] = b - a;
			if (search(count - 1)) { 
				return true;
			}

			number[i] = a * b;
			if (search(count - 1)) { 
				return true;
			}
			
			if (b != 0) {
				number[i] = a / b;
				if (search(count - 1)) { 
					return true;
				}
			}

			if (a != 0) {
				number[i] = b / a;
				if (search(count - 1)) { 
					return true;
				}
			}
			number[i] = a;
			number[j] = b;
		}
	}
}

int can24(int a, int b, int c, int d)
{
	number[0] = a;
	number[1] = b;
	number[2] = c;
	number[3] = d;

	return search(COUNT);
}

int main()
{
	int tmp[4] = {0};	
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		number[i] = x;
	}
	if (search(4)) { 
 		cout << "Success." << endl; 
 	} else { 
 		cout << "Fail." << endl; 
 	}
}
