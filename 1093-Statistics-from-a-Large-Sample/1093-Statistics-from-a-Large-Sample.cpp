class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum = -1;
        double maximum = -1;
        double mean = 0;
        double median = 0;
        double mode = 0;

        long long totalCount = 0;
        long long totalSum = 0;

        int maxFrequency = 0;

        // Find minimum, maximum, mean, and mode
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                if (minimum == -1)
                    minimum = i;

                maximum = i;

                totalCount += count[i];
                totalSum += (long long)i * count[i];

                if (count[i] > maxFrequency) {
                    maxFrequency = count[i];
                    mode = i;
                }
            }
        }

        mean = (double)totalSum / totalCount;

        // Find median
        long long leftPos = (totalCount + 1) / 2;
        long long rightPos = (totalCount + 2) / 2;

        long long currentCount = 0;
        double leftValue = 0;
        double rightValue = 0;

        for (int i = 0; i < 256; i++) {
            if (count[i] == 0)
                continue;

            currentCount += count[i];

            if (currentCount >= leftPos && leftValue == 0) {
                leftValue = i;
            }

            if (currentCount >= rightPos) {
                rightValue = i;
                break;
            }
        }

        median = (leftValue + rightValue) / 2.0;

        return {minimum, maximum, mean, median, mode};
    }
};
