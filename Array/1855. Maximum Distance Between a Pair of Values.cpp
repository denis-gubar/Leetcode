class Solution {
public:
	int maxDistance(vector<int>& nums1, vector<int>& nums2) {
		int result = 0;
		int a = 0, b = 0;
		while (a < nums1.size() && b < nums2.size())
		{            
			if (nums1[a] <= nums2[b])
            {
				result = max(result, b - a);
                ++b;
            }
			else
				++a;			
		}
		return result;
	}
};