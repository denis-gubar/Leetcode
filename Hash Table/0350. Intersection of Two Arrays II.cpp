class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int a = 0, b = 0, A = nums1.size(), B = nums2.size();
		while (a < A && b < B)
		{
			if (nums1[a] == nums2[b])
			{
				result.push_back(nums1[a]);
				++a, ++b;
			}
			else if (nums1[a] < nums2[b])
				++a;
			else
				++b;
		}
		return result;
	}
};