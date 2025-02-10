class Solution {
public:
    int maxDifference(string s) {
        int odd = 0, even = 1000;
        for (char c = 'a'; c <= 'z'; ++c)
        {
            int count = 0;
            for (char x : s)
                if (x == c)
                    ++count;
            if (count == 0)
                continue;
            if (count % 2 == 0 && even > count)
                even = count;
            if (count % 2 == 1 && odd < count)
                odd = count;
        }
        return odd - even;
    }
};
