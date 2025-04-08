// Optimal:- Tontoise and Hare 
// Steps:- 
// 1. Initialize two pointers, slow and fast, both pointing to the head of the linked list.
// 2. Move the slow pointer one step at a time and the fast pointer two steps at a time.
// 3. When the fast pointer reaches the end of the list (or goes beyond it), the slow pointer will be at the middle node of the list.
// 4. If the list has an even number of nodes, the slow pointer will point to the second middle node.

class Solution {
    public:
       ListNode* middleNode(ListNode* head) {
            if(!head || !head->next) return head;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
       }};
// Time Complexity: O(n) (traversing the linked list once)
// Space Complexity: O(1) (no extra space used)

// Brute Force
// Approach :-
// First pass: Traverse the linked list using a pointer temp to count the total number of nodes.
// Second pass: Start from head again, move cnt/2 steps forward to reach the middle node.
// Return the node where you land — that’s the middle.
// Time = O(n) + O(n/2) = O(n)
// Space = O(1) (no extra space used)

// class Solution {
//     public:
//         ListNode* middleNode(ListNode* head) {
//             ListNode* temp = head;
//             int cnt = 0; 

//             while(temp){
//                 cnt++;
//                 temp = temp->next;
//             }
//             int n = (cnt/2);
//             temp = head;
//             while(n--){
//                 temp = temp->next;
//             }
//             return temp;
//         }
//     };
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* temp = head;
//         int cnt = 0;
//         while(temp){
//             cnt++;
//             temp = temp->next;
//         }
//         int n = (cnt/2);
//         temp = head;

//         while(n){
//             n--;
//             temp = temp->next;
//         }
//         return temp;
//     }
// };