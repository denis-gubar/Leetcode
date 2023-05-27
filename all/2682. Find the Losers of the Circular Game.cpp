class Solution {
public:
    vector<int> circularGameLosers(int N, int k) {
        vector<int> result;
        vector<bool> visited(N);
        int pos = 0;
        visited[pos] = true;
        for (int i = 0; i < N; ++i)
        {
            pos = (pos + (i + 1) * k) % N;
            if (visited[pos])
                break;
            visited[pos] = true;
        }
        for (int i = 0; i < N; ++i)
            if (!visited[i])
                result.push_back(i + 1);
        return result;
    }
};
