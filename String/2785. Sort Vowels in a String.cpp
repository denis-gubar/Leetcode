class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        string t;
        for (char c : s)
            if (vowels.find(c) != string::npos)
                t.push_back(c);
        sort(t.begin(), t.end());
        reverse(t.begin(), t.end());
        for (char& c : s)
            if (vowels.find(c) != string::npos)
                c = t.back(), t.pop_back();
        return s;
    }
};
