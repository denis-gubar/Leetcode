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
		long long a = 0, b = n + 1LL;
		while (a < b)
		{
			long long m = (a + b) / 2;
			int guessResult = guess(m);
			if (guessResult == 0)
				return m;
			if (guessResult < 0)
				b = m;
			else
				a = m;
		}
		return a;
	}
};