class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int const N = friends.size();
        vector<int> result;
        result.reserve(N);
        for (int x : order)
            if (find(friends.begin(), friends.end(), x) != friends.end())
                result.push_back(x);
        return result;
    }
};
