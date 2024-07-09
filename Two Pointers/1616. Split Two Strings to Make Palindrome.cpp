class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int const N = a.size();
        int left = 0, right = N - 1;
        while (left < right)
            if (a[left] == b[right])
                ++left, --right;
            else
                break;
        int L = left, R = right;
        while (left < right)
            if (b[left] == b[right])
                ++left, --right;
            else
                break;
        if (left >= right)
            return true;
        left = L, right = R;
        while (left < right)
            if (a[left] == a[right])
                ++left, --right;
            else
                break;
        if (left >= right)
            return true;
        left = 0, right = N - 1;
        while (left < right)
            if (b[left] == a[right])
                ++left, --right;
            else
                break;
        L = left, R = right;
        while (left < right)
            if (b[left] == b[right])
                ++left, --right;
            else
                break;
        if (left >= right)
            return true;
        left = L, right = R;
        while (left < right)
            if (a[left] == a[right])
                ++left, --right;
            else
                return false;
        return true;
    }
};
