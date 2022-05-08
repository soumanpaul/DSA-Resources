class powerXY {
    public: 
    
    int power(int x, int y){
        // If x^0 return 1
        if (y == 0)
            return 1;
  
       // If we need to find of 0^y
        if (x == 0)
            return 0;
  
       // For all other cases
        return x * power(x, y - 1);
    }
    int power(int x, int y){
        // return type of pow() 
        // function is double
        return (int)pow(x, y);
    }
  
    // T = O(n), S = O(1)
        int power(int x, unsigned int y){
            if(y==0)
                return 1;
            else if(y % 2 == 0){
                return power(x, y/2) * power(x, y/2);
            }    
            else{
                return x * power(x, y/2) * power(x, y/2);
            }
        }

    // T = O(log n), S = O(1)
        int power(int x, unsigned int y){
            int temp;
            if( y== 0)
                return 1;
            temp = power(x, y/2) ;
            if(y%2 == 0)
                return temp * temp;
            else
                return x * temp * temp;       
        }
    //  negative y and float x. 
        float power(float x, unsigned int y){
            float temp;
            if( y== 0)
                return 1;
            temp = power(x, y/2);
            else if(y % 2 == 0){
                return temp * temp;
            }    
            else{
                if(y > 0)
                    return x * temp * temp;
                else 
                    return (1/x) * temp * temp;    
            }
        }
        int power(int x, unsigned int y){
            int res = 1; // Initialize result
            while (y > 0) {
            // If y is odd, multiply x with result
            if (y & 1)
                res = res * x;
            // y must be even now
            y = y >> 1; // y = y/2
            x = x * x; // Change x to x^2
        }
    return res;
}
}
// Language: cpp

