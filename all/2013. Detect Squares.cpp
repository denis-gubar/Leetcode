class DetectSquares {
public:
	DetectSquares() {
		grid = vector<vector<int>>(1001, vector<int>(1001));
	}

	void add(vector<int> point) {
		int const& i = point[0];
		int const& j = point[1];
		++grid[i][j];
		X.insert(i);
	}

	bool check(int x, int y)
	{
		return x >= 0 && x <= 1000 && y >= 0 && y <= 1000;
	}

	int count(vector<int> point) {
		int const& i = point[0];
		int const& j = point[1];
		int result = 0;
		for (int x : X)
		{
			int delta = i - x;
			if (delta != 0)
			{
				int a = i - delta, b = j - delta;                
				if (check(a, b))
					result += grid[a][b] * grid[i][b] * grid[a][j];                
                b = j + delta;
                if (check(a, b))
					result += grid[a][b] * grid[i][b] * grid[a][j];
			}
            
		}
		return result;
	}
	vector<vector<int>> grid;
	unordered_set<int> X;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */