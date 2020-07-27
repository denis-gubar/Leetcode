class Solution {
public:
	int distance(vector<int> const& p1, vector<int>	const& p2)
	{
		return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
	}
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<int>	A;
		A.push_back(distance(p1, p2));
		A.push_back(distance(p1, p3));
		A.push_back(distance(p1, p4));
		A.push_back(distance(p2, p3));
		A.push_back(distance(p2, p4));
		A.push_back(distance(p3, p4));
		sort(A.begin(), A.end());
		int x = A[0];
		return x > 0 && x == A[3] && 2 * x == A[4] && 2 * x == A[5];
	}
};