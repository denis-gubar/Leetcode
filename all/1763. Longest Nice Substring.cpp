class Solution {
public:
	string longestNiceSubstring(string s) {
		string result;
		int N = s.size();
		for(int length = 1; length <= N; ++length)
			for (int start = N - length; start >= 0; --start)
			{
				string x = s.substr(start, length);				
				set<char> S(x.begin(), x.end());
				bool flag = true;
				for(char c : S)
					if (S.find(::tolower(c)) == S.end() ||
						S.find(::toupper(c)) == S.end())
					{
						flag = false;
						break;
					}
				if (flag)
					result = x;
			}			
		return result;
	}
};