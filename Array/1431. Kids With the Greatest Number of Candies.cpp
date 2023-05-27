class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int N = candies.size();
        int m = *max_element(candies.begin(), candies.end());
        vector<bool> result(N);
        for (int i = 0; i < N; ++i)
            result[i] = candies[i] + extraCandies >= m;
        return result;            
    }
};
