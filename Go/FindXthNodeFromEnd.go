package main

import (
	"fmt"
)

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) (*ListNode, *ListNode) {
	if len(v) == 0 {
		return nil, nil
	}

	if len(v) == 1 {
		pNode := &ListNode{v[0], nil}
		return pNode, pNode
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead, pCur
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
	}
	if pNode.next != nil {
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func FindNode(head *ListNode, x int) (*ListNode, int) {
	if head == nil {
		return head, 0
	}

	pNode, i := FindNode(head.next, x)
	if pNode != nil {
		return pNode, i
	}

	i++
	if i == x {
		return head, i
	}

	return nil, i
}

func XthNodeFromEnd(head *ListNode, x int) *ListNode {
	pNode, _ := FindNode(head, x)

	return pNode
}

func main() {
	for {
		fmt.Print("Number of nodes: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the list: ")
		pNode, _ := GetListFromArray(vec)

		fmt.Print("Please enter number x: ")
		var x int
		fmt.Scan(&x)

		p := XthNodeFromEnd(pNode, x)
		if p != nil {
			fmt.Printf("The %dth node form end of the linked list is ", x)
			fmt.Println(XthNodeFromEnd(pNode, x).data)
		} else {
			fmt.Printf("There are less than %d nodes in the list", x)
		}
	}
}
