class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        vector<bool> M1(4000), M2(4000);
		for (int x : nums1)
			M1[x + 1000] = true;
		for (int x : nums2)
			M2[x + 1000] = true;
        for (int i = 0; i <= 2000; ++i)
        {
			if (M1[i] && !M2[i])
				result[0].push_back(i - 1000);
			if (!M1[i] && M2[i])
				result[1].push_back(i - 1000);
        }
		return result;
    }
};
