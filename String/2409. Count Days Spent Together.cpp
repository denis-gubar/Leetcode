class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int result = 0;
        bool isAlice = false, isBob = false;
        for(int i = 0; i < 12; ++i)
            for (int j = 1; j <= months[i]; ++j)
            {
                string s = to_string(101 + i).substr(1) + "-" + to_string(100 + j).substr(1);
                if (s == arriveAlice)
                    isAlice = true;
                if (s == arriveBob)
                    isBob = true;
                result += isAlice && isBob;
                if (s == leaveAlice)
                    isAlice = false;
                if (s == leaveBob)
                    isBob = false;
            }
        return result;
    }
};
