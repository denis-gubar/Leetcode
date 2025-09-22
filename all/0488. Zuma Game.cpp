class Solution {
public:
    int findMinStep(string board, string hand) {
        int const N = board.size(), H = hand.size();
        int result = H + 1;
        string s;
        s.reserve(2 * N);
        char prev = board[0];
        int count = 0;
        board += '$';
        for (char c : board)
            if (prev == c)
                ++count;
            else
                s += prev, s += '0' + count, prev = c, count = 1;
        string current(s);
        count = 0;
        sort(hand.begin(), hand.end());
        auto dfs = [&](this const auto& self, int i) -> int
            {
                if (current.empty())
                    return i;
                if (i == H)
                    return H + 1;
                int result = H + 1;
                char const& c = hand[i];
                for (int j = 0; j < current.size(); j += 2)
                {
                    string temp(current);
                    if (c == current[j])
                    {
                        current[j + 1] = (current[j + 1] - '0' + 1) % 3 + '0';
                        auto it = current.begin() + j;
                        while (true)
                        {
                            if (it[1] == '0')
                            {
                                it = current.erase(it, it + 2);
                                if (it != current.begin())
                                    --(--it);
                            }
                            if (it == current.end() || it + 2 == current.end() || it[0] != it[2])
                                break;
                            int sum = (it[1] - '0') + (it[3] - '0');
                            if (sum > 2)
                                sum = 0;
                            it[1] = sum + '0';
                            current.erase(it + 2, it + 4);
                        }
                        result = min(result, self(i + 1));
                    }
                    else if (current[j + 1] == '2' && count == 0)
                    {
                        count = 1;
                        current[j + 1] = '1';
                        string z;
                        z += c;
                        z += '1';
                        z += current[j];
                        z += '1';
                        current.insert(current.begin() + j + 2, z.begin(), z.end());
                        result = min(result, self(i + 1));
                        count = 0;
                    }
                    current = temp;
                }
                return result;
            };
        do
        {
            current = s;
            result = min(result, dfs(0));
        } while (next_permutation(hand.begin(), hand.end()));
        if (result > H)
            result = -1;
        return result;
    }
};
