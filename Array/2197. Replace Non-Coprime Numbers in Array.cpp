class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {        
        list<int> L(nums.begin(), nums.end());
        for (auto it = L.begin(); it != L.end();)
        {
            if (it != L.begin())
            {
                int a = *prev(it);
                int b = *it;
                int k = gcd(a, b);
                if (k > 1)
                {
                    L.erase(prev(it));
                    *it = a / k * b;
                    continue;
                }
            }
            ++it;
        }
        vector<int> result(L.begin(), L.end());
        return result;
    }
};
