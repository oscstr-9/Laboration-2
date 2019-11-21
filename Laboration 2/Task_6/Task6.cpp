#include <iostream>
#include <vector>
#include <string>
using namespace std;

void main() {
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
			if (command == "y" || command  == "Y") {
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