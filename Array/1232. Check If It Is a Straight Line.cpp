class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int N = coordinates.size();
		if (coordinates[0][0] == coordinates[1][0])
		{
			for (int i = 3; i < N; ++i)
				if (coordinates[i][0] != coordinates[0][0])
					return false;
			return true;
		}
		int dx = coordinates[1][0] - coordinates[0][0];
		int dy = coordinates[1][1] - coordinates[0][1];
		for (int i = 3; i < N; ++i)
			if (dx * (coordinates[i][1] - coordinates[0][1]) !=
				dy * (coordinates[i][0] - coordinates[0][0]) )
				return false;
		return true;
	}
};