class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (string const& w : words)
        {
            int sum = 0;
            for (char c : w)
                sum += weights[c - 'a'];
            result += 'a' + (25 - sum % 26);
        }
        return result;
    }
};
