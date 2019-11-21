#include <lab2lib.h>
#include <iostream>

using namespace std;

int main() {
	char command;
	while (true) {
		cout << "Select a task to run:" << endl;
		for (int i = 1; i <= 6; i++) {
			cout << i << ". Task " << i << endl;;
		}
		cout << "0. Quit" << endl;
		
		cin >> command;

		switch (command) {

		case '1':
			cout << endl;
			task1();
			cout << endl;
			break;
		case '2':
			cout << endl;
			task2();
			cout << endl;
			break;
		case '3':
			cout << endl;
			task3();
			cout << endl;
			break;
		case '4':
			cout << endl;
			task4();
			cout << endl;
			break;
		case '5':
			cout << endl;
			task5();
			cout << endl;
			break;
		case '6':
			cout << endl;
			task6();
			cout << endl;
			break;
		case '0':
			return 0;
		default:
			cout << "There is no such task!" << endl;
			break;
		}
	}
}