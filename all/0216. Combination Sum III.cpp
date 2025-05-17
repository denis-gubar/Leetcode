class Solution {
public:
    vector<vector<int>> combinationSum3(int K, int N) {
        vector<vector<int>> result;
        vector<int> prefix;
        int sum = 0;
        function<void(void)> dfs = [&]() -> void
            {                
                if (prefix.size() == K && sum == N)
                {
                    result.push_back(prefix);
                    return;
                }
                for (int d = prefix.empty() ? 1 : (prefix.back() + 1); d < 10; ++d)
                {
                    sum += d;
                    if (sum > N)
                    {
                        sum -= d;
                        break;
                    }
                    prefix.push_back(d);
                    dfs();
                    prefix.pop_back();
                    sum -= d;
                }
            };
        dfs();
        return result;        
    }
};
