// Optimal Approach :-
// approach :-
// 1. Find the middle of the linked list using the Tortoise and Hare algorithm (slow and fast pointers).
// 2. Reverse the second half of the linked list starting from the middle node.
// 3. Compare the first half of the linked list with the reversed second half node by node.
// 4. If all nodes match, the linked list is a palindrome; otherwise, it is not.

// Time complexity :- / Step 1: Find middle → O(n/2)
// Step 2: Reverse second half → O(n/2)
// Step 3: Compare both halves → O(n/2) : -- O(n)
// Space complexity :- O(1) (no extra space used)
class Solution { 
    public:
        bool isPalindrome(ListNode* head) {


        if(!head || !head->next) return head;

                // Tontaise and Hare alog to reach middle of Element
                ListNode* slow = head;
                ListNode* fast = head;

                while(fast && fast->next){
                    slow = slow->next;
                    fast = fast->next->next;
                }
                // After reach to middle reverse the LL from middle node

                ListNode* prev = nullptr;
                while(slow){
                    ListNode* nextNode = slow->next;
                    slow->next = prev;
                    prev = slow;
                    slow = nextNode;
                }
        // After reversing LL start comparing value/data

            ListNode* left = head;
            ListNode* right  = prev; //new head

            while(right){
                if(left->val != right->val){
                    return false;
                }
                left = left->next;
                right = right->next;
            }
            return true;
        }
    };




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
