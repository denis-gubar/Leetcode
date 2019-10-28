class Solution {
public:
    int numRabbits( vector<int>& answers ) {
        int N = answers.size();
        if (!N)
            return 0;
        if (N == 1)
            return answers[0] + 1;
        sort( answers.begin(), answers.end() );
        int result = 0;
        vector<int> colors;
        int count = -1;
        for (int i = 0; i < N; ++i)
        {
            if (count == -1 || count == answers[i - 1])
            {
                colors.push_back( answers[i] + 1 );
                count = 0;
            }
            else if (answers[i] != answers[i - 1])
            {
                colors.push_back( answers[i] + 1 );
                count = 0;
            }
            else
                ++count;
        }
        return accumulate( colors.begin(), colors.end(), 0 );
    }
};