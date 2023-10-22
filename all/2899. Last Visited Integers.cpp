class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int N = words.size();
        vector<int> result;
        for(int i = 0; i < N; ++i)
        {
            if (words[i] == "prev")
            {
                int pos = i;
                int k = 0;
                bool flag = false;
                while (pos >= 0)
                    if (!flag)
                    {
                        if (words[pos] == "prev")
                            ++k;
                        else
                        {
                            flag = true;
                            continue;
                        }
                        --pos;
                    }
                    else
                    {
                        if (words[pos] != "prev")
                        {
                            --k;
                            if (k == 0)
                                break;
                        }
                        --pos;
                    }
                if (pos >= 0)
                    result.push_back(stoi(words[pos]));
                else
                    result.push_back(-1);
            }
        }
        return result;
    }
};
