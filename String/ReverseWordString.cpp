class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        string word = "";

        // Reverse the entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            // Build each word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            // Reverse the word and add to result
            reverse(word.begin(), word.end());
            if (!word.empty()) {
                if (!ans.empty()) {
                    ans += " "; // Add space between words
                }
                ans += word;
            }
            word = ""; // Clear word for next iteration
        }
        return ans;
    }
};
