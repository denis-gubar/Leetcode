class Solution {
public:
    int largestInteger(int num) {
        string s(to_string(num));
        int N = s.size();
        string even, odd;
        for (int i = 0; i < N; ++i)
            if (s[i] % 2 == 0)
                even.push_back(s[i]);
            else
    			odd.push_back(s[i]);
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());        
        for (int i = 0; i < N; ++i)
            if (s[i] % 2 == 0)
            {
                s[i] = even.back();
                even.pop_back();
            }
            else
            {
                s[i] = odd.back();
                odd.pop_back();
            }
        return stoi(s);
    }
};
