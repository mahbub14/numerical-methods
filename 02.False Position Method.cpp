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
        double c;
        for (int i = 1; i <= n; ++i) {
            c = (a * f(b) - b * f(a)) / (f(b) - f(a));

            cout << fixed << setprecision(4);
            cout << "a" << i << " = " << a << "  "
                 << "b" << i << " = " << b << "  ";

            cout << fixed << setprecision(9);
            cout << "c" << i << " = " << c << endl;

            if (fabs(b - c) < e || fabs(a - c) < e)
                break;

            if (f(a) * f(c) < 0)
                b = c;
            else if (f(b) * f(c) < 0)
                a = c;
            else
                break;  // Exact root found
        }

        cout << "\nApproximate root is: " << c << endl;
    } else {
        cout << "No roots between given brackets" << endl;
    }

    return 0;
}
