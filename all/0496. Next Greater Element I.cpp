class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int>	result;
		stack<int> S;
		int N = nums2.size();
		unordered_map<int, int> M;
		for (int i = N - 1; i >= 0; --i)
		{
			while (!S.empty() && S.top() < nums2[i])
				S.pop();
			if (!S.empty())
				M[nums2[i]] = S.top();
			else
				M[nums2[i]] = -1;
			S.push(nums2[i]);
		}
		for (int n : nums1)
			result.push_back(M[n]);
		return result;
	}
};