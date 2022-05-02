class Solution {
public:
    string digitSum(string s, int k) {
        string result = s;
        while (s.size() > k)
        {
            result.clear();
            int N = s.size();
            for (int i = 0; i < N; i += k)
            {
                string t = s.substr(i, k);
                int sum = 0;
                for (char c : t)
                    sum += c - '0';
                result += to_string(sum);
            }
            s = result;
        }
        return result;
    }
};
