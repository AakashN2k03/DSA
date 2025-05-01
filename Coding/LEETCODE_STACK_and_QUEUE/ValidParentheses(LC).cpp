// LEETCODE: 20. Valid Parentheses (STACK)

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

       for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);  // Push opening bracket
        } else {
            if (st.empty()) return false;  // No matching opening IF STARTING IISELF THE STRING CONTAINS },],) .eg : s="}]", then stack will be empty and returns false
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;  // Mismatch
            }
            st.pop();  // Matched, remove opening
        }
    }
    return st.empty();  // All brackets matched
}

};

//Time Complexity: O(n)
// Space Complexity: O(n)
