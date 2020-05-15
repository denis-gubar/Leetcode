/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long a = 1, b = n;
        while(a <= b)
        {
            long m = (a + b) / 2;
            int result = guess(m);
            if (result == 0)
                return m;
            if (result == -1)
                b = m - 1;
            else
                a = m + 1;
        }
        return -1;
    }
};