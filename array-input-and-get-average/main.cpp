#include <iostream>
using namespace std;

void inputArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Please Enter Element for " << i + 1 << ": ";
        cin >> array[i];
    }
}

float avg(int array[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    };
    return sum / size;
}
int main()
{
    int size;
    cout << "Please Enter Size of Array: ";
    cin >> size;

    int array[size];
    inputArray(array, size);
    float average = avg(array, size);
    char x = 65;
    cout << x;
    cout << "Average is: " << average;
    return 0;
}
