class Solution {
public:
	bool check(vector<int> const& nums, double m, int k) {
		double sum = 0, prev = 0, min_sum = 0;
		for (int i = 0; i < k; i++)
			sum += nums[i] - m;
		if (sum >= 0)
			return true;
		for (int i = k; i < nums.size(); i++) {
			sum += nums[i] - m;
			prev += nums[i - k] - m;
			min_sum = min(prev, min_sum);
			if (sum >= min_sum)
				return true;
		}
		return false;
	}
	double findMaxAverage(vector<int>& nums, int k) {
		double b = numeric_limits<int>::min();
		double a = numeric_limits<int>::max();
		for (int n : nums) {
			b = max(b, 1.0 * n);
			a = min(a, 1.0 * n);
		}
		double prev = b, eps = numeric_limits<int>::max();
		while (eps > 0.00001) {
			double m = (a + b) * 0.5;
			if (check(nums, m, k))
				a = m;
			else
				b = m;
			eps = abs(prev - m);
			prev = m;
		}
		return a;
	}
};