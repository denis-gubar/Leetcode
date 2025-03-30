class Solution {
public:
    string predictPartyVictory(string senate) {
        int const N = senate.size();
        deque<char> Q(senate.begin(), senate.end());
        Q.push_back('#');
        int dBlocked = 0, rBlocked = 0;
        int dCount = 0, rCount = 0;
        while (true)
        {
            if (Q.front() == 'R')
            {
                if (rBlocked > 0)
                    --rBlocked;
                else
                    ++rCount, ++dBlocked, Q.push_back('R');
            }
            else if (Q.front() == 'D')
            {
                if (dBlocked > 0)
                    --dBlocked;
                else
                    ++dCount, ++rBlocked, Q.push_back('D');
            }
            else
            {
                if (dCount == 0)
                    return "Radiant";
                if (rCount == 0)
                    return "Dire";
                dCount = 0, rCount = 0, Q.push_back('#');
            }
            Q.pop_front();
        }
    }
};
