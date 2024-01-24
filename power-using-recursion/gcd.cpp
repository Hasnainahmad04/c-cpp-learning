#include <iostream>
#include <string>

using namespace std;

int main()
{
    string prhny_waly_bachy[] = {};
}

// cctype
// 1- toupper(), acccept a character and convert it to upper case
// 2- find(),
//  accept a character/word and return the first position of that character/word in string, return string::npos in case of not found
//  Optionally accept a second argument position from which to start finding element
// 3- rfind(), accept a character/word and return the last position of that character/word in string, return string::npos in case of not found

// find_first_of: returns position of the first occurrence of any of the characters included in the string passed as parameter
// find_first_not_of works in a similar way, except that it finds the first character that is not one of the characters specified in the string,