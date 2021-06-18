class Solution {
public:
	int chalkReplacer(vector<int>& chalk, int k) {
		int result = 0;
		int N = chalk.size();
		long long total = 0;
		for (int x : chalk)
			total += x;
		if (k >= total)
			k %= total;
		while (k >= 0)
		{
			k -= chalk[result];
			if (k >= 0)
				result = (result + 1) % N;
		}
		return result;
	}
};