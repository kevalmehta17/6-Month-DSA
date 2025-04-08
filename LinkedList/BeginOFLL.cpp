// Linked List Cycle II :- leetcode:-142
class Solution {
    public:
        // This function assumes slow and fast have met (cycle is confirmed)
        ListNode* findCycleStart(ListNode* head, ListNode* meetingPoint) {
            ListNode* entry = head;
            ListNode* current = meetingPoint;
    
            while (entry != current) {  
                entry = entry->next;
                current = current->next;
            }
    
            return entry;
        }
    
        ListNode* detectCycle(ListNode* head) {
            if (!head || !head->next) return nullptr;
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
    
                if (slow == fast) {
                    return findCycleStart(head, slow);
                }
            }
    
            return nullptr; // No cycle found
        }
    };