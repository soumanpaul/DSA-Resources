#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(string &str) {
    int begin = 0;
    int end = str.length() - 1;

    while (begin < end) {
        if (str[begin] != str[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

int main() {

    string str = "souman";
    isPalindrom(str);
}