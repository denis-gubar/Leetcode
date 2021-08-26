class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> odd;
		vector<int> even;
		vector<int> result;
		for (int a : A)
			if (a % 2)
				odd.push_back(a);
			else
				even.push_back(a);
		for (int i = 0; i < odd.size(); ++i)
		{
			result.push_back(even[i]);
			result.push_back(odd[i]);
		}
		return result;
	}
};