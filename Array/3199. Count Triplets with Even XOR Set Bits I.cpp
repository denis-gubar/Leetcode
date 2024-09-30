class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int result = 0;
        int const N = a.size();
        for(int A : a)
            for(int B : b)
                for (int C : c)
                {
                    int count = 1, x = A ^ B ^ C;
                    while (x > 0)
                    {
                        x &= x - 1;
                        count = 1 - count;
                    }
                    result += count;
                }
        return result;
    }
};
