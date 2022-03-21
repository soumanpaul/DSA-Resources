#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double temp;
        if (n == 0)
            return 1;
        temp = myPow(x, n / 2);
        if (n % 2 == 0)
            return temp * temp;
        else {
            if (n > 0)
                return x * temp * temp;
            else
                return (temp * temp) / x;
        }
    }
    // For negative number
    double myPowForNegativeNumber(double x, int n) {
        double temp;
        if (n == 0)
            return 1;
        temp = myPowForNegativeNumber(x, n / 2);
        if (n % 2 == 0)
            return temp * temp;
        else {
            if (n > 0)
                return x * temp * temp;
            else
                return (temp * temp) / x;
        }
    }
    double Power_Iterative(double x, int N) {
        double ans;
        double current_product = x;
        for (long long i = N; i; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
    }
    // TIme :  O(1)
    int mathPower(int x, int y) {

        // return type of pow()
        // function is double
        return (int)pow(x, y);
    }
    int power(int x, int y) {
        int result = 1;
        while (y > 0) {
            if (y % 2 == 0) {
                x = x * x;
                y = y / 2;
            } else {
                // y isn't even
                result = result * x;
                y = y - 1;
            }
        }
        return result;
    }
};
int main() {
    Solution PW;
    cout << "Power of x^n :" << PW.myPow(2, 4);
    return 0;
}