//
//  main.swift
//  reverseLinkedListSwift
//
//  Created by gmy on 2023/5/27.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
};

class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        var pre: ListNode?
        var next: ListNode?
        var head1: ListNode? = head
        while (head1 != nil) {
            next = head1?.next
            head1?.next = pre
            pre = head1
            head1 = next
        }
        return pre
    }
};

let head = ListNode(0)
let node1 = ListNode(1)
head.next = node1
let node2 = ListNode(2)
node1.next = node2
let node3 = ListNode(3)
node2.next = node3
let node4 = ListNode(4)
node3.next = node4

var tmpHead: ListNode? = head;

while (tmpHead != nil) {
    print(tmpHead?.val)
    tmpHead = tmpHead?.next
}

var reverseHead: ListNode? = Solution().reverseList(head)

while (reverseHead != nil) {
    print(reverseHead?.val)
    reverseHead = reverseHead?.next
}
