class Solution {
public:
	bool canBeValid(string s, string locked) {
		int a = 0, b = 0;
		int N = s.size();
        if (N % 2 == 1)
            return false;
		for (int i = 0; i < N; ++i)
		{
			if (locked[i] == '1')
			{
				if (s[i] == '(')
					++a, ++b;
				else
					--a, --b;				
			}
			else
				--a, ++b;
			a = max(0, a);
			if (b < 0)
				return false;

		}
		return a == 0;
	}
};