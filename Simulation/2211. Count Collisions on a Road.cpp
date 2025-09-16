class Solution {
public:
    int countCollisions(string directions) {
        int result = 0;
        int const N = directions.size();
        string buffer;
        buffer.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            switch (directions[i])
            {
            case 'L':
                if (!buffer.empty())
                {
                    ++result;
                    while (!buffer.empty() && buffer.back() == 'R')
                        buffer.pop_back(), ++result;
                    if (buffer.empty())
                        buffer += 'S';
                }
                break;
            case 'S':
                while (!buffer.empty() && buffer.back() == 'R')
                    buffer.pop_back(), ++result;
                buffer += 'S';
                break;
            case 'R':
                buffer += 'R';
                break;
            }
        }
        return result;
    }
};
