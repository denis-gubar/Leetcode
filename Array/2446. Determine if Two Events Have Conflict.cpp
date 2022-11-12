class Solution {
public:
    string calc(int hh, int mm)
    {
        return to_string(100 + hh).substr(1) + ":" + to_string(100 + mm).substr(1);
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        bool flag1 = false;
        bool flag2 = false;
        for (int i = 0; i < 1440; ++i)
        {
            int hh = i / 60;
            int mm = i % 60;
            if (calc(hh, mm) == event1[0])
                flag1 = true;
            if (calc(hh, mm) == event2[0])
                flag2 = true;
            if (flag1 && flag2)
                return true;
            if (calc(hh, mm) == event1[1])
                flag1 = false;
            if (calc(hh, mm) == event2[1])
                flag2 = false;
        }
        return false;
    }
};
