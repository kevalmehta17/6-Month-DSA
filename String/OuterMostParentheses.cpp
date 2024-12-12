class Solution {
  public:
    string removeOuter(string& s) {
      string ans = "";
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Increment count but skip the outermost '('
                if (count > 0) ans.push_back(s[i]);
                count++;
            } else if (s[i] == ')') {
                count--;
                // Skip the outermost ')' but add others
                if (count > 0) ans.push_back(s[i]);
            }
        }
        
        return ans;
      
    }
};