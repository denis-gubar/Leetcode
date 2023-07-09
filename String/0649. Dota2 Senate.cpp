class Solution {
public:
    static constexpr array results = { "Radiant", "Dire" };
    string predictPartyVictory(string senate) {
        bool result = false;
        string newSenate;
        int dBlocked = 0, rBlocked = 0;
        while(true)
        {
            int dCount = 0, rCount = 0;
            for (char c : senate)
            {
                if (c == 'R')
                {
                    if (rBlocked > 0)
                        --rBlocked;
                    else
                    {
                        ++rCount;
                        ++dBlocked;
                        newSenate.push_back('R');
                    }
                }
                else
                {
                    if (dBlocked > 0)
                        --dBlocked;
                    else
                    {
                        ++dCount;
                        ++rBlocked;
                        newSenate.push_back('D');
                    }
                }
            }
            if (dCount == 0)
                break;
            if (rCount == 0)
            {
                result = true;
                break;
            }
            senate = move(newSenate);
        }
        return results[result];
    }
};
