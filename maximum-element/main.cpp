// MAximum Number In C++

#include <iostream>
using namespace std;

int main()
{
    // Define the size of the array
    int n = 5;
    int array[n] = {10, 11, 33, 45, 57};

    int max = array[0];

    for (int i = 0; i < n; i++)
        if (array[i] > max)
            max = array[i];
    cout << max;
    return 0;
}
