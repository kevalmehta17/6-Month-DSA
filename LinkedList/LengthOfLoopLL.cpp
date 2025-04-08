// Optimal approach:-

// tortose and haire algorithm:- Use two pointers, one moving at twice the speed of the other.
// Time Complexity:- O(n)
// Space Complexity:- O(1)

class Solution {
    public:
      // Function to find the length of a loop in the linked list.
      
      int findLength(Node* slow, Node* fast){
          int cnt = 1;
          fast = fast->next;
          while(slow != fast){
              cnt++;
              fast = fast->next;
          }
          return cnt;
      }
      
      int countNodesinLoop(Node *head) {
          // Code here
          if(!head || !head->next) return 0;
          
          Node* slow = head;
          Node* fast = head;
          // Node* temp = head;
          
          while(fast && fast->next){
              slow = slow->next;
              fast = fast->next->next;
              if(slow == fast){
                  return findLength(slow,fast);
              }
          }
          return 0;
          
          
      }

//Brute Force :- Use the hashing technique to store the address of the node in a hash table.
// Time Complexity:- O(n)
// Space Complexity:- O(n)
// Steps:- 1)take unordered_map to store the address of the node
//        2) Traverse the linked list and check if the address of the node is already present in the hash table or not. 
//        3) If it is present then return the length of the loop else insert the address of the node in the hash table and move to the next node.
//        4) If the end of the linked list is reached then return 0.

#include <unordered_map>

class Solution {
public:
    int countLoopLength(Node* head) {
        std::unordered_map<Node*, int> nodemap;
        Node* current = head;
        int cnt = 0;

        while (current) {
            if (nodemap.find(current) != nodemap.end()) {
                return cnt - nodemap[current]; // Loop detected
            } else {
                nodemap[current] = cnt; // Store address with index
                current = current->next;
                cnt++;
            }
        }

        // No loop found
        return 0;
    }
};
