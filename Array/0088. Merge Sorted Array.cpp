class Solution {
public:
	void merge( vector<int>& nums1, int m, vector<int>& nums2, int n ) {
		int k = m + n - 1;
		int a = m - 1;
		int b = n - 1;
		while(a >=0 && b >= 0)
			if (nums1[a] == nums2[b])
			{
				nums1[k] = nums1[a]; --k; --a;
				nums1[k] = nums2[b]; --k; --b;
			}
			else if (nums1[a] < nums2[b])
			{
				nums1[k] = nums2[b]; --k; --b;
			}
			else
			{
				nums1[k] = nums1[a]; --k; --a;
			}
		while (a >= 0)
		{
			nums1[k] = nums1[a]; --k; --a;
		}
		while (b >= 0)
		{
			nums1[k] = nums2[b]; --k; --b;
		}
	}
};