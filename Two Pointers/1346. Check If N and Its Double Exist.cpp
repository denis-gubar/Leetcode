class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		unordered_set<int> S;
        sort(begin(arr), end(arr));
		for (int a : arr)
			if (S.find(a * 2) != S.end() || a % 2 == 0 && S.find(a / 2) != S.end())
				return true;
			else
				S.insert(a);
		return false;
	}
};