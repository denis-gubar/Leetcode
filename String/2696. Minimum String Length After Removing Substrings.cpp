class Solution {
public:
    string replace_all(const string& s, const string& what, const string& to)
    {
        string result;
        int start = 0;
        for (int finish = s.find(what); finish != string::npos; finish = s.find(what, start))
        {
            result.append(s, start, finish - start).append(to);
            start = finish + what.size();
        }
        result.append(s, start, s.size() - start);
        return result;
    }
    int minLength(string s) {
        for(int i = 0; i < 50; ++i)
        {
            s = replace_all(s, "AB", "");
            s = replace_all(s, "CD", "");
        }
        return s.size();
    }
};
