#include <iostream>

using namespace std;

void shrink_array(int numArr[64], int size) {
	int i = 0, j = 0;

	while (numArr[i] != 0 && i < size/2) { // sums and moves summerized numbers into their correct place
		numArr[i] = numArr[j] + numArr[j + 1];
		j += 2;
		i++;
	}
	i = 0;
	while (size - i >= size / 2) { // replaces whatever spaces that weren't used with 0
		numArr[size - i] = 0;
		i++;
	}
}

void main() {
	int num, size = 0;
	int numArr[64];
	cout << "Enter some numbers for an array, press 0 to stop:" << endl;

	while (true) {
		cin >> num;
		numArr[size] = num;
		size += 1;
		if (num == 0) {
			break;
		}
	}
	cout << endl;

	cout << "Input array: ";
	for (int i = 0; i < size-1; i++) {
		cout << numArr[i] << " ";
	}
	cout << endl;

	shrink_array(numArr, size);

	cout << "Output array: ";
	for (int i = 0; i < size-1; i++) {
		cout << numArr[i] << " ";
	}
}