#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

// Global memory & history
double memory = 0;
vector<string> history;

// Utility Functions
void addHistory(string entry) {
    history.push_back(entry);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

void fibonacci(int n) {
    int a = 0, b = 1, c;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n====== BTECH SCIENTIFIC CALCULATOR PROJECT ======\n";
        cout << "1. Basic Arithmetic\n";
        cout << "2. Scientific Functions\n";
        cout << "3. Memory Operations\n";
        cout << "4. Unit Conversions\n";
        cout << "5. Number Utilities\n";
        cout << "6. View Calculation History\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            double a, b;
            char op;
            cin >> a >> op >> b;
            double res;
            if (op == '+') res = a + b;
            else if (op == '-') res = a - b;
            else if (op == '*') res = a * b;
            else if (op == '/') res = b != 0 ? a / b : 0;
            else break;

            cout << "Result: " << res << endl;
            addHistory(to_string(a) + op + to_string(b) + "=" + to_string(res));
            break;
        }

        case 2: {
            int s;
            double x;
            cout << "1.Sin  2.Cos  3.Tan  4.Log  5.Sqrt\n";
            cin >> s >> x;
            double r;
            if (s == 1) r = sin(x * M_PI / 180);
            else if (s == 2) r = cos(x * M_PI / 180);
            else if (s == 3) r = tan(x * M_PI / 180);
            else if (s == 4) r = log10(x);
            else if (s == 5) r = sqrt(x);
            else break;

            cout << "Result: " << r << endl;
            addHistory("Scientific Result=" + to_string(r));
            break;
        }

        case 3: {
            int m;
            double v;
            cout << "1.M+  2.M-  3.MR  4.MC\n";
            cin >> m;
            if (m == 1) { cin >> v; memory += v; }
            else if (m == 2) { cin >> v; memory -= v; }
            else if (m == 3) cout << "Memory: " << memory << endl;
            else if (m == 4) memory = 0;
            break;
        }

        case 4: {
            int u;
            double val;
            cout << "1.Celsius to Fahrenheit\n";
            cout << "2.KM to Miles\n";
            cin >> u >> val;
            if (u == 1)
                cout << "Result: " << (val * 9 / 5) + 32 << endl;
            else if (u == 2)
                cout << "Result: " << val * 0.621371 << endl;
            break;
        }

        case 5: {
            int n;
            cout << "1.Prime Check  2.GCD & LCM  3.Fibonacci\n";
            cin >> choice;

            if (choice == 1) {
                cin >> n;
                cout << (isPrime(n) ? "Prime" : "Not Prime") << endl;
            }
            else if (choice == 2) {
                int a, b;
                cin >> a >> b;
                cout << "GCD: " << gcd(a, b) << endl;
                cout << "LCM: " << lcm(a, b) << endl;
            }
            else if (choice == 3) {
                cin >> n;
                fibonacci(n);
            }
            break;
        }

        case 6:
            cout << "\n---- Calculation History ----\n";
            for (auto &h : history)
                cout << h << endl;
            break;
        }

    } while (choice != 0);

    cout << "Project Closed Successfully.\n";
    return 0;
}

