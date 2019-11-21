#include <Iostream>

using namespace std;

bool is_palindrome(char letterArray[64],int size) {
	int i = 0;
	char temp;

	for (int i = 0; i < size; i++) {
		if (letterArray[i] != letterArray[size-1-i]) { // walks from first and last to last and first checking if letters are the same
			return false;
		}
	}
	return true;
}

void main() {
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