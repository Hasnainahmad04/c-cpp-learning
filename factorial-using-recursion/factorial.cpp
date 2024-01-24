// Simple Factorial
#include <iostream>
using namespace std;

long fact(int n)
{
    // Base Step: if n reach 0 return 1
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);

    // using Ternary: return n == 0 ? 1 : n * fact(n-1);
}

int main()
{
    int n;
    cout << "Please Enter A Number: ";
    cin >> n;
    long result = fact(n);
    cout << "factorial of " << n << " is " << result;
    return 0;
}
