class Solution {
public:
	int numSteps(string s) {
		int result = 0;
		while (s != "1")
		{            
			++result;
			if (s.back() == '0')
				s.pop_back();
			else
			{
				int i = s.size() - 1;
				for (; i >= 0; --i)
					if (s[i] == '1')
						s[i] = '0';
					else
					{
						s[i] = '1';
						break;
					}
				if (i < 0)
					return result + s.size();                
			}
		}
		return result;
	}
};