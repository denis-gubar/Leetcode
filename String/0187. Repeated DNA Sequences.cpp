class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		string const nucleotids = "ACGT"s;
		long long hash = 0;
		int N = s.size();
		unordered_map<int, int> M;
		for (int i = 0; i < 10 && i < N; ++i)
		{
			hash <<= 2;
			hash += nucleotids.find(s[i]);
		}
		++M[hash];
		for (int i = 10; i < N; ++i)
		{
			hash <<= 2;
			hash += nucleotids.find(s[i]);
			hash &= (1 << 20) - 1;
			if (++M[hash] == 2)
				result.push_back(s.substr(i - 9, 10));
		}
		return result;
	}
};