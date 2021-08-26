class Solution {
public:
	bool canDivideIntoSubsequences(vector<int>& nums, int K) {
		vector<int> count(100'001);
		map<int, int> M;
		int total = nums.size();
		for (int n : nums)
		{
			++count[n];
			++M[n];
		}
		int size = *max_element(count.begin(), count.end());
		if (K * size > total)
			return false;
		vector<int> to_delete;
		for(auto& m: M)
			if (m.second >= size)
			{
				if (--K == 0)
					return true;
				total -= m.second;
				to_delete.push_back(m.first);
			}
		for (int x : to_delete)
			M.erase(x);
		return K * size <= total;
	}
};