class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> S;
		multiset<int> A(nums.begin(), nums.end());
		while(!A.empty())
		{
			set<int>::iterator it = A.begin();
			int x = *it;
			A.erase(it);
			it = prev(A.end());
			x += *it;
			A.erase(it);
			S.insert(x);
		}
		return S.size();
    }
};