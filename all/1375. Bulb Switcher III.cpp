class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int result = 0;
		set<int> S;
		S.insert(0);
		for (int i = 0; i < light.size(); ++i)
		{
			S.insert(-light[i]);
			result += -*S.begin() == i + 1;
		}
		return result;
	}
};