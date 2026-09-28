class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";

        int i = 0;
        while (i < n) {
            s += chars[i];
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            if (j - i > 1) {
                s += to_string(j - i);
            }
            i = j;
        }

        for (i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};