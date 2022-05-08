class SetBit {
    public:

    // POP count 
     int popCount(int x) {
        int count;
        while (x) {
            count++;
            x &= x - 1; // zeroing out the least significant nonzero bit
        }
        return count;
    }
    
    int[] countBits(int n) {
        int[] ans = new int[n + 1];
        for (int x = 0; x <= n; ++x) {
            ans[x] = popCount(x);
        }
        return ans;
    }

    // Approach 2: DP + Most Significant Bit
     int[] countBits(int n) {
        int[] ans = new int[n + 1];
        int x = 0;
        int b = 1;
        // [0, b) is calculated
        while (b <= n) {
            // generate [b, 2b) or [b, n) from [0, b)
            while (x < b && x + b <= n) {
                ans[x + b] = ans[x] + 1;
                ++x;
            }                         
            x = 0; // reset x
            b <<= 1; // b = 2b
        }
        return ans;
    }

    // Approach 3: DP + Least Significant Bit
        int[] countBits(int n) {
            int[] ans = new int[n + 1];
            for (int x = 1; x <= n; ++x) {
                // x / 2 is x >> 1 and x % 2 is x & 1
                ans[x] = ans[x >> 1] + (x & 1); 
            }
            return ans;
        } 
    
        int[] countBits(int num) {
            int[] ans = new int[num + 1];
            for (int x = 1; x <= num; ++x) {
                ans[x] = ans[x & (x - 1)] + 1;
            }
            return ans;
        }
}