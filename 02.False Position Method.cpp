#include <bits/stdc++.h>
using namespace std;

// Define the function f(x) = x^3 - 2x - 5
double f(double x) {
    return x * x * x - 2 * x - 5;
}

int main() {
    double a = 2, b = 3;
    int n = 30;  // Maximum iterations
    double e = 0.00002;  // Tolerance

    if (f(a) * f(b) < 0) {
        double x1;
        for (int i = 1; i <= n; ++i) {
            x1 = (a * f(b) - b * f(a)) / (f(b) - f(a));

            cout << fixed << setprecision(4);
            cout << "a" << i << " = " << a << "  "
                 << "b" << i << " = " << b << "  ";

            cout << fixed << setprecision(9);
            cout << "x1" << i << " = " << x1 << endl;

            if (fabs(b - x1) < e || fabs(a - x1) < e)
                break;

            if (f(a) * f(x1) < 0)
                b = x1;
            else if (f(b) * f(x1) < 0)
                a = x1;
            else
                break;  // Exact root found
        }

        cout << "\nApproximate root is: " << x1 << endl;
    } else {
        cout << "No roots between given brackets" << endl;
    }

    return 0;
}
