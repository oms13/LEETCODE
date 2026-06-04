class Solution {
public:
  int myAtoi(string s) {
    int n = int(s.size());

    int64_t number = 0;
    char sign = '+';
    int i = 0;

    for (; i < n && s[i] == ' '; i++);  // Ignore leading whitespaces
    if (i == n) return 0;

    if (s[i] == '+') i++;
    else if (s[i] == '-') {             // Sign Detection
      i++;
      sign = '-';
    }

    for (; i < n && s[i] == '0'; i++);  // Ignore leading zeros

    for (; i < n; i++) {
      int d = s[i] - '0';
      if (d < 0 || d > 9) {
        break ;
      }

      number = number * 10 + d;

      if (number > INT_MAX) {
        return (sign == '-' ? INT_MIN : INT_MAX);
      }
    }

    // check for the sign and return the number
    if (sign == '-') number = -number;
    return number;
  }
};