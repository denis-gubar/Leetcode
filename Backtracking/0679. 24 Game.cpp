class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        string const operations{ "*+-/" };
        array<unsigned char, 3> A;
        do
        {
            for (unsigned char mask = 0; mask < 64; ++mask)
            {
                unsigned char x = mask;
                for (unsigned char k = 0; k < 3; ++k)
                    A[k] = operations[x & 3], x >>= 2;
                auto calc = [](double a, double b, char operation, double& result)->bool
                    {
                        switch (operation)
                        {
                        case '*':
                            result = a * b;
                            break;
                        case '+':
                            result = a + b;
                            break;
                        case '-':
                            result = a - b;
                            break;
                        case '/':
                            if (abs(b) > 1e-6)
                                result = a / b;
                            else
                                return false;
                            break;
                        default:
                            break;
                        }
                        return true;
                    };
                double current = -1, left = -1, right = -1;
                if (calc(cards[0], cards[1], A[0], current))
                    if (calc(current, cards[2], A[1], current))
                        if (calc(current, cards[3], A[2], current))
                            if (abs(current - 24) < 1e-6)
                                return true;
                if (calc(cards[0], cards[1], A[0], current))
                    if (calc(cards[2], cards[3], A[2], right))
                        if (calc(current, right, A[1], current))
                            if (abs(current - 24) < 1e-6)
                                return true;
                if (calc(cards[1], cards[2], A[1], current))
                    if (calc(cards[0], current, A[0], current))
                        if (calc(current, cards[3], A[2], current))
                            if (abs(current - 24) < 1e-6)
                                return true;

                if (calc(cards[1], cards[2], A[1], current))
                    if (calc(current, cards[3], A[2], current))
                        if (calc(cards[0], current, A[0], current))
                            if (abs(current - 24) < 1e-6)
                                return true;

                if (calc(cards[2], cards[3], A[2], current))
                    if (calc(cards[1], current, A[1], current))
                        if (calc(cards[0], current, A[0], current))
                            if (abs(current - 24) < 1e-6)
                                return true;
                if (calc(cards[0], cards[1], A[0], left))
                    if (calc(cards[2], cards[3], A[2], right))
                        if (calc(left, right, A[1], current))
                            if (abs(current - 24) < 1e-6)
                                return true;

            }
        } while (next_permutation(cards.begin(), cards.end()));
        return false;
    }
};
