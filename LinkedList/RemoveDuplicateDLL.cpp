// Optimal Approach:-
// Question GFG :- Remove duplicates from a sorted doubly linked list
// Time Complexity :- O(n)
// Space Complexity :- O(1)

// Approach :-
// 1. Traverse the list and check if the current node's data is equal to the next node's data.
// 2. If they are equal, delete the next node and update the current node's next pointer to skip the deleted node.
// 3. If they are not equal, move to the next node.

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
       if(!head) return nullptr;
       
       Node* current = head;
       
       while(current && current->next){
           
           if(current->data == current->next->data){
            //   create the delete pointer
                Node* duplicateNode = current->next;
                current->next = duplicateNode->next;
                if(duplicateNode->next) duplicateNode->next->prev = current;
                delete duplicateNode;
           }
           else {
                current = current->next;
            }
       }
       return head;
    }
};
