// Leetcode :- 2095
// Problem :- Delete the Middle Node of a Linked List

// Time Complexity:- O(n)
// Space Complexity:- O(1)
// Steps:- 1) Use the slow and fast pointer approach to find the middle node of the linked list.
//        2) Use the prev pointer to keep track of the previous node of the slow pointer.
//        3) When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle node of the linked list.
//        4) Now delete the middle node by using the prev pointer and return the head of the linked list.
//        5) If the linked list is empty or has only one node, return null.
class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            if(!head || !head->next) return nullptr;
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;
    
            while(fast && fast->next){
                
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            // Now after reaching the null
                prev->next = prev->next->next;
                slow->next = nullptr;
                delete slow;
            return head;
        }
    };