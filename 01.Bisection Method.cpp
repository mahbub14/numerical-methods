#include<bits/stdc++.h>

using namespace std;
//Program : Bisection Method
double f(double x) {
    return x * x * x - x - 1; // f(x) = x³ - x - 1
}

int main() {
    double a = 1, b = 2, c,tol=1e-6;
    int n = 30;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: No roots between given brackets" << endl;
        return 0;
    }

    cout << fixed << setprecision(6);
    cout << "Iter\t a\t\t b\t\t c\t\t f(c)\n";

    for (int i = 1; i <= n; i++) {
        c = (a + b) / 2;
        double fc = f(c);

        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << fc << endl;

        if (fabs(fc) < tol)
            break;

        if (fc * f(a) < 0)
            b = c;
        else
            a = c;
    }

    cout << "\nApproximate Root = " << c << endl;

    return 0;
}
