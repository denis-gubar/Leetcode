class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<int> result(nums);
		for (int i = 2; i + 1 < N; ++i)
			if (result[i] + result[i - 2] == 2 * result[i - 1])
				swap(result[i + 1], result[i]);
		while (result[N - 1] + result[N - 3] == 2 * result[N - 2])
        {
			rotate(result.begin(), result.begin() + 1, result.end());
            swap(result[N - 2], result[N - 1]);
        }
		return result;
	}
};