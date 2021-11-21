class Solution {
public:
	int countVowelSubstrings(string word) {
		string vowels{ "aeiou" };
		int N = word.size();
		int result = 0;
		for (int start = 0; start < N; ++start)
		{
			vector<int> A(5);
			for (int length = 1; length + start <= N; ++length)
			{
				bool isOk = false;
				for (int i = 0; i < 5; ++i)
					if (word[start + length - 1] == vowels[i])
					{
						isOk = true;
						++A[i];
						break;
					}
                if (!isOk)
                    break;
				result += (*min_element(A.begin(), A.end()) > 0);                
			}
		}
		return result;
	}
};