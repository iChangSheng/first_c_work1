#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap(double &x, double &y)
{
    double temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "交换前：a = " << a << ", b = " << b << endl;
    swap(a,b);
    cout << "交换后：a = " << a << ", b = " << b << endl;

    double m, n;
    cin >> m >> n;
    cout << "交换前：m = " << m << ", n = " << n << endl;
    swap(m,n);
    cout << "交换后：m = " << m << ", n = " << n << endl;
    return 0;
}

