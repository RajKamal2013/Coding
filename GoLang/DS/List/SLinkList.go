package main

import "fmt"

type Node struct {
	val  interface{}
	next *Node
}

func newNode(val interface{}) *Node {
	return &Node{val, nil}
}

type LinkedList struct {
	head   *Node
	length int
}

func initLinkedList() *LinkedList {
	return &LinkedList{}
}

func (ll *LinkedList) prepend(data interface{}) {
	n := newNode(data)
	n.next = ll.head
	ll.head = n
	ll.length++
}

func (ll *LinkedList) append(data interface{}) {
	n := newNode(data)
	if ll.head == nil {
		ll.head = n
		ll.length++
		return
	}
	curr := ll.head
	for ; curr.next != nil; curr = curr.next {

	}
	curr.next = n
	ll.length++
}

func (ll *LinkedList) removeFront() interface{} {
	if ll.head == nil {
		return nil
	}

	curr := ll.head
	ll.head = ll.head.next
	ll.length--
	return curr.val
}

func (ll *LinkedList) removeBack() interface{} {
	if ll.head == nil {
		return nil
	}

	if ll.head.next == nil {
		curr := ll.head
		ll.head = nil
		ll.length--
		return curr.val
	}

	curr := ll.head
	for ; curr.next != nil; curr = curr.next {

	}

	ll.length--
	retVal := curr.next.val
	curr.next = nil
	return retVal
}

func (ll *LinkedList) size() int {
	return ll.length
}

func (ll *LinkedList) display() {
	curr := ll.head
	for ; curr != nil; curr = curr.next {
		fmt.Print(curr.val, " ")
	}
	fmt.Println()
}

func (ll *LinkedList) reverse() {
	if ll.head == nil {
		return
	}

	if ll.head.next == nil {
		return
	}

	var curr, rev, temp *Node
	curr = ll.head
	rev = nil
	temp = nil

	for curr != nil {
		temp = curr.next
		curr.next = rev
		rev = curr
		curr = temp
	}

	ll.head = rev
}

func (ll *LinkedList) insertAtN(index int, data interface{}) {
	if index < 0 || index > ll.length {
		fmt.Println("Insert: Index Out of Bound")
		return
	}

	if index == 0 {
		ll.prepend(data)
		return
	}

	if index == ll.length {
		ll.append(data)
		return
	}
	curr := ll.head

	for i := 0; i < index; i++ {
		curr = curr.next
	}
	n := newNode(data)
	n.next = curr.next
	curr.next = n
	ll.length++
	return
}

func (ll *LinkedList) removeAtN(index int) {
	if index < 0 || index > ll.length-1 {
		fmt.Println("Insert: Index Out of Bound")
		return
	}

	if index == 0 {
		ll.removeFront()
		return
	}

	if index == ll.length-1 {
		ll.removeBack()
		return
	}
	curr := ll.head
	var prev *Node

	for i := 0; i < index; i++ {
		prev = curr
		curr = curr.next
	}
	prev.next = curr.next
	ll.length--
}

func (ll *LinkedList) contains(data interface{}) bool {
	if ll.head == nil {
		return false
	}

	curr := ll.head
	for curr != nil {
		if curr.val == data {
			return true
		}
		curr = curr.next
	}
	return false
}

func main() {
	list := initLinkedList()

	for i := 0; i < 10; i++ {
		list.append(i)
	}

	list.display()
	list.reverse()
	list.display()
}
