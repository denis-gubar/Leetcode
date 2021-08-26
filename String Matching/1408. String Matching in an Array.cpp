class Solution {
public:
	vector<string> stringMatching(vector<string>& words) {
		vector<string> result;
		int N = words.size();
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if (i != j && words[j].find(words[i]) != string::npos)
				{
					result.push_back(words[i]);
					break;
				}
		return result;
	}
};