// Leetcode 19. Remove Nth Node From End of List

// Optimal Approach:-
// 1. Use two pointers, fast and slow
// 2. Move the fast pointer n steps ahead
// 3. Move both pointers until the fast pointer reaches the end of the list
// 4. The slow pointer will be at the (len - n)th node
// 5. Remove the next node of the slow pointer
// Understanding :- here why we have to move fast pointer n steps ahead is because we want to find the (len - n)th node, so we need to move the fast pointer n steps ahead of the slow pointer. When the fast pointer reaches the end of the list, the slow pointer will be at the (len - n)th node
// 6. Return the head node
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(!head) return head;
            ListNode* fast = head;
            ListNode* slow = head;
    
            for(int i = 0; i<n; i++){
                if(fast) fast = fast->next;
            }
            if(!fast){
                return head->next;
            }
            while(fast->next){
                slow = slow->next;
                fast = fast->next;
            }
           
            ListNode* deleteNode = slow->next;
            slow->next = slow->next->next;
            delete deleteNode;
            return head;
        }
    };

// Brute Force Approach:-
// 1. Count the number of nodes in the linked list
// 2. IF cnt == n, then remove the head node and return the new head
// 3. Else, traverse the list again to find the (cnt - n)th node and remove the next node
// 4. Return the head node
// Time Complexity: O(2n) = O(n) => O(len N) + O(len - N) 
// Space Complexity: O(1)
// class Solution {
//     public:
//         ListNode* removeNthFromEnd(ListNode* head, int n) {
//             if(!head) return head;
//             int cnt = 0;
//             ListNode* temp = head;
    
//             while(temp){
//                 cnt++;
//                 temp = temp->next;
//             }
//             // If N is on head
//             if(cnt == n){
//                 ListNode* deletehead = head;
//                 head = head->next;
//                 delete deletehead;
//                 return head;
//             }
//             int result = cnt - n;
//             temp = head;
//             while(temp){
//                 result--;
//                 if(result == 0) break;
//                 temp = temp->next;
//             }
//             ListNode* deletetemp = temp->next;
//             temp->next = temp->next->next;
//             delete deletetemp;
//             return head;
    
//         }
//     };