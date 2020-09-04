/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
	int x, y, d;
	vector<int>	const dx{ -1, 0, 1, 0 };
	vector<int>	const dy{ 0, 1, 0, -1 };
	int hash(int x, int y)
	{
		return x * 2000 + y;
	}
	void calc(unordered_set<int>& S, Robot& robot)
	{
		auto rotate = [this, &robot](int z)
		{
			while (d != z)
			{
				d = (d + 1) % 4;
				robot.turnRight();
			}
		};        
		robot.clean();        
		for (int z = 0; z < 4; ++z)
		{
			int nx = x + dx[z];
			int ny = y + dy[z];
			int nkey = hash(nx, ny);
			if (S.find(nkey) == S.end())
			{
				S.insert(nkey);
				rotate(z);
				if (robot.move())
				{
					int saveX = x, saveY = y;
					x = nx, y = ny;
					calc(S, robot);
                    rotate((z + 2) % 4);
                    robot.move();
					x = saveX, y = saveY;
				}
			}
		}
	}
	void cleanRoom(Robot& robot) {
		unordered_set<int> S;
		x = y = d = 0;
		S.insert(hash(x, y));
		calc(S, robot);
	}
};
