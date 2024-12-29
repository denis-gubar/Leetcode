class Solution {
public:
    string answerString(string word, int numFriends) {
        string result;
        int const N = word.size();
        result = word.substr(0, N + 1 - numFriends);
        string_view sv(word);
        string rv(result);
        if (numFriends > 1)
            for (int i = 1, last = N - numFriends + 1; i < N; ++i, last = min(last + 1, N - 1))
                if (rv < sv.substr(i, last - i + 1))
                    rv = sv.substr(i, last - i + 1);
        return rv;
    }
};
