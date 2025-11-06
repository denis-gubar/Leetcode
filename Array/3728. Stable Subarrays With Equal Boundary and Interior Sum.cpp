static long long A[100'001];
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long result = 0;
        int const N = capacity.size();
        unordered_map<int, vector<int>> M;
        A[0] = 0;
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + capacity[i];
        for (int i = 0; i < N; ++i)
            M[capacity[i]].push_back(i);
        queue<int> Q;
        for (auto const& [key, value] : M)
        {
            while (!Q.empty())
                Q.pop();
            unordered_map<long long, int> M;
            for (int pos : value)
            {
                while (!Q.empty() && Q.front() + 1 < pos)
                {
                    int prev = Q.front(); Q.pop();
                    ++M[A[prev + 1]];
                }
                if (auto it = M.find(A[pos] - capacity[pos]); it != M.end())
                    result += it->second;
                Q.push(pos);
            }
        }
        return result;
    }
};
