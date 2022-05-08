// Method 1 (Naive) 
// A Naive method is to try all numbers from 1 to m. For every number x, check if (a*x)%m is 1. 

int modInverse(int a, int m){
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}
// Time Complexity: O(m)
// Auxiliary Space: O(1)

// Method 2 ( Works when m and a are coprime or gcd(a,m)=1 ) 
void modInverse(int a, int m){
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else    {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}

int gcdExtended(int a, int b, int* x, int* y)
    // Base Case
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
// Time Complexity: O(log m)
// Auxiliary Space: O(log m)

// Iterative
int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1; 
    if (m == 1)
        return 0;
    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    // Make x positive
    if (x < 0)
        x += m0; 
    return x;
}

//  Fermats’s little theorem
void modInverse(int a, int m){
    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else{
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m - 2, m);
    }
}
 int power(int x, unsigned int y, unsigned int m){
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}