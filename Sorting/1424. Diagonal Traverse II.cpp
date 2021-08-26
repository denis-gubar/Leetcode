class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		vector<int> result;
		int N = nums.size();
		vector<pair<int, int>> A;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < nums[i].size(); ++j)
				A.push_back({i + j, -i});
		sort(A.begin(), A.end());
		for (auto a : A)
        {
            int i = -a.second;
            int j = a.first - i;
			result.push_back(nums[i][j]);
        }
		return result;
	}
};