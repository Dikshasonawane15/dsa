class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool exponentSeen = false;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                digitSeen = true;
            }
            else if (ch == '+' || ch == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (ch == '.') {
                if (dotSeen || exponentSeen)
                    return false;
                dotSeen = true;
            }
            else if (ch == 'e' || ch == 'E') {
                if (exponentSeen || !digitSeen)
                    return false;

                exponentSeen = true;
                digitSeen = false; // Need digits after e/E
            }
            else {
                return false;
            }
        }

        return digitSeen;
    }
};