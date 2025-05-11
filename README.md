"# Numerical Methods in C++" 
"# numerical-methনিশ্চিত! নিচে গুরুত্বপূর্ণ সকল **Numerical Methods**–এর **Algorithm (বাংলায়)** এবং **C++ Code** একসাথে সাজিয়ে দেওয়া হলো। এতে আছে—

---

## 🔢 Root-Finding Methods

---

### 1️⃣ **Bisection Method**

**Algorithm (বাংলায়)**:

1. দুটি প্রাথমিক মান $a$ এবং $b$ নিতে হবে যেন $f(a) \cdot f(b) < 0$ হয়।
2. মাঝখানের মান $c = \frac{a + b}{2}$ হিসাব করো।
3. যদি $f(c) == 0$, তাহলে $c$ হল root।
4. যদি $f(c) \cdot f(a) < 0$, তাহলে $b = c$; অন্যথায় $a = c$।
5. নির্দিষ্ট iteration বা tolerance অনুযায়ী পুনরাবৃত্তি করো।

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;
double f(double x) {
    return x*x - 4;
}
int main() {
    double a = 0, b = 3, c, tol = 1e-3;
    int n = 20;
    if (f(a) * f(b) >= 0) {
        cout << "No Root between given bracket\n";
        return -1;
    }
    for (int i = 1; i <= n; i++) {
        c = (a + b) / 2.0;
        if (abs(f(c)) < tol) break;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        cout << "Iteration " << i << ": c = " << c << ", f(c) = " << f(c) << endl;
    }
    cout << "\nApproximate root: " << c << endl;
}
```

---

### 2️⃣ **False Position (Regula-Falsi) Method**

**Algorithm (বাংলায়)**:

1. $a$ ও $b$ নির্বাচন করো, যেন $f(a) \cdot f(b) < 0$।
2. $c = \frac{a f(b) - b f(a)}{f(b) - f(a)}$
3. যদি $f(c) == 0$, তাহলে $c$ root।
4. যদি $f(c) \cdot f(a) < 0$, তাহলে $b = c$; অন্যথায় $a = c$।
5. নির্দিষ্ট iteration বা tolerance অনুযায়ী পুনরাবৃত্তি করো।

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;
double f(double x) {
    return x*x - 4;
}
int main() {
    double a = 0, b = 3, c, tol = 1e-3;
    int n = 20;
    if (f(a) * f(b) >= 0) {
        cout << "No Root between given bracket\n";
        return -1;
    }
    for (int i = 1; i <= n; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (abs(f(c)) < tol) break;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        cout << "Iteration " << i << ": c = " << c << ", f(c) = " << f(c) << endl;
    }
    cout << "\nApproximate root: " << c << endl;
}
```

---

### 3️⃣ **Newton-Raphson Method**

**Algorithm (বাংলায়)**:

1. একটি প্রাথমিক অনুমান $x_0$ নাও।
2. $x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$
3. যতক্ষণ না পর্যন্ত $|x_{n+1} - x_n| < tol$, ততক্ষণ চালিয়ে যাও।

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;
double f(double x) {
    return x*x - 4;
}
double df(double x) {
    return 2*x;
}
int main() {
    double x = 3, tol = 1e-6;
    int n = 20;
    for (int i = 1; i <= n; i++) {
        double fx = f(x);
        double dfx = df(x);
        double x1 = x - fx / dfx;
        cout << "Iteration " << i << ": x = " << x1 << ", f(x) = " << f(x1) << endl;
        if (abs(x1 - x) < tol) break;
        x = x1;
    }
    cout << "\nApproximate root: " << x << endl;
}
```

---

### 4️⃣ **Secant Method**

**Algorithm (বাংলায়)**:

1. দুটি প্রাথমিক মান $x_0, x_1$ নাও।
2. $x_{n+1} = x_n - f(x_n) \cdot \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}$
3. যতক্ষণ না $|x_{n+1} - x_n| < tol$, ততক্ষণ চালাও।

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;
double f(double x) {
    return x*x - 4;
}
int main() {
    double x0 = 0, x1 = 3, x2, tol = 1e-6;
    int n = 20;
    for (int i = 1; i <= n; i++) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        cout << "Iteration " << i << ": x = " << x2 << ", f(x) = " << f(x2) << endl;
        if (abs(x2 - x1) < tol) break;
        x0 = x1;
        x1 = x2;
    }
    cout << "\nApproximate root: " << x2 << endl;
}
```

---

## 🧮 ODE Solving Methods

---

### 5️⃣ **Runge-Kutta 2nd Order (RK2)**

```cpp
#include <bits/stdc++.h>
using namespace std;
double f(double x, double y) {
    return x + y;
}
int main() {
    double x = 0, y = 1, h = 0.1;
    int n = 10;
    cout << "x\ty\n" << x << "\t" << y << endl;
    for (int i = 0; i < n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y += 0.5 * (k1 + k2);
        x += h;
        cout << x << "\t" << y << endl;
    }
}
```

---

### 6️⃣ **Runge-Kutta 4th Order (RK4)**

```cpp
#include <bits/stdc++.h>
using namespace std;
double f(double x, double y) {
    return x + y;
}
int main() {
    double x = 0, y = 1, h = 0.1;
    int n = 10;
    cout << "x\ty\n" << x << "\t" << y << endl;
    for (int i = 0; i < n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x += h;
        cout << x << "\t" << y << endl;
    }
}
```

---



