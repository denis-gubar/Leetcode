class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool a = password.size() >= 8, b = false, c = false, d = false, e = false, f = true;
        for (char z : password)
        {
            b |= z >= 'a' && z <= 'z';
            c |= z >= 'A' && z <= 'Z';
            d |= z >= '0' && z <= '9';
            e |= string("!@#$%^&*()-+").find(z) != string::npos;
        }
        for (int i = 0; i + 1 < password.size(); ++i)
            f &= password[i] != password[i + 1];
        return a && b && c && d && e && f;
    }
};
