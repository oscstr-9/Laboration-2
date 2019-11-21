#include <Iostream>
#include <Cstdlib>
#include <ctime>

using namespace std;

void arr_cols_rows(int matrix[256][256], int cols, int rows) {
	int colEqulizer = 0;
	int rowEqulizer = 0;
	int rowSum = 0;
	int colSum = 0;
	int totSum = 0;
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

void main() {
	int columns;
	int rows;
	int matrix[256][256];
	srand((unsigned)time(0));
	cout << "How many columns do you want? :" << endl;
	cin >> columns;
	cout << "How many rows do you want? :" << endl;
	cin >> rows;
	cout << "\n";

	// creates the matrix
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
	// sets edges to zero so they can be set to the correct sums later
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