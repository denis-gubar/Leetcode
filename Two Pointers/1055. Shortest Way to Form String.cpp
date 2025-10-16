class Solution {
public:
	int shortestWay(string source, string target) {
		int N = source.size();
		int pos = 0;
		int result = 1;
		for (int i = 0; i < target.size(); ++i)
		{
			int cycleCount = 0;
			for (; cycleCount < 2; ++cycleCount)
			{
				while (pos < N && source[pos] != target[i])
					++pos;
				if (pos < N)
					break;
                pos = 0;
				++result;
			}
			if (cycleCount > 1)
				return -1;			
            ++pos;            
		}
		return result;
	}
};