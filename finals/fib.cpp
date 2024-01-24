// Fibonacci Sequence
#include <iostream>
using namespace std;

long fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    cout << "Enter Term for Fibonacci Sequence" << endl;
    cin >> n;

    long result = fib(n);

    cout << "Fib Term at" << n << "is" << result;
}
