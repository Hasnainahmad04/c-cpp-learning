// Linear Search using for loop in C++

#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    int array[n] = {10, 11, 33, 45, 57};
    int key = 11;

    int location = -1;

    for (int i = 0; i < n; i++)
    {

        if (key == array[i])
        {
            location = i;
            break;
        }
    }

    if (location != -1)
        cout << "Element Found at index " << location << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
