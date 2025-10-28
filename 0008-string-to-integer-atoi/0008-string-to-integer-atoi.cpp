class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long num = 0;
        bool negative = false;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            negative = (s[i] == '-');
            i++;
        }

        while (i < n && s[i] == '0') i++;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (!negative && num > INT_MAX) return INT_MAX;
            if (negative && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return negative ? -num : num;
    }
};