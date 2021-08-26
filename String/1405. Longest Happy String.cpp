class Solution {
public:
	string longestDiverseString(int a, int b, int c) {
		string result{ "$" };
		vector<pair<int, char>> A{ {a, 'a'}, {b, 'b'}, {c, 'c'} };
		while (A[0].first + A[1].first + A[2].first > 0)
		{
			sort(A.begin(), A.end());
			if (A[2].second != result.back())
			{
				int x = min(A[2].first, 2);
				A[2].first -= x;
				result += string(x, A[2].second);
			}
			else
			{
				int x = min(A[1].first, 1);
				if (x == 0)
					break;
				A[1].first -= x;
				result += string(x, A[1].second);
			}
		}
		return result.substr(1);
	}
};