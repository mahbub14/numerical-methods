#include <bits/stdc++.h>
using namespace std;

// Define dy/dt = y - t
double f(double y, double t) {
    return y - t;
}

int main() {
    double t0 = 0;
    double y0 = 2;
    double h = 0.1;
    double tn = 8;
    int n = (int)((tn - t0) / h);

    vector<double> t(n + 1);
    vector<double> y(n + 1);

    t[0] = t0;
    y[0] = y0;

    cout << fixed << setprecision(4);

    for (int i = 0; i < n; ++i) {
        double k1 = h * f(y[i], t[i]);
        double k2 = h * f(y[i] + 0.5 * k1, t[i] + 0.5 * h);
        double k3 = h * f(y[i] + 0.5 * k2, t[i] + 0.5 * h);
        double k4 = h * f(y[i] + k3, t[i] + h);

        y[i + 1] = y[i] + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        t[i + 1] = t[i] + h;

        cout << "y(" << t[i + 1] << ") = " << y[i + 1] << endl;
    }

    return 0;
}
