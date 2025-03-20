class Solution {
public:
    string solveEquation(string equation) {
        string result;
        bool isLeft = true, isPositive = true;
        int K = 0, C = 0;
        equation += '=';
        string buffer;
        auto flush = [&buffer, &C, &isLeft, &isPositive]()
            {
                if (buffer.empty())
                    return;
                int deltaC = stoi(buffer);
                buffer.clear();
                C += (isPositive * 2 - 1) * (isLeft * 2 - 1) * deltaC;
            };
        for (char c : equation)
        {
            if (c == '=')
            {
                flush();
                isLeft = false;
                isPositive = true;
            }
            else if (c == 'x')
            {
                int deltaK = 1;
                if (!buffer.empty())
                    deltaK = stoi(buffer);
                buffer.clear();
                K += (isPositive * 2 - 1) * (isLeft * 2 - 1) * deltaK;
                isPositive = true;
            }
            else if (c == '-')
            {
                flush();
                isPositive = false;
            }
            else if (c == '+')
            {
                flush();
                isPositive = true;
            }
            else
                buffer += c;
        }
        if (K == 0 && C == 0)
            return "Infinite solutions";
        if (K == 0 && C != 0)
            return "No solution";
        return "x=" +  to_string(-C / K);
    }
};
