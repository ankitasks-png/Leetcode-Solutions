#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen; // character -> last index
        int maxLen = 0;
        int start = 0; // start of current window

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // If character was seen and is inside current window
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= start) {
                start = lastSeen[c] + 1; // move start right after duplicate
            }
            lastSeen[c] = i; // update last seen index
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
