class Solution {
public:
    Solution(double radius, double x_center, double y_center) : 
		x(x_center), y(y_center), r(radius),
		engine(rd()),
        dist(uniform_real_distribution<>(-1.0, 1.0)) 
    {
	}

	vector<double> randPoint() {
        while(true)
        {
		    double deltaX = dist(engine);
            double deltaY = dist(engine);
            if (deltaX * deltaX + deltaY * deltaY <= 1.0)            
		        return { deltaX * r + x, deltaY * r + y };
        }
	}
	double x, y, r;
	random_device rd;
	mt19937 engine;
	uniform_real_distribution<> dist;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */