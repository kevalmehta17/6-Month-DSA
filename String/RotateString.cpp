class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths of s and goal are not the same, return false
        if (s.length() != goal.length()) {
            return false;
        }

        // Concatenate s with itself
        s += s;
        
        // Check if goal is a substring of the concatenated string
        return s.find(goal) != string::npos;
    }
};

// simple app
// class Solution {
// public:
//     bool rotateString(string s, string goal) {

//         int n = s.size();

//         for(int i = 0; i<n ; i++){

        
//             if(s == goal){
//                 return true;
//             }

//             char last = s.back(); // took the last of s
//             s.pop_back(); //now remove it from s
//             s = last + s; //build the new String
//         }
//     return false;
//     }
   
// };