class Solution {
public:
	enum class State
	{
		Pending,
		A,
		B,
		Draw
	};
	State check(vector<vector<int>> const& A)
	{
		for (int k = 1; k < 3; ++k)
		{
			if (A[0][0] == k && A[0][1] == k && A[0][2] == k ||
				A[1][0] == k && A[1][1] == k && A[1][2] == k ||
				A[2][0] == k && A[2][1] == k && A[2][2] == k ||
				A[0][0] == k && A[1][0] == k && A[2][0] == k ||
				A[0][1] == k && A[1][1] == k && A[2][1] == k ||
				A[0][2] == k && A[1][2] == k && A[2][2] == k ||
				A[0][0] == k && A[1][1] == k && A[2][2] == k ||
				A[0][2] == k && A[1][1] == k && A[2][0] == k)
			{
				if (k == 1)
					return State::A;
				return State::B;
			}
		}
		int count = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				count += A[i][j] == 0;
		if (count) return State::Pending;
		return State::Draw;
	}
	string tictactoe(vector<vector<int>>& moves) {
		vector<vector<int>> A(3, vector<int>(3));
		int k = 2;
		for (vector<int> const& move : moves)
		{
			k = 3 - k;
			A[move[0]][move[1]] = k;
		}
		switch (check(A))
		{
			case State::A: return "A";
			case State::B: return "B";
			case State::Draw: return "Draw";
			case State::Pending: return "Pending";
		}
		return {};
	}
};