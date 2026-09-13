class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {};

        for (int digit : digits) {
            count[digit]++;
        }

        int answer = 0;

        for (int hundreds = 1; hundreds <= 9; hundreds++) {
            if (count[hundreds] == 0) continue;

            count[hundreds]--;

            for (int tens = 0; tens <= 9; tens++) {
                if (count[tens] == 0) continue;

                count[tens]--;

                for (int ones = 0; ones <= 8; ones += 2) {
                    if (count[ones] > 0) {
                        answer++;
                    }
                }

                count[tens]++;
            }

            count[hundreds]++;
        }

        return answer;
    }
};
