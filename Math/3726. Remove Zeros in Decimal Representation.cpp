class Solution {
public:
    string replace_all(const string s, const string& what, const string& to)
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
    long long removeZeros(long long n) {
        return stoll(replace_all(to_string(n), "0", ""));
    }
};
