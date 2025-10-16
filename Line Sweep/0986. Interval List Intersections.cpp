class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
		vector<pair<int, int>> M;
		for (auto a : A)
		{
			M.push_back({ a[0], -1 });
			M.push_back({ a[1], 1 });
		}
		for (auto b : B)
		{
			M.push_back({ b[0], -1 });
			M.push_back({ b[1], 1 });
		}
		int balance = 0;
		sort(M.begin(), M.end());
		vector<int> P;
		for (auto m : M)
		{
			balance -= m.second;
			if (balance == 2)
			{
				if (P.empty())
					P.push_back(m.first);
				else
				{
					P.push_back(m.first);
					result.push_back(P);
					P.clear();
				}
			}
			else
			{
				if (!P.empty())
				{
					P.push_back(m.first);
					result.push_back(P);
					P.clear();
				}
			}
		}
		return result;
    }
};