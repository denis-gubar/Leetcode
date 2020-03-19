class Solution {
public:
	double angleClock(int hour, int minutes) {
		double m = minutes * 6.0;
		double h = (hour % 12) * 30.0 +  m / 12.0;
		double delta = abs(h - m);
		return min(delta, 360.0 - delta);
	}
};