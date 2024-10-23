class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int const N = nums.size();
        vector<long long> result;
        result.reserve(N - k);
        unordered_map<int, int> M;
        set<pair<int, int>> S, R;
        long long sum = 0;
        auto add = [&M, x, &sum, &S, &R](int value)
            {
                if (++M[value] > 1)
                {
                    if (auto it = S.find({ M[value] - 1, value }); it != S.end())
                    {
                        sum -= (M[value] - 1LL) * value;
                        S.erase(it);
                    }
                    else
                        R.erase({ M[value] - 1, value });
                }
                pair<int, int> const P{ M[value], value };
                if (R.empty() && S.size() < x)
                {
                    S.insert(P);
                    sum += 1LL * P.first * P.second;
                }
                else
                    R.insert(P);
                if (S.size() == x && !R.empty() && *R.rbegin() > *S.begin())
                {
                    sum -= 1LL * S.begin()->first * S.begin()->second;
                    R.insert(*S.begin());
                    S.erase(S.begin());
                }
                while (!R.empty() && S.size() < x)
                {
                    auto it = prev(R.end());
                    S.insert(*it);
                    sum += 1LL * it->first * it->second;
                    R.erase(it);
                }
            };
        auto remove = [&M, x, &sum, &S, &R](int value)
            {
                --M[value];
                if (auto it = S.find({ M[value] + 1, value }); it != S.end())
                {
                    sum -= (M[value] + 1LL) * value;
                    S.erase(it);
                }
                else
                    R.erase({ M[value] + 1, value });
                if (M[value] == 0)
                {
                    M.erase(value);
                    return;
                }
                pair<int, int> const P{ M[value], value };
                if (R.empty() && S.size() < x)
                {
                    S.insert(P);
                    sum += 1LL * P.first * P.second;
                }
                else
                    R.insert(P);
                while (!R.empty() && S.size() < x)
                {
                    auto it = prev(R.end());
                    S.insert(*it);
                    sum += 1LL * it->first * it->second;
                    R.erase(it);
                }
            };
        for (int i = 0; i < k; ++i)
            add(nums[i]);
        result.push_back(sum);
        for (int i = k; i < N; ++i)
        {
            remove(nums[i - k]);
            add(nums[i]);
            result.push_back(sum);
        }
        return result;
    }
};
