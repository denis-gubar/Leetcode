class Solution {
public:
	int countVowelPermutation(int n) {
		static const int MOD = 1000000007;
		int result = 0;
		vector<vector<char>> transitions(128);
		transitions['!'] = { 'a', 'e', 'i', 'o', 'u' };
		transitions['a'] = { 'e' };
		transitions['e'] = { 'a', 'i' };
		transitions['i'] = { 'a', 'e', 'o', 'u' };
		transitions['o'] = { 'i', 'u' };
		transitions['u'] = { 'a' };
		unordered_map<char, long long> counts;
		counts['!'] = 1;
		for (int i = 0; i < n; ++i)
		{
			unordered_map<char, long long> nextCounts;
			for (auto m : counts)
				for (char transition : transitions[m.first])
					nextCounts[transition] += m.second % MOD;
			counts = move(nextCounts);
		}
		for (auto m : counts)
			result = (result + m.second) % MOD;
		return result;
	}
};