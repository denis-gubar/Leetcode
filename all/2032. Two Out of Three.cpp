class Solution {
public:
	vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
		vector<int> result;
		unordered_map<int, int> M;
		unordered_set<int> s1(nums1.begin(), nums1.end());
		unordered_set<int> s2(nums2.begin(), nums2.end());
		unordered_set<int> s3(nums3.begin(), nums3.end());
		for (int x : s1)
			++M[x];
		for (int x : s2)
			++M[x];
		for (int x : s3)
			++M[x];
		for (auto [key, value] : M)
			if (value > 1)
				result.push_back(key);
		return result;
	}
};