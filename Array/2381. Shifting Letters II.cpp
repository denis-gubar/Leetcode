class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string result = s;
		int N = s.size(), M = shifts.size();
		vector<int> A(N + 1);
		for (int i = 0; i < M; ++i)
		{
			int const& start = shifts[i][0];
			int const& end = shifts[i][1];
			int const& direction = shifts[i][2];
			int delta = direction * 2 - 1;
			A[start] += delta;
			A[end + 1] -= delta;
		}
		int delta = 0;
		for (int i = 0; i < N; ++i)
		{
			delta += A[i];
			result[i] = ((result[i] - 'a') + delta + 260'000) % 26 + 'a';
		}
        return result;
    }
};
