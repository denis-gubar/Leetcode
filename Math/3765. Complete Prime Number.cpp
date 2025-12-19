class Solution {
public:
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        for (int k = 2; k * k <= x; ++k)
            if (x % k == 0)
                return false;
        return true;
    }
    bool completePrime(int num) {
        string n = to_string(num);
        int const N = n.size();
        for(int i = 1; i <= N; ++i)
            if (!isPrime(stoi(n.substr(0, i))))
                return false;
        for (int i = 1; i < N; ++i)
            if (!isPrime(stoi(n.substr(i))))
                return false;
        return true;
    }
};
