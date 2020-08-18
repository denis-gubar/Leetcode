class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		int N = arr.size();
		arr.push_back(0);
		arr.push_back(0);
		arr.push_back(0);
		for (int i = 0; i < N; ++i)
			if (arr[i] % 2 + arr[i + 1] % 2 + arr[i + 2] % 2 == 3)
				return true;
		return false;
	}
};