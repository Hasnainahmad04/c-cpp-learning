#include <iostream>
using namespace std;

int power(int num, int pow)
{
  if (num == 0)
  {
    return 1;
  }

  return num * power(num, pow - 1);
}

int main()
{
  int num = 3, pow = 3;
  int result = power(num, pow);
  cout << "Result is: " << result;
  return 0;
}