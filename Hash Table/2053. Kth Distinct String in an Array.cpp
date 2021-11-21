class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		unordered_map<string, int> M;
		string result;
		for (string const& t : arr)
			++M[t];
		for (string const& t : arr)
			if (M[t] == 1)
			{
				--k;
				if (k == 0)
					result = t;
			}
		return result;
	}
};