int countByMask[1 << 26];
class Solution {
public:
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
		int P = puzzles.size();
		int W = words.size();
		memset(countByMask, 0, sizeof(countByMask));
		vector<int> result(P);
		for (int i = 0; i < W; ++i)
		{
			int mask = 0;
			for (char c : words[i])
				mask |= 1 << (c - 'a');
			++countByMask[mask];
		}
		for (int i = 0; i < P; ++i)
		{
			int mask = 0;
			int firstBit = 1 << (puzzles[i][0] - 'a');
			for (int j = 1; j < puzzles[i].size(); ++j)
				mask |= 1 << (puzzles[i][j] - 'a');
			for (int submask = mask; ; submask = (submask - 1) & mask)
			{
				result[i] += countByMask[submask | firstBit];
				if (submask == 0)
					break;
			}
		}		
		return result;
	}
};