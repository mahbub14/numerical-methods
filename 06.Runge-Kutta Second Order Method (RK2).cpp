#include <bits/stdc++.h>
using namespace std;

// Function dy/dx = y - x
double f(double y, double x) {
    return y - x;
}

int main() {
    double x0 = 0;
    double y0 = 2;
    double h = 0.1;
    double xn = 0.4;
    int n = (int)((xn - x0) / h);

    double x = x0;
    double y = y0;

    cout << fixed << setprecision(5);

    for (int i = 1; i <= n; ++i) {
        double k1 = h * f(y, x);
        double k2 = h * f(y + h, x + k1);

        y = y + 0.5 * (k1 + k2);
        x = x0 + i * h;

        cout << "y(" << x << ") = " << y << endl;
    }

    return 0;
}
