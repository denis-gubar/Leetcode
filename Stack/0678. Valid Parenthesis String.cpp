class Solution {
public:
    bool checkValidString(string s) {
        int minBalance = 0, maxBalance = 0;
        for(char c: s)
        {
            switch(c)
            {
                case('('):
                    ++minBalance;
                    ++maxBalance;
                    break;
                case(')'):
                    if (--minBalance < 0)
                        minBalance = 0;
                    if (--maxBalance < 0)
                        return false;
                    break;
                case('*'):
                    if (--minBalance < 0)
                        minBalance = 0;
                    ++maxBalance;
                    break;
            }
        }
        return minBalance <= 0;
    }
};