#include <iostream>
#include <iomanip>
using namespace std;

void output_array(char array[], int size);

int main() {
	int sum = 0;
	const int size = 10;
	char array_1[size], array_2[size], array_3[size];
	for (int i = 0; i < size; i++) {
		array_1[i] = 95 + i;
		array_2[i] = 105 - i;
		array_3[i] = 0;
	}
	cout << "array_1:" << endl;
	output_array(array_1, size);
	cout << "array_2:" << endl;
	output_array(array_2, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array_1[i] == array_2[j]) {
				array_3[i] = array_1[i];
			}
		}
	}
	cout << "array_3:" << endl;
	output_array(array_3, size);
	for (int i = 0; i < size; i++) {
		if (array_3[i] > 101) {
			sum += array_3[i];
		}
	}
	cout << "sum: " << sum << endl;
	system("pause");
	return 0;
}

void output_array(char array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(2) << array[i];
	}
	cout << endl << endl;
}