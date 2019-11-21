#include <Iostream>

using namespace std;

bool is_sorted(int numArray[5]) {
	for (int i = 1; i < 5; i++) {
		if (numArray[i] < numArray[i - 1]) { // checks if number before in array is smaller
			return false;
		}
	}
	return true;
}

void main() {
	int num;
	int numArray[5];

	cout << "Type 5 numbers 1 by 1:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		numArray[i] = num;
	}

	if (is_sorted(numArray) == 1) {
		cout << "It is sorted." << endl;
	}
	else {
		cout << "It is not sorted." << endl;
	}
}

