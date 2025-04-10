// Optimal Approach:-
// Steps:-
// 1. Create a dummy node to help with the merging process.
// 2. Use a pointer to keep track of the current position in the merged list.
// 3. Compare the values of the nodes in the two lists and append the smaller one to the merged list.
// 4. Move the pointer in the list from which the node was taken to the next node.  
// 5. Repeat steps 3 and 4 until one of the lists is empty.
// 6. Append the remaining nodes of the non-empty list to the merged list.
// 7. Return the merged list starting from the node next to the dummy node.
// Time Complexity:- O(n+m) where n and m are the lengths of the two lists respectively.
// Space Complexity:- O(1) as we are not using any extra space except for the dummy node.
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
            ListNode* dummyNode = new ListNode(-1);
            // This will help to iterate
            ListNode* current = dummyNode;
    
            ListNode* l1 = list1;
            ListNode* l2 = list2;
    
            while(l1 && l2){
    
                // check for l1 < l2
    
                if(l1->val < l2->val){
                    current->next = l1;
                    current = l1;
                    l1 = l1->next;
                }
                // check for l1 > l2
                else if(l1->val > l2->val){
                    current->next = l2;
                    current = l2;
                    l2 = l2->next;
                }
                // check for l1 == l2
                else{
                    current->next = l1;
                    l1 = l1->next;
                    current = current->next;
    
                    current->next = l2;
                    l2 = l2->next;
                    current = current->next;
                }
            }
            // IF any LinkedList break the loop so remaining nodes connected to the current
            if(l1) current->next = l1;
            else current->next = l2;
    
            return dummyNode->next;
        }
    };