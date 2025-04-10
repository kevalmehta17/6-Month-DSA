// Leetcode :- 148 Sort Linked List

// Optimal Approach:-
// We use the Merge Sort Algorithm to sort the linked list.
// Steps:- 
// 1. Find the middle of the linked list using the slow and fast pointer approach.
// 2. Recursively sort the left and right halves of the linked list.    
class Solution {
public:

       // Optimal Approach :- Merge Sort;
       // Time complexity :- o(n Logn)
       // Space Complexity:- o(logn) recurrsive stack

       // This is helper function to Merge the LinkedList
   ListNode* merge(ListNode* l1,ListNode* l2){
       
       ListNode* dummyNode = new ListNode(-1);
       ListNode* current = dummyNode;

         while (l1 && l2) {
           if (l1->val < l2->val) {
               current->next = l1;
               l1 = l1->next;
           } else {
               current->next = l2;
               l2 = l2->next;
           }
           current = current->next;
       }

       // If Loop break then remaining Node
       current->next = l1 ? l1 : l2;

       return dummyNode->next;
   }

   ListNode* sortList(ListNode* head) {

       if(!head || !head->next) return head;
       // Optimal Approach :- Merge Sort;

       ListNode* slow = head;
       ListNode* fast = head->next;

       while(fast && fast->next){
           
           slow = slow->next;
           fast = fast->next->next;
       }
       ListNode* mid = slow->next;
       slow->next = nullptr;

       ListNode* left = sortList(head);
       ListNode* right = sortList(mid);

       return merge(left, right);
   }
};


// Brute Force:-

class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            
            // Brute Force :---------------------
            // Push the nodes to the Array
    
            vector<int> values;
    
            ListNode* temp = head;
            while (temp != NULL) {
                values.push_back(temp->val);
                temp = temp->next;
            }

            // Sort the Array
            sort(values.begin(), values.end());

            // Push the sorted values back to the Linked List
            temp = head;
            for (int i = 0; i < values.size(); i++) {
                temp->val = values[i];
                temp = temp->next;
            }

            return head;   
        }
    };