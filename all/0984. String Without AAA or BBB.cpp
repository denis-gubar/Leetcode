class Solution {
public:
	string strWithout3a3b(int A, int B) {
		string result;
		while (A || B)
		{
			if (A == B)
			{
				--A, --B;
				result += "ab";
			}
			else if (A > B)
			{
				int k = min(A, 2);
				A -= k;
				result += string(k, 'a');
				if (B)
				{
					--B; result += 'b';
				}
			}
			else
			{
				int k = min(B, 2);
				B -= k;
				result += string(k, 'b');
				if (A)
				{
					--A; result += 'a';
				}
			}
		}
		return result;
	}
};