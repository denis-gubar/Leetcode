class Solution {
public:
	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		int result = 0;
		unordered_map<long long, int> M;
		for (long long b : nums1)
		{
			for (long long a : nums2)
				if (a * a % b == 0)
			{				
				long long key = a * a / b;
				auto it = M.find(key);
				if (it != M.end())
					result += it->second;
			}
			++M[b];
		}
		M.clear();
		for (long long b : nums2)
		{
			for (long long a : nums1)
				if (a * a % b == 0)
				{
					long long key = a * a / b;
					auto it = M.find(key);
					if (it != M.end())
						result += it->second;
				}
			++M[b];
		}
		return result;
	}
};