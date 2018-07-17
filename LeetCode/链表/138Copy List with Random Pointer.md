# 138 Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.



## 解

### 方法一

参考： https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)

An intuitive solution is to keep a hash table for each node in the list, via which we just need to iterate the list in 2 rounds respectively to create nodes and assign the values for their random pointers. As a result, the space complexity of this solution is `O(N)`, although with a linear time complexity.

使用hash 表的算法分为两步：

- 1) 遍历一遍，将不要 random 指针的先copy 一份，然后将遍历到的节点顺道添加到 hash table 里。
- 2) 遍历第二遍，将查找到的每个节点的 random 指向添上；

注意： 指针出了当前作用域还能使用；

这种方法要求链表中的值不能重复；

```cpp

```









As an optimised solution, we could reduce the space complexity into constant. **\*The idea is to associate the original node with its copy node in a single linked list. In this way, we don't need extra space to keep track of the new nodes.***

The algorithm is composed of the follow three steps which are also 3 iteration rounds.

1. Iterate the original list and duplicate each node. The duplicate
   of each node follows its original immediately.
2. Iterate the new list and assign the random pointer for each
   duplicated node.
3. Restore the original list and extract the duplicated nodes.

The algorithm is implemented as follows:

```java
public RandomListNode copyRandomList(RandomListNode head) {
	RandomListNode iter = head, next;

	// First round: make copy of each node,
	// and link them together side-by-side in a single list.
	while (iter != null) {
		next = iter.next;

		RandomListNode copy = new RandomListNode(iter.label);
		iter.next = copy;
		copy.next = next;

		iter = next;
	}

	// Second round: assign random pointers for the copy nodes.
	iter = head;
	while (iter != null) {
		if (iter.random != null) {
			iter.next.random = iter.random.next;
		}
		iter = iter.next.next;
	}

	// Third round: restore the original list, and extract the copy list.
	iter = head;
	RandomListNode pseudoHead = new RandomListNode(0);
	RandomListNode copy, copyIter = pseudoHead;

	while (iter != null) {
		next = iter.next.next;

		// extract the copy
		copy = iter.next;
		copyIter.next = copy;
		copyIter = copy;

		// restore the original list
		iter.next = next;

		iter = next;
	}

	return pseudoHead.next;
}
```

不需要dummy 头节点的版本：

```cpp
public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) 
            return head;
        
        RandomListNode cur = head;
        
        while (cur != null) {
            RandomListNode next = cur.next;
            cur.next = new RandomListNode(cur.label);
            cur.next.next = next;
            cur = next;
        }
        
        cur = head;
        
        while (cur != null) {
            if (cur.random != null)
                cur.next.random = cur.random.next;
            
            cur = cur.next.next;
        }
        
        cur = head;
        RandomListNode copyHead = head.next;
        RandomListNode copyIter = copyHead;
        
        while (cur != null) {
            RandomListNode next = cur.next.next;
            RandomListNode copyNext = next == null ? null : next.next;
            
            cur.next = next;
            copyIter.next = copyNext;
            
            copyIter = copyIter.next;
            cur = cur.next;
        }
        
        return copyHead;
    }
```

