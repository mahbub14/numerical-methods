#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x - 4; 
}

int main() {
    double x0 = 0, x1 = 3, x2;
    double tol = 1e-6;
    int max_iter = 100;

    cout << fixed << setprecision(6);

    for (int i = 1; i <= max_iter; i++) {
        if (f(x1) - f(x0) == 0) {
            cout << "Math Error: Division by zero\n";
            return -1;
        }

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        cout << "Iteration " << i << ": x = " << x2 << ", f(x) = " << f(x2) << endl;

        if (fabs(x2 - x1) < tol) {
            cout << "\nApproximate root: " << x2 << endl;
            break;
        }

        x0 = x1;
        x1 = x2;
    }

    return 0;
}
