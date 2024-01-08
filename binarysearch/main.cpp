// Binary Search in C++

#include <iostream>
using namespace std;

int main()
{
  int n = 5;

  int array[n] = {10, 11, 33, 45, 57};

  int key = 11;

  int low = 0;
  int high = n - 1;
  int location = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (key == array[mid])
    {
      location = mid;
      break;
    }

    if (key < array[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  if (location != -1)
    cout << "Element Found at location " << location + 1 << endl;
  else
    cout << "Element not found" << endl;

  return 0;
}
