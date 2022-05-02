class Solution {
public:
	string largestNumber( vector<int>& nums ) {
		string result;
		vector<int> A( nums );
		sort( A.begin(), A.end(), []( int a, int b )
		{
			string s( to_string( a ) ), t( to_string( b ) );
			string a_string = s + t;
			string b_string = t + s;
			return a_string > b_string;
		}
		);
		for (auto i : A)
			result += to_string( i );
		if (A[0] == 0)
			return "0"s;
		return result;
	}
};