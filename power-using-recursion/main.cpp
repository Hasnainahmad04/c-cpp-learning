#include <iostream>
using namespace std;

int pow(int a, int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return a * pow(a, n - 1);
  }
}

int main()
{
  int a = 3, n = 3;
  int result = pow(a, n);
  cout << "Result is: " << result;
  return 0;
}