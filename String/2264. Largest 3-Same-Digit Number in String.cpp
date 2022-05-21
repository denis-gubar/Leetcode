class Solution {
public:
    string largestGoodInteger(string num) {
        string result;
        int N = num.size();
        for (int i = 0; i + 2 < N; ++i)
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                string t = num.substr(i, 3);
                result = max(result, t);
            }
        return result;
    }
};
