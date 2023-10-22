class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int result = 0;
        int N = processorTime.size();
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < 4; ++k)
            {
                if (tasks.empty())
                    return result;
                result = max(result, processorTime[i] + tasks.back());
                tasks.pop_back();
            }
        return result;
    }
};
