class Solution {
public:
	string findLongestWord( string s, vector<string>& d ) {
		vector<string> A;
		for (auto &i : d)
		{
			bool flag = true;
			int position = 0;
			for (int k = 0; k < i.size(); ++k)
			{
				position = s.find( i[k], position );
				if (position == string::npos)
				{
					flag = false;
					break;
				}
				++position;
			}
			if (flag)
				A.push_back( i );
		}
		A.push_back( string() );
		return *min_element( A.begin(), A.end(), [&s]( const string& a, const string& b )
		{
			return a.size() > b.size() || a.size() == b.size() && a < b;
		} );
	}
};