class Solution {
public:
    int countOddLetters(int N) {
        vector<string> digits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        int result = 0;
        string buffer;
        buffer.reserve(1'000);
        while(N > 0)
        {
            string t = digits[N % 10];
            N /= 10;
            buffer = t + buffer;
        }
        unordered_map<char, int> M;
        for(char c : buffer)
            ++M[c];
        for(auto [key, value] : M)
            if  (value % 2 == 1)
                ++result;
        return result;
    }
};