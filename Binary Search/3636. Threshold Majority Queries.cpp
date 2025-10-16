class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size(), Q = queries.size();
        vector<int> result(Q, -1);
        vector<int> I(Q);
        int const K = sqrt(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&queries, K](int a, int b)
            {
                if (queries[a][0] / K != queries[b][0] / K)
                    return queries[a][0] < queries[b][0];
                return queries[a][1] < queries[b][1];
            });
        //-count, value
        set<pair<int, int>> S;
        unordered_map<int, int> M;
        auto add = [&nums, &S, &M](int pos) -> void
            {
                int const& value = nums[pos];
                if (int count = ++M[value]; count > 1)
                {
                    S.erase({ -count + 1, value });
                    S.insert({ -count, value });
                }
                else
                    S.insert({ -1, value });
            };
        auto del = [&nums, &S, &M](int pos) -> void
            {
                int const& value = nums[pos];
                if (int count = --M[value]; count > 0)
                {
                    S.erase({ -count - 1, value });
                    S.insert({ -count, value });
                }
                else
                    S.erase({ -1, value });
            };
        int a = 1, b = 0;
        for(int i = 0; i < Q; ++i)
        {
            int const q = I[i];
            int const& L = queries[q][0];
            int const& R = queries[q][1];
            int const& THRESHOLD = queries[q][2];
            while (a > L)
            {
                add(a - 1);
                --a;
            }
            while (b < R)
            {
                add(b + 1);
                ++b;
            }
            while (a < L)
            {
                del(a);
                ++a;
            }
            while (b > R)
            {
                del(b);
                --b;
            }
            if (S.empty())
                continue;
            pair<int, int> P = *S.begin();
            if (-P.first < THRESHOLD)
                continue;
            result[q] = P.second;
        }
        return result;
    }
};
