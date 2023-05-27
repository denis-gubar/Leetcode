class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        auto isVowel = [](char c) -> bool
        {
            return string("aeuioAEUIO").find(c) != string::npos;
        };
        copy_if(s.begin(), s.end(), back_inserter(vowels), isVowel);
        for (char& c : s)
            if (isVowel(c))
                c = vowels.back(), vowels.pop_back();
        return s;
    }
};
