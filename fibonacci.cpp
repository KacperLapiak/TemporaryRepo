#include <iostream>

using namespace std;

void fibonacci(int x)
{
    int a = 0;
    int b = 1;

    for (int i = 0; i < x; i++)
    {
        b += a;
        cout << b << " ";
        a = b - a;
    }
}
void fibonacciRec(int x, int a=0, int b=1)
{
    b += a;
    cout << b << " ";
    a = b - a;

    x--;
    if (x == 0) return;
    fibonacciRec(x, a, b);
}

int main()
{
    fibonacci(10);
    cout << endl;
    fibonacciRec(10);

    cin.get();
}