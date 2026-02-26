class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Iterate from right to left, stopping before the first digit
        for (int i = s.length() - 1; i > 0; i--) {
            int digit = (s[i] - '0') + carry;
            
            if (digit == 1) { 
                // It's odd (either 1+0 or 0+1)
                // We add 1 (1 step) then divide by 2 (1 step) = 2 steps
                steps += 2;
                carry = 1;
            } else {
                // It's even (either 0+0 or 1+1 with carry)
                // If it was 1+1, carry remains 1. If 0+0, carry remains 0.
                steps += 1;
            }
        }
        
        // Final check for the leftmost digit and the carry
        return steps + carry;
    }
};
