class Solution {
public:
	string addBinary( string a, string b ) {
		string result;
		int i = 0, k = 0;
		reverse( a.begin(), a.end() );
		reverse( b.begin(), b.end() );
		while (i < a.size() && i < b.size())
		{
			int sum = k + (a[i] - '0') + (b[i] - '0');
			result += (char) ((sum % 2) + '0');
			k = sum / 2;
			++i;
		}
		while (i < a.size())
		{
			int sum = k + (a[i] - '0');
			result += (char) ((sum % 2) + '0');
			k = sum / 2;
			++i;
		}
		while (i < b.size())
		{
			int sum = k + (b[i] - '0');
			result += (char) ((sum % 2) + '0');
			k = sum / 2;
			++i;
		}
		if (k)
		{
				result += (char) (k + '0');
		}
		reverse( result.begin(), result.end() );
		return result;
	}
};