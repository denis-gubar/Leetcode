class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int result = 0;
        string s = to_string(num);
        int N = s.size();
        for (int i = 0; i + k <= N; ++i)
        {
            int a = stoi(s.substr(i, k));
            if (a != 0 && num % a == 0)
                ++result;
        }
        return result;
    }
};
