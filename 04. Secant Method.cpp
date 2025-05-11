#include<bits/stdc++.h>

using namespace std;

double f(double x) { return -1; }

int main() {
    double x0 = 0, x1 = 1, x2, tol = 1e-5;
    if (f(x0) == f(x1)) {
        cout << "Division by zero in Secant Method (constant function)" << endl;
        return 1;
    }
    while (fabs(f(x1)) > tol) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }
    cout << "Root = " << x1 << endl;
    return 0;
}
