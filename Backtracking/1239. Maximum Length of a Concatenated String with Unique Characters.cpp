class Solution {
public:
	int maxLength(vector<string>& arr) {
		int result = 0;
		vector<int> A, bitsCount;
		for (string const& s : arr)
		{
			bool isCorrect = true;
			int count = 0;
			int bits = 0;
			for (int c : s)
			{
				int newCount = count | (1 << (c - 'a'));
				isCorrect &= newCount != count;
				count = newCount;
				++bits;
			}
			if (isCorrect)
			{
				A.push_back(count);
				bitsCount.push_back(bits);
			}
			int N = A.size();
			for (int x = 1; x < (1 << N); ++x)
			{
				bool isCorrect = true;
				int current = 0, currentBits = 0;
				for(int k = 0; isCorrect && k < N; ++k)
					if (x & (1 << k))
					{
						int newCurrent = current | A[k];
						isCorrect &= (newCurrent ^ current) == A[k];
						current = newCurrent;
						currentBits += bitsCount[k];
					}
				if (isCorrect && result < currentBits)
					result = currentBits;
			}
		}
		return result;
	}
};