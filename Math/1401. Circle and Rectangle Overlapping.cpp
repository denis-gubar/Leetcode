class Solution {
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2)
			return true;
		if (x_center >= x1 && x_center <= x2 && y_center > y2 && y_center - radius <= y2)
			return true;
		if (x_center >= x1 && x_center <= x2 && y_center < y1 && y_center + radius >= y1)
			return true;
		if (y_center >= y1 && y_center <= y2 && x_center > x2 && x_center - radius <= x2)
			return true;
		if (y_center >= y1 && y_center <= y2 && x_center < x1 && x_center + radius >= x1)
			return true;
		vector<double> x{ 1.0 * x1, 1.0 * x1, 1.0 * x2, 1.0 * x2, 0.5 * (x1 + x2), 0.5 * (x1 + x2), 1.0 * x1, 1.0 * x2, 0.5 * (x1 + x2) };
		vector<double> y{ 1.0 * y1, 1.0 * y2, 1.0 * y1, 1.0 * y2, 1.0 * y1, 1.0 * y2, 0.5 * (y1 + y2), 0.5 * (y1 + y2), 0.5 * (y1 + y2) };
		for (int i = 0; i < 9; ++i)
			if ((x_center - x[i]) * (x_center - x[i]) + (y_center - y[i]) * (y_center - y[i]) <= radius * radius * 1.0000000000001)
				return true;
		return false;
	}
};