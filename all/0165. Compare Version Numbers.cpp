class Solution {
public:
	vector<int> calc(const string& version)
	{
		vector<int> result;
		int x = 0;
		for (char c : version)
			if (c == '.')
			{
				result.push_back(x);
				x = 0;
			}
			else
				x = x * 10 + (c - '0');
        result.push_back(x);
        while(result.size() > 1 && result.back() == 0)
            result.pop_back();
		return result;
	}
	int compareVersion(string version1, string version2) {
		vector<int> v1 = calc(version1);
		vector<int> v2 = calc(version2);
		if (v1 < v2)
			return -1;
		if (v1 == v2)
			return 0;
			return 1;
	}
};