#include <iostream>
using namespace std;

int fact(int n)
{
    return n > 1 ? n * fact(n - 1) : 1;
}

int main()
{
    int n;
    cout << "Please Enter A Number: ";
    cin >> n;
    cout << "factorial of " << n << " is " << fact(n);
    return 0;
}