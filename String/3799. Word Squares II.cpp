class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> result;
        int const N = words.size();
        sort(words.begin(), words.end());
        for(int a = 0; a < N; ++a)
            for(int b = 0; b < N; ++b)
                if (a != b)
                    for(int c = 0; c < N; ++c)
                        if (a != c && b != c)
                            for(int d = 0; d < N; ++d)
                                if (a != d && b != d && c != d)
                                {
                                    string const& top = words[a];
                                    string const& left = words[b];
                                    string const& right = words[c];
                                    string const& bottom = words[d];
                                    if (top[0] == left[0] && top[3] == right[0] &&
                                        bottom[0] == left[3] && bottom[3] == right[3])
                                        result.push_back({top, left, right, bottom});
                                }
        sort(result.begin(), result.end());
        result.resize(unique(result.begin(), result.end()) - result.begin());
        return result;
    }
};
