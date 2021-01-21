#include "lists.h"
/**
 *
 *
 *
 */
listint_t *find_listint_loop(listint_t *head)
{
  listint_t *fast, *slow;

  if ((!head || !(head->next)) || !(head->next->next))
    return (NULL);
  if (head->next->next == head)
  return (head);
  fast = head->next->next;
  slow = head;
while (fast && fast->next)
{
  if (fast == slow)
  break;
  slow = slow->next;
  fast = fast->next->next;
}
if (!fast || !(fast->next))
return (NULL);
if (slow == fast)
{
  fast = fast->next;
  while(fast != head)
  {
   while (fast != slow)
    fast = fast->next;
    head = head->next;
  }
  return (head);
}
}
