// Leetcode 452 :- 
// Add Two Numbers II
// Time Complexity: O(max(m, n)), where m and n are the lengths of the two linked lists
// Space Complexity: O(max(m, n)), for the stack space used to store the digits of the numbers
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            stack<int> s1, s2;
    
            // Fill the stacks
            while (l1) {
                s1.push(l1->val);
                l1 = l1->next;
            }
            while (l2) {
                s2.push(l2->val);
                l2 = l2->next;
            }
    
            ListNode* result = nullptr;
            int carry = 0;
    
            // Process addition
            while (!s1.empty() || !s2.empty() || carry) {
                int sum = carry;
    
                if (!s1.empty()) {
                    sum += s1.top();
                    s1.pop();
                }
                if (!s2.empty()) {
                    sum += s2.top();
                    s2.pop();
                }
    
                ListNode* newNode = new ListNode(sum % 10);
                newNode->next = result;
                result = newNode;
                carry = sum / 10;
            }
    
            return result;
        }
    };
    