// GFG Problem: Flattening a Linked List
// Approach:
// 1. Traverse the linked list and merge each list with the next one using a helper function.
// 2. The helper function merges two sorted linked lists using the bottom pointers.
// 3. The merged list is then returned as the new head of the flattened linked list.
// 4. The time complexity is O(n*m) where n is the number of lists and m is the average length of each list.
// 5. The space complexity is O(1) as we are not using any extra space except for the dummy node.
// Recursive Approach:-
// flatten(5)
//  └── flatten(10)
//  └── flatten(19)
//       └── flatten(28) → returns 28 (base case)
//       ←─ merge(19, 28)
//  ←─ merge(10, merged)
// ←─ merge(5, merged)
// → return final flattened list

class Solution {
    public:
        // Merge two sorted linked lists using bottom pointers
        Node* merge(Node* list1, Node* list2) {
            Node* dummy = new Node(0);
            Node* curr = dummy;
    
            while (list1 && list2) {
                if (list1->data < list2->data) {
                    curr->bottom = list1;
                    list1 = list1->bottom;
                } else {
                    curr->bottom = list2;
                    list2 = list2->bottom;
                }
                curr = curr->bottom;
            }
    
            if (list1) curr->bottom = list1;
            else curr->bottom = list2;
    
            return dummy->bottom;
        }
    
       Node* flatten(Node* root) {
        // Base case: if root is NULL or only one list is present
        if (!root || !root->next) return root;
    
        // Recursively flatten the next list
        Node* flattenedNextList = flatten(root->next);
    
        // Merge current list with the flattened next list
        Node* mergedList = merge(root, flattenedNextList);
    
        // Return the merged (and now flattened) list
        return mergedList;
    }
    
    };