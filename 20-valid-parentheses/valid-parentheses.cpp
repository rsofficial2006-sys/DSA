class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            // opening bracket
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }

            // closing bracket
            else {
                if(st.empty()) {
                    return false;
                }

                if((s[i] == ')' && st.top() == '(') ||
                   (s[i] == ']' && st.top() == '[') ||
                   (s[i] == '}' && st.top() == '{')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // stack empty means all brackets matched
        if(st.empty()) {
            return true;
        }

        return false;
    }
};