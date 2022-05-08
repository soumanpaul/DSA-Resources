bool isPowerOfTwo(int x) {
    // First x in the below expression is
    // for  the case when x is 0
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && (!(x & (x - 1))));
}
