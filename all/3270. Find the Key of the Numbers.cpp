class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string result{ "::::" };
        string a{ to_string(num1) };
        string b{ to_string(num2) };
        string c{ to_string(num3) };
        while (a.size() < 4)
            a = '0' + a;
        while (b.size() < 4)
            b = '0' + b;
        while (c.size() < 4)
            c = '0' + c;
        for (int i = 0; i < a.size(); ++i)
            result[i] = min(result[i], a[i]);
        for (int i = 0; i < b.size(); ++i)
            result[i] = min(result[i], b[i]);
        for (int i = 0; i < c.size(); ++i)
            result[i] = min(result[i], c[i]);
        return stoi(result);
    }
};
