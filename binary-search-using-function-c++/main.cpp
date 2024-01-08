// Binary Search in C++

#include <iostream>
using namespace std;

int binarySerach(int array[], int sizeOfArray, int elementToFind)
{

    int low = 0;
    int high = sizeOfArray - 1;
    int index = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (elementToFind == array[mid])
        {
            index = mid;
            break;
        }

        if (elementToFind < array[mid])
            high = mid - 1;
        else
            low = mid + 1;
    };

    return index;
};

int main()
{
    int n = 5;

    int array[n] = {10, 11, 33, 45, 57};

    int key = 15;

    int index = binarySerach(array, n, key);
    if (index != -1)
        cout << "Element Found at location " << index << endl;
    else
        cout << key << " Not found in the array" << endl;

    return 0;
}
