// Optimal Approach :---------------------
// Steps:-
// 1. Create a new node for each node in the original list and insert it right after the original node.
// 2. Set the random pointer of the new node to point to the next node of the original node's random pointer.
// 3. Separate the new nodes from the original list to form the copied list.
// 4. Return the head of the copied list.
// Time Complexity: O(n)
// Space Complexity: O(1) for the extra space used in the new nodes
// Code:-
class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (!head) return nullptr;
    
            // 1st Pass: Insert copied nodes just after original nodes
            Node* curr = head;
            while (curr) {
                Node* copy = new Node(curr->val);
                copy->next = curr->next;
                curr->next = copy;
                curr = copy->next;
            }
    
            // 2nd Pass: Assign random pointers to copied nodes
            curr = head;
            while (curr) {
                if (curr->random)
                    curr->next->random = curr->random->next;
                curr = curr->next->next;
            }
    
            // 3rd Pass: Restore original list and extract copied list
            curr = head;
            Node* dummy = new Node(0);
            Node* copyCurr = dummy;
    
            while (curr) {
                Node* copy = curr->next;
                copyCurr->next = copy;
                copyCurr = copy;
    
                curr->next = copy->next;
                curr = curr->next;
            }
    
            return dummy->next;
        }
    };
    
// Brute Force :---------------------
// Steps:-
//Create mapping of Node to Node
//Create a copy of the Node and store it in the map
//Iterate through the original list and set the next and random pointers of the copied nodes using the map  
//Time Complexity: O(n)
//Space Complexity: O(n) for the map

// class Solution {
//     public:
//         Node* copyRandomList(Node* head) {
//             if (!head) return nullptr; // If the list is empty, return nullptr

//             unordered_map<Node*, Node*> nodeMap; // Create a map to store the mapping of original nodes to copied nodes
//             Node* current = head;

//             // First pass: Create copies of the nodes and store them in the map
//             while (current) {
//                 nodeMap[current] = new Node(current->val); // Create a new node with the same value
//                 current = current->next; // Move to the next node in the original list
//             }

//             current = head; // Reset current to the head of the original list

//             // Second pass: Set the next and random pointers for the copied nodes
//             while (current) {
//                 nodeMap[current]->next = nodeMap[current->next]; // Set the next pointer
//                 nodeMap[current]->random = nodeMap[current->random]; // Set the random pointer
//                 current = current->next; // Move to the next node in the original list
//             }

//             return nodeMap[head]; // Return the head of the copied list
//         }
//     };