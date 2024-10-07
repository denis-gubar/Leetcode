class Solution {
public:
    int findNthDigit(long long N) {
        long long count = 9, size = 1;
        long long total = 0;
        while (true)
        {
            if (total + count * size >= N)
                break;
            total += count * size;
            count *= 10, ++size;
        }
        if (total + count * size == N)
            return 9;
        int x = count / 9 + (N - total + size - 1) / size - 1;
        int d = (N - total - 1) % size;
        return to_string(x)[d] - '0';
    }
};
