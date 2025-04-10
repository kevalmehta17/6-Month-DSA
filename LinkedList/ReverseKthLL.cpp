// Leetcode : 25. Reverse Nodes in k-Group
//Approach :
// 1. Traverse the linked list in groups of k nodes and reverse each group of k nodes.
// 2. If the number of nodes in the last group is less than k, leave them as they are.
// 3. Connect the reversed groups together to form the final modified linked list.  
// 4. Return the new head of the modified linked list.
// 5. Use a helper function to reverse the linked list and another helper function to get the kth node from the current position.
// 6. Use a pointer to keep track of the previous group's tail and connect it to the new head of the reversed group.
// 7. Update the head pointer to point to the new head of the modified linked list after processing all groups.
// 8. Return the new head of the modified linked list.
// 9. The time complexity is O(n) and the space complexity is O(1).
class Solution {
    public:
        ListNode* getKNode(ListNode* temp, int k) {
            int cnt = 0;
            while (temp) {
                cnt++;
                if (cnt == k) return temp;
                temp = temp->next;
            }
            return nullptr;
        }
    
        ListNode* reverseLL(ListNode* temp) {
            if (!temp || !temp->next) return temp;
            ListNode* prevNode = nullptr;
            while (temp) {
                ListNode* nextN = temp->next;
                temp->next = prevNode;
                prevNode = temp;
                temp = nextN;
            }
            return prevNode;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (!head || !head->next || k == 1) return head;
    
            ListNode* temp = head;
            ListNode* prev = nullptr;
    
            while (temp) {
                ListNode* kthNode = getKNode(temp, k);
                if (!kthNode) {
                    if (prev) prev->next = temp;
                    break;
                }
    
                ListNode* nextNode = kthNode->next;
                kthNode->next = nullptr;
    
                // 🔥 Store the new head of reversed group
                ListNode* reversedHead = reverseLL(temp);
    
                if (temp == head) {
                    head = reversedHead;
                } else {
                    prev->next = reversedHead;
                }
    
                prev = temp;      // temp is now the tail of reversed group
                temp = nextNode;  // move to next group
            }
    
            return head;
        }
    };
    