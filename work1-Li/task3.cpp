#include <iostream>
#include <iomanip>
using namespace std;

inline double square(double x)
{
    return x * x;
}

double power(double base, int exponent = 2)
{
    double res = 1.0;
    for (int i = 0; i < exponent; i++)
    {
        res *= base;
    }
    return res;
}

double calc(double a, double b, char op)
{
    double ans = 0;
    if (op == '+') ans = a + b;
    else if (op == '-') ans = a - b;
    else if (op == '*') ans = a * b;
    else if (op == '/')
    {
        if (b == 0)
        {
            cout << "Error: divide by zero" << endl;
            return 0;
        }
        ans = a / b;
    }
    return ans;
}

double calc(int a, int b, char op)
{
    double ans = 0;
    if (op == '+') ans = a + b;
    else if (op == '-') ans = a - b;
    else if (op == '*') ans = a * b;
    else if (op == '/')
    {
        if (b == 0)
        {
            cout << "Error: divide by zero" << endl;
            return 0;
        }
        ans = (double)a / b;
    }
    return ans;
}

int main()
{
    double a, b;
    char op;
    cin >> a >> b >> op;
    cout << fixed << setprecision(2);

    cout << "square(a) = " << square(a) << endl;
    cout << "power(a) = " << power(a) << endl;
    cout << "power(a,3) = " << power(a,3) << endl;
    cout << "calc(a,b,op) = " << calc(a,b,op) << endl;
    return 0;
}

