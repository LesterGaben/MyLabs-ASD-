#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void output_matrix(int matrix[6][4]);
void output_array(int array[6]);

int main() {
	srand(time(NULL));
	int matrix[6][4];
	int array[6];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
	output_matrix(matrix);
	int max_in_line;
	for (int i = 0; i < 6; i++) {
		max_in_line = 0;
		for (int j = 0; j < 4; j++) {
			if (max_in_line < matrix[i][j]) {
				max_in_line = matrix[i][j];
			}
		}
		array[i] = max_in_line;
	}
	cout << "array: " << endl;
	output_array(array);
	int temp, j;
	for (int i = 1; i < 6; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] < temp) {
			array[j + 1] = array[j];
			array[j] = temp;
			j--;
		}
	}
	cout << "newArray: " << endl;
	output_array(array);
	system("pause");
	return 0;
}

void output_matrix(int matrix[6][4]) {
	cout << "matrix: " << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
}

void output_array(int array[6]) {
	for (int i = 0; i < 6; i++) {
		cout << array[i] << "\t";
	}
	cout << "\n\n";
}