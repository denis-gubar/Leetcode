class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int result = 0;
        int N = hours.size();
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if ((hours[i] + hours[j]) % 24 == 0)
                    ++result;
        return result;
    }
};
