class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int currentValue = romanValues[s[i]];

            // Check for the subtractive case (e.g., IV, IX, XL, XC, CD, CM)
            if (i + 1 < n && currentValue < romanValues[s[i + 1]]) {
                total += (romanValues[s[i + 1]] - currentValue);
                i++; // Skip the next character as it's already processed
            } else {
                total += currentValue;
            }
        }
        return total;
    }
};