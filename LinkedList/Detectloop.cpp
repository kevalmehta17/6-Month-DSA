
//141. Linked List Cycle

// Optimal Approch :- use Tontaise and hare algo

// Code:-
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            // Lets use the Totaise and hare Algo
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
    
                if(slow == fast){
                    return true;
                }
            }
            return false;
        }
    };
// Brute Force :- Use the hashing technique to store the address of the node in a hash table.
// Steps:- 1)take unordered_set to store the address of the node
//        2) Traverse the linked list and check if the address of the node is already present in the hash table or not.
//        3) If it is present then return true else insert the address of the node in the hash table and move to the next node.
// Time Complexity:- O(n)
// Space Complexity:- O(n)



class Solution {
    public:
        bool hasCycle(ListNode *head) {
    
            ListNode* temp = head;
            unordered_set<ListNode*> visited;
    
            while(temp){
                if(visited.find(temp) != visited.end()){
                    return true;
                }
                visited.insert(temp);
                temp = temp->next;
            }
            return false;
        }
    };