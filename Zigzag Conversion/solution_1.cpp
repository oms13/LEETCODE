class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (numRows == 1 || size <= numRows)
            return s;

        int i = 0, j = 0;
        bool down = true;
        string rows[numRows];
        while (i < size) {
            rows[j] += s[i];
            i++;
            if (down) {
                j++;
                if (j == numRows - 1)
                    down = false;
            } else {
                j--;
                if (j == 0)
                    down = true;
            }
        }
        string ans = "";
        for (int k = 0; k < numRows; k++) {
            ans += rows[k];
        }
        return ans;
    }
};