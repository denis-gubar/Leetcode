class Solution {
public:
    int compress(vector<char>& chars) {
        int pos = 0;
        char prev = chars[0];
        chars.push_back(0);
        int count = 0;
        for (char c : chars)
            if (c != prev)
            {
                chars[pos] = prev;
                ++pos;
                if (count > 1)
                {
                    string t{ to_string(count) };
                    for (char z : t)
                        chars[pos] = z, ++pos;
                    count = 1;
                }
                prev = c;
            }
            else
                ++count;
        chars.pop_back();
        return pos;
    }
};
