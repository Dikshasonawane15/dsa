class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int index, int parts, string curr) {
        if (parts == 4 && index == s.size()) {
            curr.pop_back(); // remove last '.'
            ans.push_back(curr);
            return;
        }

        if (parts == 4 || index == s.size())
            return;

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string segment = s.substr(index, len);

            if (segment.size() > 1 && segment[0] == '0')
                break;

            int num = stoi(segment);
            if (num > 255)
                break;

            backtrack(s, index + len, parts + 1,
                      curr + segment + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return ans;
    }
};