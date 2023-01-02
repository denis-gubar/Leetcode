class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int result = 0;
        int N = strs.size();
        for(int i = 0; i < N; ++i)
        {
            string s = strs[i];
            bool flag = true;
            for(char c : s)
                flag &= isdigit(c);
            if (flag)
                result = max(result, stoi(s));
            else
                result = max<int>(result, s.size());
        }
        return result;
    }
};