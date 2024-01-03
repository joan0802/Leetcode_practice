class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        int n = 0;
        for(auto c: s) {
            if(c != ']') {
                st.push(c);
            }
            else {
                string tmp = "";
                string num = "";
                int n = 0;
                while(st.top() != '[') {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop(); // for '['
                while(!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }
                n = stoi(num);
                for(int i = 0; i < n; i++) {
                    for(auto t: tmp) {
                        st.push(t);
                    }
                }
            }
        }
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};