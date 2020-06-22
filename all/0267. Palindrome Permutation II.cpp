class Solution {
public:
	vector<string> generatePalindromes(string s) {
		vector<string> result;
		unordered_map<char, int> M;
		string middle;
		string A;
		for (char c : s)
			++M[c];
		for (auto m : M)
			if (m.second % 2 == 1)
            {
				middle += m.first;
                A += string(m.second / 2, m.first);
            }
			else
				A += string(m.second / 2, m.first);
		if (middle.size() < 2)
		{
			int N = A.size();
			sort(A.begin(), A.end());
			string t;
			do 
			{
				t = A + middle;
				copy(A.rbegin(), A.rend(), back_inserter(t));
				result.push_back(t);
			} while (next_permutation(A.begin(), A.end()));
		}
		return result;
	}
};