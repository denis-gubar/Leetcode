class Solution {
public:
    long long minimumPossibleSum(int N, int target) {
        long long result = 0;
        vector<bool> visited(200'000);
        int last = 0;
        visited[last] = true;
        for (int i = 0; i < N; ++i)
        {
            while (visited[last])
                ++last;
            visited[last] = true;
            if (last < target)
                visited[target - last] = true;
            result += last;
        }
        return result;
    }
};
