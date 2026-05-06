# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        curr: ListNode = head
        prev: ListNode = None
        nextNode: ListNode = curr

        while nextNode:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode

        head = prev

        return head

    def reorderList(self, head: Optional[ListNode]) -> None:
        slow: ListNode = head
        fast: ListNode = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        tail = self.reverseList(slow)

        curr: ListNode = head
        while tail.next != None:
            currTemp: ListNode = curr.next
            tailTemp: ListNode = tail.next

            curr.next = tail
            tail.next = currTemp

            curr = currTemp
            tail = tailTemp


            
# TC - O(n)
# SC - O(1) - auxilary space



