class Solution {
public:
    int maxOperations(string s) {
        int result = 0;
        int const N = s.size();
        vector<int> A;
        A.reserve(N);
        int last = -1, count = 0;
        for(int i = N - 1; i >= 0; --i)
            if (s[i] == '1')
            {
                if (last > -1)
                    ++count;
            }
            else
            {
                last = i;
                if (count > 0)
                    A.push_back(count);
                count = 0;
            }
        if (count > 0)
            A.push_back(count);
        int balance = 0;
        while (!A.empty())
            balance += A.back(), A.pop_back(), result += balance;
        return result;
    }
};
