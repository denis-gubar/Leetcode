class Solution {
public:
    int countTime(string time) {
        int result = 0;
        for (int i = 0; i < 1440; ++i)
        {
            int mm = i % 60;
            int hh = i / 60;
            string x = to_string(100 + hh).substr(1) + ":" + to_string(100 + mm).substr(1);
            bool isOk = true;
            for (int j = 0; j < 5; ++j)
                if (x[j] != time[j] && time[j] != '?')
                    isOk = false;
            result += isOk;
        }
        return result;
    }
};
