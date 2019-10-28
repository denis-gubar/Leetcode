class Solution {
public:
    int countPrimeSetBits( int L, int R ) {
        int result = 0;
        vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
        for (int i = L; i <= R; ++i)
        {
            int count = 0;
            int x = i;
            while (x)
            {
                count += x % 2;
                x /= 2;
            }
            if (find( primes.begin(), primes.end(), count ) != primes.end())
                ++result;
        }
        return result;
    }
};