#include <iostream>
using namespace std;

  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution 
{
public:
    bool hasCycle(ListNode* head) 
    {
      // two nodes / pointers
      // fast moves 2 nodes
      // slow moves 1 node
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            // move one node
            slow = slow->next;

            // move two nodes
            fast = fast->next->next;

            // there is a cycle
            if (slow == fast)
            {
                return true;
            }
        }
        // if we make it to this point, return false
        return false;
    }
};

int main()
{
    Solution solution;

    ListNode negativeFour(-4);

    ListNode zero(0);
    zero.next = &negativeFour;

    ListNode two(2);
    two.next = &zero;

    ListNode head(3);
    head.next = &two;

    // wrap around to root
    negativeFour.next = &head;

    cout << "Example One : " << solution.hasCycle(&head);
	return 0;
}
