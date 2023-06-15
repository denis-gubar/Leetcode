class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result = numeric_limits<double>::lowest();
        double sum = 0.0;
        int N = nums.size();
        auto add = [&sum](double x)
        {
            sum += x;
        };
        auto remove = [&sum](double x)
        {
            sum -= x;
        };
        auto process = [&sum, &result]()
        {
            result = max(result, sum);
        };
        for (int i = 0; i < N; ++i)
        {
            add(nums[i]);
            if (i >= k)
                remove(nums[i - k]);
            if (i >= k - 1)
                process();
        }
        return result / k;
    }
};
