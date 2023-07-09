class Solution {
public:
    int addMinimum(string word) {
        int result = 0;
        int N = word.size();
        char last = 'c';
        for (char c : word)
        {
            if (last == 'a')
            {
                if (c == 'a')
                    result += 2;
                else if (c == 'c')
                    ++result;
            }
            else if (last == 'b')
            {
                if (c == 'a')
                    ++result;
                else if (c == 'b')
                    result += 2;
            }
            else
            {
                if (c == 'b')
                    ++result;
                else if (c == 'c')
                    result += 2;
            }
            last = c;
        }
        if (last == 'b')
            ++result;
        else if (last == 'a')
            result += 2;
        return result;
    }
};
