/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
	int findCelebrity(int n) {
		for (int candidate = 0; candidate < n; ++candidate)
		{
            int count = 1;
			for (int other = 0; other < n; ++other)
			{
				if (other == candidate)
					continue;
				if (!knows(other, candidate))
					break;
				++count;
			}
			if (count == n)
			{
                bool flag = true;
				for (int other = 0; other < n; ++other)
					if (other != candidate && knows(candidate, other))
					{
						flag = false;
						break;
					}
				if (flag)
					return candidate;
			}
		}
		return -1;
	}
};