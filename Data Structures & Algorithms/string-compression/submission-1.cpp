class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), k = 0, i = 0;

        while (i < n) {
            chars[k++] = chars[i];
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            if (j - i > 1) {
                string cnt = to_string(j - i);
                for (char c : cnt) {
                    chars[k++] = c; //no extra space since length <= chars required
                }
            }
            i = j;
        }

        return k;
    }
};