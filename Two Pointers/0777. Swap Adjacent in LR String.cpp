class Solution {
public:
    bool canTransform(string start, string end) {
        int const N = start.size();
        string a{ start }, b{ end };
        a.resize(remove(a.begin(), a.end(), 'X') - a.begin());
        b.resize(remove(b.begin(), b.end(), 'X') - b.begin());
        if (a != b)
            return false;
        vector<int> AL, AR, BL, BR;
        AL.reserve(N);
        AR.reserve(N);
        BL.reserve(N);
        BR.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            if (start[i] == 'L')
                AL.push_back(i);
            else if (start[i] == 'R')
                AR.push_back(i);
            if (end[i] == 'L')
                BL.push_back(i);
            else if (end[i] == 'R')
                BR.push_back(i);
        }
        for (int i = 0, posL = 0, posR = 0, M = a.size(); i < M; ++i)
        {
            if (a[i] == 'L')
            {
                if (AL[posL] < BL[posL])
                    return false;
                ++posL;
            }
            else
            {
                if (AR[posR] > BR[posR])
                    return false;
                ++posR;
            }
        }
        return true;
    }
};
