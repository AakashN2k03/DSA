#include<iostream>
#include<string.h>
using namespace std;

int main() {
    char s[100], temp[100], rev[100];
    int i, j = 0;
    cout << "Enter string: ";
    cin >> s;

    int count = 0;
    for (i = 0; s[i] != '\0'; i++) {
        temp[i] = s[i];
        count++;
    }
    temp[i] = '\0';

    for (i = count - 1; i >= 0; i--) {
        rev[j] = s[i];
        j++;
    }
    rev[j] = '\0';

    int count1 = 0;
    for (i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == rev[i]) {
            count1++;
        }
    }

    if (count1 == count) {
        cout << "The given string is palindrome: " << temp << endl;
    } else {
        cout << "The given string is not palindrome." << endl;
    }

    return 0;
}

