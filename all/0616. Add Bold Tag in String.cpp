class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		string result;
		int N = s.size();
		vector<bool> bold(N);
		sort(dict.begin(), dict.end());
		for (int i = 0; i < N; ++i)
		{
			auto it = lower_bound(dict.begin(), dict.end(), s.substr(i, 1));
			while(it != dict.end() && s[i] == (*it)[0])
			{
				int length = (*it).size();
				if (N - i >= length && equal(s.begin() + i, s.begin() + i + length, (*it).begin(), (*it).end()))
				{
					for (int j = i; j < i + length; ++j)
						bold[j] = true;
				}
                ++it;
			}
		}
		bool isBold = false;
		for (int i = 0; i < N; ++i)
		{
			if (bold[i])
			{
				if (!isBold)
					isBold = true, result += "<b>"s + s[i];
				else
					result += s[i];
			}
			else
			{
				if (isBold)
					isBold = false, result += "</b>"s + s[i];
				else
					result += s[i];
			}
		}
		if (isBold)
			result += "</b>"s;
		return result;
	}
};