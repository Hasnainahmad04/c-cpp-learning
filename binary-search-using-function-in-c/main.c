
#include <stdio.h>

int binarySerach(int array[], int sizeOfArray, int elementToFind) {

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

    int arr[5] = {10, 11, 33, 45, 57};

    int key = 33;

    int index = binarySerach(arr, n, key);
    if (index != -1)
        printf("Element Found at index %d", index);
    else
      printf("Element Not Found");

    return 0;
};

