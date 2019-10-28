class Solution {
public:
	int mirrorReflection(int p, int q) {
		int x = 0, y = 0, dir = 1;
		while (true)
		{
			y += dir * q;
			if (y > p)
			{
				y = p - (y - p);
				dir = -dir;
			}
			if (y < 0)
			{
				y = -y;
				dir = -dir;
			}
			x = p - x;
			if (x == 0 && y == p)
				return 2;
			if (x == p && y == p)
				return 1;
			if (x == p && y == 0)
				return 0;
		}
	}
};