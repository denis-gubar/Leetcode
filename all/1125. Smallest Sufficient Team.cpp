class Solution {
public:
	vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
		vector<int> result;
		map<string, int> M;
		int N = req_skills.size();
		for (string const& s : req_skills)
			M[s] = M.size();
		vector<int> A(1 << N, N + 1);
		vector<vector<int>> results(1 << N);
		vector<int> P;
		for (auto const& p : people)
		{
			P.push_back(0);
			for (string const& s : p)
				if (M.find(s) != M.end())
					P.back() |= 1 << M[s];
		}
		A[0] = 0;
		for (int i = 0; i < P.size(); ++i)
			for (int a = 0; a < A.size(); ++a)
				if (A[a] < N && A[a | P[i]] > A[a] + 1)
				{
					A[a | P[i]] = A[a] + 1;
					results[a | P[i]] = results[a];
					results[a | P[i]].push_back(i);
				}
		return results.back();
	}
};