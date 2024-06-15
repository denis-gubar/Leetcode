class Solution {
public:
    bool isValid(string word) {
        string const vowels = "aeoiu";
        string const digits = "0123456789";
        int N = word.size();
        if (N < 3)
            return false;
        string s(word);
        for (char& c : s)
            c = tolower(c);
        for (char c : s)
            if (!isalnum(c))
                return false;
        bool result = false;
        for (char c : s)
            result |= vowels.find(c) != string::npos;
        if (!result)
            return false;
        result = false;
        for (char c : s)
            if (c >= 'a' && c <= 'z' && vowels.find(c) == string::npos)
                result = true;
        return result;
    }
};
