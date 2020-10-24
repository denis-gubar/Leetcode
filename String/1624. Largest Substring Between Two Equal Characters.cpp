class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		int result = -1;
		vector<int>	A(256, -1);
		vector<int>	B(256);
		for (int i = 0; i < s.size(); ++i)
		{
			char x = s[i];
			if (A[x] >= 0)
			{
				B[x] = i;
				result = max(result, B[x] - A[x] - 1);
			}
			else
				A[x] = i;			
		}
		return result;
	}
};