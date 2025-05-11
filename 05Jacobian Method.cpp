#include<bits/stdc++.h>
using namespace std;

// Define functions
double f(double x, double y) {
    return x*x + y*y - 1;
}

double g(double x, double y) {
    return y - x*x;
}

// Partial derivatives (Jacobian matrix)
void jacobian(double x, double y, double J[2][2]) {
    J[0][0] = 2*x;     // df/dx
    J[0][1] = 2*y;     // df/dy
    J[1][0] = -2*x;    // dg/dx
    J[1][1] = 1;       // dg/dy
}

// Inverse of 2x2 matrix
bool inverse2x2(double J[2][2], double invJ[2][2]) {
    double det = J[0][0]*J[1][1] - J[0][1]*J[1][0];
    if (fabs(det) < 1e-12) return false;  // Singular

    invJ[0][0] = J[1][1]/det;
    invJ[0][1] = -J[0][1]/det;
    invJ[1][0] = -J[1][0]/det;
    invJ[1][1] = J[0][0]/det;
    return true;
}

int main() {
    double x = 0.5, y = 0.5;
    double tol = 1e-6;
    int max_iter = 100;
    double F[2], J[2][2], invJ[2][2];

    for (int iter = 1; iter <= max_iter; ++iter) {
        F[0] = f(x, y);
        F[1] = g(x, y);

        if (sqrt(F[0]*F[0] + F[1]*F[1]) < tol) {
            cout << "Converged in " << iter << " iterations." << endl;
            break;
        }

        jacobian(x, y, J);
        if (!inverse2x2(J, invJ)) {
            cout << "Jacobian is singular!" << endl;
            return -1;
        }

        // Newton-Raphson update: x = x - J_inv * F
        double dx = -(invJ[0][0]*F[0] + invJ[0][1]*F[1]);
        double dy = -(invJ[1][0]*F[0] + invJ[1][1]*F[1]);
        x += dx;
        y += dy;
    }

    cout << fixed << setprecision(6);
    cout << "Solution: x = " << x << ", y = " << y << endl;

    return 0;
}
