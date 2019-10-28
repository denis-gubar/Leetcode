class Solution {
public:
    double myPow( double x, long long n ) {
        if (n == 0)
            return 1.0;
        if (n < 0)
            return myPow( 1 / x, -n );
        if (n == 1)
            return x;
        double f = myPow( x * x, n / 2 );
        if (n % 2 == 1)
            f *= x;
        return f;
    }
};