class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int result = 0;
        int N = batteryPercentages.size();
        for(int i = 0; i < N; ++i)
            if (batteryPercentages[i] > 0)
            {
                ++result;
                for (int j = i + 1; j < N; ++j)
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
            }
        return result;
    }
};
