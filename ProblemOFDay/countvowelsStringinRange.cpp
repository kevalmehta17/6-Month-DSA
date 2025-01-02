class Solution {
public:

    bool isValidString(const string& word){
        unordered_set<char> vowels = {'a','e','i','o','u'};
        return vowels.count(word.front()) && vowels.count(word.back());
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) { 

        int n = words.size();
        vector<int> valid(n,0); //store the valid word
        vector<int> prefix(n,0); //prefix sum array

        //now check for the vowels

        for(int i = 0; i<n; i++){
            if(isValidString(words[i])){
                valid[i] = 1;
                //[1 ,0 ,1 ,1 ,1]
            }
        }
        //after finding valid, findout there prefixsum

        prefix[0] = valid[0]; //first ele always same

        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + valid[i];//findout sum till element
        }

        vector<int> ans;
        for(const auto& query : queries){
            int li = query[0];
            int ri = query[1];

            if(li>0){
                ans.push_back(prefix[ri] - prefix[li-1]);
            }
            else{
                ans.push_back(prefix[ri]);
            }
        }
        return ans;
        
    }
};