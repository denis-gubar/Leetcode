// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long a = 0, b = n;
        while(a + 1 < b)
        {
            int m = (a + b) / 2;
            if (isBadVersion(m))
                b = m;
            else
                a = m;            
        }
        return b;
    }
};