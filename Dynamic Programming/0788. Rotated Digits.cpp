class Solution {
public:
    int calc( int x )
    {
        bool result = false;
        string s;
        int k = x;
        while (k)
        {
            int d = k % 10;
            if (d == 0 || d == 1 || d == 8)
                s = string( 1, d + '0' ) + s;
            else if (d == 2)
                s = '5' + s;
            else if (d == 5)
                s = '2' + s;
            else if (d == 6)
                s = '9' + s;
            else if (d == 9)
                s = '6' + s;
            else
                return false;
            k /= 10;
        }
        return stoi(s) != x;
    }
    int rotatedDigits( int N ) {
        int result = 0;
        for (int i = 1; i <= N; ++i)
            result += calc( i );
        return result;
    }
};