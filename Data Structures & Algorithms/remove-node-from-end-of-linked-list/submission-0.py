# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        total: int = 0
        curr: ListNode = head
        while curr:
            total += 1
            curr=curr.next
        
        if total == n:
            return head.next
        if total == 1:
            return None
        
        target:int = total - n
        k: int = 1
        curr = head
        while k<target:
            curr=curr.next
            k += 1
        
        curr.next = curr.next.next

        return head





