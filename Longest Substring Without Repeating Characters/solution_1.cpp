#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> lastIndex;

        int l = 0;
        int ans = 0;

        for(int r = 0; r < s.size(); r++) {

            if(lastIndex.find(s[r]) != lastIndex.end()
               && lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1;
            }
            lastIndex[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};