// LeetCode Problem 328

// Optimal Approach:- 
// 1. Create two pointers, one for odd indexed nodes and one for even indexed nodes.
// 2. Traverse the linked list and add the odd indexed nodes to the odd pointer and even indexed nodes to the even pointer.
// 3. At the end, connect the last node of the odd indexed nodes to the first node of the even indexed nodes.
class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
           if(!head || !head->next) return head;
    
           ListNode* odd = head;
           ListNode* even = head->next;
           ListNode* evenhead = even;
    
           while(even && even->next){
    
            odd->next = odd->next->next;
            even->next = even->next->next;
    
            // Move the odd/even for pointing another odd/even node
            odd = odd->next;
            even = even->next;
           }
            //Now points the last node of head to the evenhead so that it complete
            odd->next = evenhead; 
            return head;
    
        }
    };



//Brute Force Approach:-                      
// 1. Create a new linked list and add the odd indexed nodes first and then the even indexed nodes.
// 2. Return the new linked list.
// 3. Time Complexity: O(n) and Space Complexity: O(n)
// 4. This is not an optimal solution as we are using extra space for the new linked list.
// class Solution {
//     public:
//         ListNode* oddEvenList(ListNode* head) {
//             if(!head || !head->next) return head;
    
//             ListNode* dummyNode = new ListNode(0);
//             ListNode* current = dummyNode;
//             ListNode* temp = head;
            
//             while(temp){
//                 ListNode* newNode = new ListNode(temp->val);
//                 current->next = newNode;
//                 current = current->next;
//                 if(temp->next) temp = temp->next->next;
//                 else break;
//             }
//             ListNode* evenIndex = head->next;
//             while(evenIndex){
//                 ListNode* newNode = new ListNode(evenIndex->val);
//                 current->next = newNode;
//                 current = current->next;
//                 if(evenIndex->next) evenIndex = evenIndex->next->next;
//                 else break;
//             }
//             return dummyNode->next;
//         }
//     };