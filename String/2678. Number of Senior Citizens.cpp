class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        int N = details.size();
        for (int i = 0; i < N; ++i)
            if (stoi(details[i].substr(11, 2)) > 60)
                ++result;
        return result;
    }
};
