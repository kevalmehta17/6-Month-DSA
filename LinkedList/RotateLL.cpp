// Leetcode :- 61. Rotate List
// Approach :
// 1. Find the length of the linked list and the tail node.
// 2. If k is greater than the length, calculate k modulo length to handle cases where k is larger than the list size.
// 3. Find the (length - k)th node, which will be the new tail after rotation.
// 4. Set the next pointer of the new tail to null to break the list.
// 5. Connect the old tail to the head to form a circular list.
// 6. Set the new head to the (length - k + 1)th node, which will be the new head after rotation.
// 7. Return the new head of the rotated linked list.
// 8. The time complexity is O(n) and the space complexity is O(1).
// 9. The algorithm uses two pointers to traverse the list and perform the rotation in a single pass.
// Time Complexity:- O(n) where n is the length of the linked list.
// Space Complexity:- O(1) as we are not using any extra space except for the dummy node.
class Solution {
    public:
    
        ListNode* findLast(ListNode* temp, int k){
            int cnt = 0;
            while(temp){
                cnt++;
                if(cnt == k){
                    ListNode* lastNode = temp;
                    return lastNode;
                }
                temp = temp->next;
            }
            return temp;
    
        }
    
        ListNode* rotateRight(ListNode* head, int k) {
            
            if(!head || !head->next || k== 0) return head;
    
            // First we have to find the tail of the LL
            ListNode* tail =  head;
            ListNode* temp = head;
            int len = 1;
    
            while(tail->next){
                len++;
                tail = tail->next;
            }
    
            if(k % len == 0) return head;
    
            k = k % len;
    
            // Now we have to find the lastNode 
            ListNode* lastNode = findLast(temp, len-k);
            
            // We need to connect the tail with the head & newHead is lastNode->next
            ListNode* newHead = lastNode->next;
            tail->next  =  head;
            lastNode->next = nullptr;
            return newHead;
    
        }
    };