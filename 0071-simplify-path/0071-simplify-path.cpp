class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";
        string ans = "";

        for (int i = 0; i < path.size(); i++) { // path ke ek ek charecter ko traverse krenge
            if (path[i] != '/') { // Agar '/' nahi hai to current folder name banao
                curr += path[i];
            }
            else {
                if (curr.empty()) { // Consecutive '/' ko ignore karo
                    // Ignore
                }
                else if (curr == ".") { // Current directory (.) ko ignore karo
                    // Ignore
                }
                else if (curr == "..") { // Parent directory (..) aaye to last valid folder hata do
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else {
                    st.push(curr);  // normal folder hai to stack me store kr do 
                }

                curr = "";
            }
        }

        // Process the last token (if any)
        // Agar last folder '/' se end nahi hua ho to usko bhi process karo
        if (!curr.empty()) {
            if (curr == ".") {
                // Ignore
            }
            else if (curr == "..") {  // parent directory aaye to last folder ko ignore krna 
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(curr);
            }
        }
        // Ab yahan se stack se answer banana hai.
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.empty()){
            return "/";
        }
        return ans;
    }
};