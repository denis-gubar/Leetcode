class Solution {
public:
    string trimTrailingVowels(string s) {
        string vowels{"aeiou"};
        while(!s.empty() && vowels.find(s.back()) != string::npos)
            s.pop_back();
        return s;            
    }
};