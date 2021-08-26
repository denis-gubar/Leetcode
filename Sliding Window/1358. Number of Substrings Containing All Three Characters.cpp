class Solution {
public:
	int numberOfSubstrings(string s) {
		int result = 0;
		int N = s.size(), a = 0, b = 0;
		int aCount = 0, bCount = 0, cCount = 0;
		while (b < N)
		{
			while (b < N && (aCount == 0 || bCount == 0 || cCount == 0))
			{
				if (s[b] == 'a') ++aCount;
				else if (s[b] == 'b') ++bCount;
				else if (s[b] == 'c') ++cCount;
				++b;
			}
			if (b == N)
				break;
			int oldA = a;
			while (aCount && bCount && cCount)
			{
                result += N - b + 1;
                if (s[a] == 'a') --aCount;
				else if (s[a] == 'b') --bCount;
				else if (s[a] == 'c') --cCount;
				++a;                
			}
		}
        while (b == N && aCount && bCount && cCount)
        {
            ++result;
            if (s[a] == 'a') --aCount;
    		else if (s[a] == 'b') --bCount;
			else if (s[a] == 'c') --cCount;
			++a;                
		}
		return result;
	}
};