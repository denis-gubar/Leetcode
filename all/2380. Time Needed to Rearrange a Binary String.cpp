class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int N = s.size();
        int result = 0;
        deque<char> D(s.begin(), s.end());
        char prev = 'z';
        while (true)
        {
            while (!D.empty() && D.front() == '1')
                D.pop_front();
            deque<char> next;
            bool isFinished = true;
            for(char d : D)
                if (d == '0')
                {
                    next.push_back('0');
                    prev = '0';
                }
                else
                {
                    if (prev == '1')
                    {
                        next.push_back('1');
                        continue;
                    }
                    if (!next.empty() && next.back() == '0')
                    {
                        next.back() = '1';
                        next.push_back('0');
                        isFinished = false;
                    }
                    prev = '1';
                }
            if (isFinished)
                break;
            ++result;
            D = next;
        }
        return result;
    }
};
