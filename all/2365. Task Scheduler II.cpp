class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long result = 0;
        int N = tasks.size();
        unordered_map<int, long long> M;
        for (int i = 0; i < N; ++i)
        {
            ++result;
            int const& T = tasks[i];
            if (auto it = M.find(T); it != M.end())
                result = max(result, it->second + space + 1);
            M[T] = result;
        }
        return result;
    }
};
