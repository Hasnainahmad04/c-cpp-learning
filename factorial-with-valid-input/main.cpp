// Factorial With Valid Input
#include <iostream>
using namespace std;

int fact(int n)
{
    // Base Step: if n reach 0 return 1
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int getInput()
{
    int num;
    char proceed;
    do
    {

        cout << "Please Enter A Positive Number: ";
        cin >> num;
        if (num < 0)
        {
            cout << "Invalid Input \n";
            cout << "Do you want to continue (y/n)?: ";
            cin >> proceed;
        }
    } while (num < 0 && (proceed == 'Y' || proceed == 'y'));
    return num;
}

int main()
{
    int n;
    n = getInput();
    long int result = fact(n);
    cout << "Factorial of " << n << " is " << result;

    return 0;
}
