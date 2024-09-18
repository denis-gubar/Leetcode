class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int N = hand.size();
        if (N % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        hand.push_back(1 << 30);
        int balance = 0, prev = -1, count = 0;
        queue<int> Q;
        for (int x : hand)
        {
            if (x == prev)
                ++count;
            else
            {
                if (balance > count)
                    return false;
                for(int k = count; k > balance; --k)
                    Q.push(prev + groupSize - 1);
                balance = count;
                count = 1;
                while (!Q.empty() && Q.front() == prev)
                {
                    Q.pop();
                    if (--balance < 0)
                        return false;
                }
                prev = x;
            }            
        }
        return Q.empty();
    }
};
