```cpp
class Solution {
public:
    string convert(string s, int numRows) {

        // If only one row, no zigzag is possible
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {

            // Add character to current row
            rows[currentRow] += c;

            // Change direction at top or bottom
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to next row
            if (goingDown) {
                currentRow++;
            } else {
                currentRow--;
            }
        }

        // Combine all rows
        string answer;

        for (string row : rows) {
            answer += row;
        }

        return answer;
    }
};
```
