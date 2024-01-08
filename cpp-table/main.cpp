#include <iostream>
using namespace std;

int main()
{
    // Declare variables with meaningful names
    int baseNumber, numberOfMultiples;

    // Prompt user for input
    cout << "Enter the number to generate the table: ";
    cin >> baseNumber;

    cout << "Enter the number of multiples to generate: ";
    cin >> numberOfMultiples;

    for (int i = 1; i <= numberOfMultiples; i++)
    {
        cout << baseNumber << " x " << i << " = " << (baseNumber * i) << endl;
    }

    return 0;
}
