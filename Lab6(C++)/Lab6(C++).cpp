#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

double sum_of_progression(double start, double end, double step, double sum);

int main() {
    double start, end, step, sum = 0;
    start = 3 * M_PI;
    end = -4 * M_PI;
    step = M_PI_2;
    sum = sum_of_progression(start, end, step, sum);
    cout << "Sum of progression: " << sum << endl;
    system("pause");
    return 0;
}

double sum_of_progression(double start, double end, double step, double sum) {
    if (start == end) {
        sum = end;
    }
    else {
        sum = start + sum_of_progression(start - step, end, step, sum);
    }
    return sum;
}