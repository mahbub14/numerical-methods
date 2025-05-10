#include <iostream>
#include <cmath>

using namespace std;

// Define the functions f(x, y) and g(x, y)
double f(double x, double y) {
    return x * x + y * y - 1;  // Equation 1: x^2 + y^2 - 1 = 0
}

double g(double x, double y) {
    return y - x * x;  // Equation 2: y - x^2 = 0
}

// Define the Jacobian matrix J(x, y)
void jacobian(double x, double y, double J[2][2]) {
    J[0][0] = 2 * x;  // Partial derivative of f(x, y) with respect to x
    J[0][1] = 2 * y;  // Partial derivative of f(x, y) with respect to y
    J[1][0] = -2 * x; // Partial derivative of g(x, y) with respect to x
    J[1][1] = 1;      // Partial derivative of g(x, y) with respect to y
}

// Inverse of a 2x2 matrix
bool inverse(double J[2][2], double J_inv[2][2]) {
    double det = J[0][0] * J[1][1] - J[0][1] * J[1][0];
    if (det == 0) return false;  // If determinant is 0, the matrix is singular and cannot be inverted

    double invDet = 1.0 / det;
    J_inv[0][0] = J[1][1] * invDet;
    J_inv[0][1] = -J[0][1] * invDet;
    J_inv[1][0] = -J[1][0] * invDet;
    J_inv[1][1] = J[0][0] * invDet;

    return true;
}

// Main function
int main() {
    double x0[2] = {0.5, 0.5};  // Initial guess [x, y]
    double tol = 1e-6;          // Tolerance
    int max_iter = 100;         // Maximum iterations
    int iter;

    for (iter = 0; iter < max_iter; ++iter) {
        // Function vector F(x, y) = [f(x, y), g(x, y)]
        double F[2] = {f(x0[0], x0[1]), g(x0[0], x0[1])};

        // Check for convergence
        if (fabs(F[0]) < tol && fabs(F[1]) < tol) {
            cout << "Converged in " << iter + 1 << " iterations." << endl;
            break;
        }

        // Compute the Jacobian matrix
        double J[2][2];
        jacobian(x0[0], x0[1], J);

        // Compute the inverse of the Jacobian
        double J_inv[2][2];
        if (!inverse(J, J_inv)) {
            cout << "Jacobian matrix is singular, cannot proceed." << endl;
            break;
        }

        // Update the guess: x0 = x0 - J_inv * F
        double x_new[2];
        x_new[0] = x0[0] - (J_inv[0][0] * F[0] + J_inv[0][1] * F[1]);
        x_new[1] = x0[1] - (J_inv[1][0] * F[0] + J_inv[1][1] * F[1]);

        // Update x0 for the next iteration
        x0[0] = x_new[0];
        x0[1] = x_new[1];
    }

    // If the loop exits without converging, print the result
    if (iter == max_iter) {
        cout << "Maximum iterations reached without convergence." << endl;
    }

    // Final solution
    cout << "Solution: x = " << x0[0] << ", y = " << x0[1] << endl;

    return 0;
}
