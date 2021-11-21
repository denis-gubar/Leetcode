class Robot {
public:
	Robot(int width, int height) {
        dx = { 0, 1, 0, -1 };
		dy = { 1, 0, -1, 0 };		
		dir = x = y = 0;
		M = width, N = height;
		S = { "East", "North", "West", "South" };
		P = 2 * (M + N) - 4;
	}

	void move(int num) {
        if (num == 0)
            return;
        num %= P;
        if (num == 0) 
        {
            if (x == 0 && y == 0)
                dir = 3;
            return;
        }
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {            
			x = nx, y = ny;
            move(num - 1);
        }
		else
		{
			dir = (dir + 1) % 4;
			move(num);
		}
	}

	vector<int> getPos() {
		return { y, x };
	}

	string getDir() {
		return S[dir];
	}
	vector<int>	dx, dy;
	int x, y, dir;
	int N, M, P;
	vector<string> S;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */