class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> heights;
        int N = gain.size();
        heights.reserve(N + 1);
        heights.emplace_back(0);
        partial_sum(gain.begin(), gain.end(), back_inserter(heights));
        return *max_element(heights.begin(), heights.end());
    }
};
