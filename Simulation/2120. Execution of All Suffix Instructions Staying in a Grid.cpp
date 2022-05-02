class Solution {
public:
	vector<int> executeInstructions(int N, vector<int>& startPos, string s) {
		int M = s.size();
		vector<int> result(M);
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, 1, 0, -1 };
		string dir{ "URDL" };
		unordered_map<char, int> X{ {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3} };
		for (int i = 0; i < M; ++i)
		{
			int x = startPos[0];
			int y = startPos[1];
			int& k = result[i];
			for (int j = i; j < M; ++j)
			{
				int z = X[s[j]];
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
					x = nx, y = ny, ++k;
				else
					break;
			}
		}
		return result;
	}
};