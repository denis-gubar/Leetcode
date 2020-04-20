class Solution {
public:
	int calc(int left, int right, char op)
	{
		switch (op)
		{
		case '-':
			return left - right;
		case '+':
			return left + right;
		case '*':
			return left * right;
		}
		return -1;
	}
	vector<int> diffWaysToCompute(string input) {
		vector<int> A;
		string operators;
		int buffer = 0;
		for (char c : input)
		{
			if (isdigit(c))
				buffer = buffer * 10 + (c - '0');
			else
			{
				A.push_back(buffer);
				buffer = 0;
				operators += c;
			}
		}
		A.push_back(buffer);
		int N = A.size();
		vector<vector<vector<int>>> F(N, vector<vector<int>>(N));
		for (int i = 0; i < N; ++i)
			F[i][i].push_back(A[i]);
		for (int i = 0; i + 1 < N; ++i)
			F[i][i + 1].push_back(calc(A[i], A[i + 1], operators[i]));
		for (int length = 2; length < N; ++length)
			for (int i = 0; i + length < N; ++i)
				for (int middle = 0; middle < length; ++middle)
					for(int left: F[i][i + middle])
						for (int right : F[i + middle + 1][i + length])
							F[i][i + length].push_back(calc(left, right, operators[i + middle]));
		return F[0][N - 1];
	}
};