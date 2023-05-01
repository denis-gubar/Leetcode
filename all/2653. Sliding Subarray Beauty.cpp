class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int N = nums.size();
        vector<int> result;
        multiset<int> L, R;
        auto add = [&L, &R, x](int a)
        {
            L.insert(a);
            if (L.size() > x)
            {
                int b = *L.rbegin();
                L.erase(prev(L.end()));
                R.insert(b);
            }
        };
        auto remove = [&L, &R, x](int a)
        {
            if (auto it = R.find(a); it != R.end())
                R.erase(it);
            else
            {
                L.erase(L.find(a));
                if (!R.empty())
                {
                    int b = *R.begin();
                    R.erase(R.begin());
                    L.insert(b);
                }
            }
        };
        for (int i = 0; i < k; ++i)
            add(nums[i]);
        for (int i = k; i <= N; ++i)
        {
            if (L.size() < x || *L.rbegin() >= 0)
                result.push_back(0);
            else
                result.push_back(*L.rbegin());
            remove(nums[i - k]);
            if (i < N)
                add(nums[i]);
        }
        return result;
    }
};
