#include<bits/stdc++.h>
using namespace std;
//Newton-Raphson Method
// Define the function f(x) = x^3 - 2x - 5
double f(double x) {
    return x * x * x - 2 * x - 5;
}

// Define the derivative f'(x) = 3x^2 - 2
double df(double x) {
    return 3 * x * x - 2;
}

int main() {
    double x = 2;  // Initial guess
    int n = 30;    // Maximum number of iterations
    double e = 0.00002;  // Tolerance
    double x_new;

    cout << "Newton-Raphson Method:\n";
    for (int i = 1; i <= n; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (dfx == 0) {
            cout << "Derivative zero. Method fails.\n";
            return -1;
        }

        x_new = x - fx / dfx;

        cout << fixed << setprecision(6);
        cout << "Iteration " << i << ": x = " << x_new << ", f(x) = " << f(x_new) << endl;

        if (fabs(x_new - x) < e)
            break;

        x = x_new;
    }

    cout << "\nApproximate root: " << x_new << endl;
    return 0;
}
