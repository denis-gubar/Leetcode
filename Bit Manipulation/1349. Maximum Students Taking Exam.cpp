static unsigned char F[8][256];
static unsigned char counts[256];
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        memset(counts, 0, sizeof(counts));
        for (unsigned short mask = 0; mask < 256; ++mask)
        {
            unsigned char x = mask;
            while (x)
                ++counts[mask], x &= x - 1;
        }
        unsigned char result = 0;
        int const N = seats.size(), M = seats[0].size();
        memset(F, 0, sizeof(F));
        auto update = [&result](unsigned char& x, unsigned char value)
            {
                if (x < value)
                    x = value, result = max(result, value);
            };
        vector<unsigned char> masks(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (seats[i][j] == '.')
                    masks[i] |= 1 << j;
        for (unsigned short mask = 0; mask < (1 << M); ++mask)
            if ((mask & masks[0]) == mask && (mask & (mask << 1)) == 0 && (mask & (mask >> 1)) == 0)
                update(F[0][mask], counts[mask]);
        for (int i = 1; i < N; ++i)
        {
            for (unsigned short mask = 0; mask < (1 << M); ++mask)
                for (unsigned short nmask = 0; nmask < (1 << M); ++nmask)
                    if ((nmask & (mask << 1)) == 0 && (nmask & (mask >> 1)) == 0 &&
                        (nmask & masks[i]) == nmask && (nmask & (nmask << 1)) == 0 && (nmask & (nmask >> 1)) == 0)
                        update(F[i][nmask], F[i - 1][mask] + counts[nmask]);
        }
        return result;
    }
};
