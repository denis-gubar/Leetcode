class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        multiset<int> S(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i)
        {
            auto it = prev(S.end());
            int x = *it;
            S.erase(it);
            x = sqrt(x);
            S.insert(x);
        }
        return accumulate(S.begin(), S.end(), 0LL);
    }
};
