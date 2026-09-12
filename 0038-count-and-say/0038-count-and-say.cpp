class Solution {
public:
    string countAndSay(int n) {

        string result = "1";

        for (int i = 2; i <= n; i++) {

            string next = "";

            int j = 0;

            while (j < result.length()) {

                int count = 0;
                char current = result[j];

                // Count consecutive identical characters
                while (j < result.length() && result[j] == current) {
                    count++;
                    j++;
                }

                // Append count followed by the digit
                next += to_string(count);
                next += current;
            }

            result = next;
        }

        return result;
    }
};

