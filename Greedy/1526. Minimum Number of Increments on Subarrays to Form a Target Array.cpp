class Solution {
public:
	int minNumberOperations(vector<int>& target) {
		int result = target[0];
		for (int i = 1; i < target.size(); ++i)
			result += max(0, target[i] - target[i - 1]);
		return result;
	}
};