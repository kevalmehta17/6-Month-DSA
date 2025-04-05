// Optimal Approach :-
// Using Two Pointers


// Brrute Force Approach :-
// Using Stack
// Time Complexity :- O(n)
// Space Complexity :- O(n) (due to stack)
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(!head || !head->next) return true; // Base case: empty or single node list
            ListNode* temp = head;
            stack<int> s;
            while(temp){
                s.push(temp->val);
                temp = temp->next;
            }
            temp = head;
            while(temp){
                if(s.top() != temp->val) return false;
                s.pop();
                temp  = temp->next;
            }
            return true;

        }
    };
