class Solution {
public:
    bool canAliceWin(int n) {
        int next = 10;
        while (true)
        {
            if (n < next)
                return false;
            n -= next;
            --next;
            if (n < next)
                return true;
            n -= next;
            --next;
        }
    }
};
