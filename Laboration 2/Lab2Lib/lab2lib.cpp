#include <Iostream>
#include <Cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "lab2lib.h"

using namespace std;

bool is_sorted(int numArray[5]) {
	for (int i = 1; i < 5; i++) {
		if (numArray[i] < numArray[i - 1]) { // checks if number before in array is smaller
			return false;
		}
	}
	return true;
}

void task1() {
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

bool is_palindrome(char letterArray[64], int size) {
	int i = 0;

	for (int i = 0; i < size; i++) {
		if (letterArray[i] != letterArray[size - 1 - i]) { // walks from first and last to last and first checking if letters are the same
			return false;
		}
	}
	return true;
}

void task2() {
	string word;
	char letterArray[64];
	cout << "Enter a word to check if it's a palindrome:" << endl;
	cin >> word;
	int size = distance(begin(word), end(word)); // checks size of word

	for (int i = 0; i <= size; i++) { // puts word into a char array
		letterArray[i] = word[i];
	}

	if (is_palindrome(letterArray, size) == 1) {
		cout << "It is a palindrome." << endl;
	}
	else {
		cout << "It is not a palindrome." << endl;
	}
}

void arr_cols_rows(int matrix[256][256], int cols, int rows) {
	int rowSum = 0;
	int colSum = 0;
	int totColSum = 0;
	int totRowSum = 0;

	//sums up the rows
	for (int i = 0; i < rows; i++) {
		rowSum = 0;
		for (int j = 0; j <= cols; j++) {
			rowSum += matrix[i][j];
		}
		matrix[i][cols] = rowSum;
		totRowSum += rowSum;
	}

	//sums up the columns
	for (int j = 0; j < cols; j++) {
		colSum = 0;
		for (int i = 0; i <= rows; i++) {
			colSum += matrix[i][j];
		}
		matrix[rows][j] = colSum;
		totColSum += colSum;
	}
	matrix[rows][cols] = totColSum + totRowSum;
	//prints the matrix out.
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

void task3() {
	int columns;
	int rows;
	int matrix[256][256];
	srand((unsigned)time(0));
	cout << "How many columns do you want? :" << endl;
	cin >> columns;
	cout << "How many rows do you want? :" << endl;
	cin >> rows;
	cout << "\n";

	for (int i = 0; i <= columns; i++) {
		for (int j = 0; j <= rows; j++) {
			matrix[j][i] = rand() % 10;
		}
	}
	for (int j = 0; j <= columns; j++) {
		for (int i = 0; i <= rows; i++) {
			matrix[j][i] = rand() % 10;
		}
	}

	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= columns; j++) {
			matrix[rows][j] = 0;
		}

	}
	for (int j = 0; j <= rows; j++) {
		for (int i = 0; i <= columns; i++) {
			matrix[j][columns] = 0;
		}

	}

	arr_cols_rows(matrix, columns, rows);

}

void sort_swap(int& a, int& b, int& c, bool order) {
	int temp;

	if (order == false) { // sorts descending order
		temp = a;
		if (a < b && b > c) {
			temp = a;
			a = b;
			b = temp;
		}
		else if (a < c) {
			temp = a;
			a = c;
			c = temp;
		}
		if (b < c) {
			temp = b;
			b = c;
			c = temp;
		}
	}

	else { // sorts ascending order
		if (a > b&& b < c) {
			temp = a;
			a = b;
			b = temp;
		}
		else if (a > c) {
			temp = a;
			a = c;
			c = temp;
		}
		if (b > c) {
			temp = b;
			b = c;
			c = temp;
		}
	}
}

void task4() {
	int a, b, c;
	bool order;
	while (true) {
		cout << "Enter 3 numbers:" << endl;
		cout << "press 0 to quit" << endl;
		cin >> a;
		if (a == 0) {
			break;
		}
		cin >> b;
		cin >> c;

		cout << endl << "press 1 to sort in ascending order or 0 for descending:" << endl;
		cout << endl;
		cin >> order;
		cout << endl;

		sort_swap(a, b, c, order);
		cout << a << " " << b << " " << c << endl;
		cout << endl;
	}
}

#include <iostream>

using namespace std;

void shrink_array(int numArr[64], int size) {
	int i = 0, j = 0;

	while (numArr[i] != 0 && i < size / 2) { // sums and moves summerized numbers into their correct place
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

void task5() {
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
	for (int i = 0; i < size - 1; i++) {
		cout << numArr[i] << " ";
	}
	cout << endl;

	shrink_array(numArr, size);

	cout << "Output array: ";
	for (int i = 0; i < size - 1; i++) {
		cout << numArr[i] << " ";
	}
}


void task6() {
	int flag = 1;
	string command;
	string names;
	vector<string> database;

	while (true) {
		cout << "Enter a command:" << endl << "1. initialise database" << endl << "2. insert" << endl << "3. search" << endl << "4. delete" << endl << "5. print" << endl << "6. quit" << endl << endl;
		cin >> command;
		cout << endl;

		if (command == "initialise database" || command == "init" || command == "1") {
			cout << "Are you sure? This will empty the database. Press y to confirm." << endl;
			cin >> command;
			cout << endl;
			if (command == "y" || command == "Y") {
				database.clear();
				cout << "Database has been cleared!" << endl;

			}
		}

		if (command == "insert" || command == "2") {
			cout << "Add some names to the database, press q to stop:" << endl;
			while (true) {
				cin >> command;
				if (command == "q" || command == "Q") {
					break;
				}
				database.push_back(command);
			}
			cout << endl;
		}

		if (command == "search" || command == "3") {
			cout << endl << "Enter something to search for:" << endl;
			cin >> command;
			cout << endl;
			for (int i = 0; i < database.size(); i++) {
				if (database[i].find(command) != string::npos) {
					cout << database[i] << endl;
				}
			}
			cout << endl;
		}

		if (command == "delete" || command == "4") {
			cout << "Enter a name to delete, press q to stop:" << endl;
			while (true) {
				flag = 1;
				cin >> command;
				cout << endl;
				for (int i = 0; i < database.size(); i++) {
					if (command == database[i]) {
						database.erase(database.begin() + i);
						cout << "Name removed!" << endl;
						flag = 0;
					}
				}

				if (command == "q" || command == "Q") {
					break;
				}
				else if (flag == 1) {
					cout << "That name was not found." << endl;

				}
			}
		}

		if (command == "print" || command == "5") {
			for (auto i : database) {
				cout << i << " " << endl;
			}
			cout << endl;
		}

		if (command == "quit" || command == "6") {
			cout << "Exiting program...";
			break;
		}
	}
}