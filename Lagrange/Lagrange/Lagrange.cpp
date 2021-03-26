#include <iostream>

using namespace std;

double lagrange_polynomial(double x, int i, double* x_arr, int size)
{
    double numerator = 1, denominator = 1;
    for (int j = 0; j < size; ++j)
    {
        if (i != j)
        {
            numerator *= x - x_arr[j];
            denominator *= x_arr[i] - x_arr[j];
        }
    }
    return numerator / denominator;
}

int main()
{
    int size;
    cout << "Size: ";
    cin >> size;   
    
    double* x_arr = new double[size];
    double* y_arr = new double[size];

    for (int i = 0; i < size; ++i)
    {
        cout << "x" << i << ": ";
        cin >> x_arr[i];
        cout << "y" << i << ": ";
        cin >> y_arr[i];
    }

    double x;
    cout << "X: ";
    cin >> x;

    double solution = 0;
    for (int i = 0; i < size; ++i)
    {
        solution += y_arr[i] * lagrange_polynomial(x, i, x_arr, size);        
    }

    cout << "Solution: " << solution;
}
