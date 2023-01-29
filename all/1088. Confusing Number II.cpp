static int confusingNumbers[2'000'000];
static int count_ = 0;

static array<int, 5> digits{ { 0, 1, 6, 8, 9 } };
static array<int, 10> A{ { 0, 1, 2, 3, 4, 5, 9, 7, 8, 6 } };

static bool check(int x)
{
    int n = x;
    int y = 0;
    while (n > 0)
    {
        y = y * 10 + A[n % 10];
        n /= 10;
    }
    return x != y;
}
static void calc(int length, int x = 0)
{
    if (check(x))
        confusingNumbers[count_++] = x;
    if (length == 9)
        return;
    for (int d : digits)
        if (x * 10 + d > 0)
        {
            calc(length + 1, x * 10 + d);
        }
}

static void init()
{
    if (count_ == 0)
    {
        memset(confusingNumbers, 0, sizeof(confusingNumbers));
        calc(0);
        confusingNumbers[count_++] = 1'000'000'000;
        sort(&confusingNumbers[0], &confusingNumbers[0] + count_);
    }
}

class Solution {
public:
    
    int confusingNumberII(int n) {
        init();
        return upper_bound(&confusingNumbers[0], &confusingNumbers[0] + count_, n) - &confusingNumbers[0];
    }
};
