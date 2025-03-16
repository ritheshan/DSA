
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
    public:
        bool hasCycle(ListNode *head) {
           ListNode *slow = head, *fast = head;
            
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;         // Move one step
                fast = fast->next->next;   // Move two steps
                
                if (slow == fast) {        // Cycle detected
                    return true;
                }
            }
            
            return false;  
        }
    };

    // another approach is to use a hash set to store the addresses of the nodes we have visited.#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        while (head != NULL) {
            if (visited.find(head) != visited.end()) {
                return true; // Cycle detected
            }
            visited.insert(head);
            head = head->next;
        }

        return false; // No cycle
    }
};