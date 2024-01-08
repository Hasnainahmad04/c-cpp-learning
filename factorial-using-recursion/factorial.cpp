#include <iostream>
using namespace std;

int fact(int n) {
    // Base Step: if n reach 0 return 1
    if (n == 0) {
        return 1;
    }
    // Recursive Step
    else {
        return n * fact(n - 1);
    }
}

int main() {
    int n;
    cout << "Please Enter A Number: ";
    cin >> n;
    cout << "factorial of " << n << " is " << fact(n);
    return 0;
}
