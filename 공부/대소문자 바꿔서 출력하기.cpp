#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (char c : str) {
        if (isupper(c)) cout << (char)tolower(c);
        if (islower(c)) cout << (char)toupper(c);
    }
    return 0;
}