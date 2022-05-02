class Solution {
public:
	int scoreOfStudents(string s, vector<int>& answers) {
		int result = 0;
		int N = s.size();
		vector<int> M(1001);
		for (int x : answers)
			++M[x];
		int correctResult = 0;
		for (int i = 0; i < N; i += 2)
		{
			int left = s[i] - '0';
			int j = i;
			while (j + 2 < N && s[j + 1] == '*')
			{
				left *= s[j + 2] - '0';
				j += 2;
			}
			correctResult += left;
			i = j;
		}
		vector<vector<unordered_set<int>>> F(N, vector<unordered_set<int>>(N));
		for (int start = 0; start < N; start += 2)
			F[start][start].insert(s[start] - '0');
		for (int length = 3; length <= N; length += 2)
			for (int start = 0; start + length <= N; start += 2)
				for (int leftLength = 1; leftLength < length; leftLength += 2)
				{
					if (s[start + leftLength] == '+')
						for (int left : F[start][start + leftLength - 1])
							for (int right : F[start + leftLength + 1][start + length - 1])
                                if (left + right <= 1000)
								    F[start][start + length - 1].insert(left + right);
					if (s[start + leftLength] == '*')
						for (int left : F[start][start + leftLength - 1])
							for (int right : F[start + leftLength + 1][start + length - 1])
                                if (left * right <= 1000)
								    F[start][start + length - 1].insert(left * right);
				}
		for (int x : F[0][N - 1])
			if (x == correctResult)
				result += 5 * M[x];
			else if (x <= 1000)
				result += 2 * M[x];
		return result;
	}
};