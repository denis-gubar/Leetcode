class Solution {
public:
    int minimumSum(int N, int k) {
        int result = 0;
        vector<bool> visited(1'000);
        int last = 0;
        visited[last] = true;
        for (int i = 0; i < N; ++i)
        {
            while (visited[last])
                ++last;
            visited[last] = true;
            if (last < k)
                visited[k - last] = true;
            result += last;
        }
        return result;
    }
};
