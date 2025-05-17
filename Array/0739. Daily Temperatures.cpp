class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int const N = temperatures.size();
        vector<int> result(N);
        stack<int> S;
        for (int i = N - 1; i >= 0; --i)
        {
            while (!S.empty() && temperatures[S.top()] <= temperatures[i])
                S.pop();
            if (!S.empty())
                result[i] = S.top() - i;
            S.push(i);
        }
        return result;
    }
};
