package patterns

// TwoPointer is a package that provides a two-pointer technique for solving problems

import (
	"GoLang/internal/model"
	_ "fmt"
)

// RemoveNthLastNode removes the nth node from the end of a singly linked list and returns the new head.
// If n is 0 or the list is empty, it returns the original head.
func RemoveNthLastNode(head *model.ListNode, n int) *model.ListNode {
	if n == 0 || head == nil {
		return head
	}

	var firstPtr *model.ListNode
	var secondPtr *model.ListNode

	firstPtr = head
	secondPtr = head

	for i := 1; i <= n; i = i + 1 {
		if secondPtr != nil {
			secondPtr = secondPtr.Next
		} else {
			return secondPtr
		}
	}

	var prev *model.ListNode
	prev = nil

	for secondPtr != nil {
		prev = firstPtr
		firstPtr = firstPtr.Next
		secondPtr = secondPtr.Next
	}

	if prev == nil {
		head = head.Next
	} else {
		prev.Next = firstPtr.Next
	}
	return head
}

// sortColors sorts an array containing 0s, 1s, and 2s in-place using the two-pointer technique.
// Returns the sorted array.
func sortColors(colors []int) []int {
	firstIdx := 0
	lastIdx := len(colors) - 1

	// Lambda function for pivotArray
	pivotArray := func(colors []int, pivot int, firstIdx int) int {
		secondIdx := len(colors) - 1

		for firstIdx < secondIdx {
			if firstIdx < len(colors) && colors[firstIdx] == pivot {
				firstIdx++
			}

			if secondIdx > 0 && colors[secondIdx] != pivot {
				secondIdx--
			}

			if firstIdx < secondIdx {
				// Swap function
				colors[firstIdx], colors[secondIdx] = colors[secondIdx], colors[firstIdx]
			}
		}

		return firstIdx
	}

	firstIdx = pivotArray(colors, 0, firstIdx)

	if firstIdx == len(colors)-1 {
		return colors
	}

	lastIdx = pivotArray(colors, 1, lastIdx)

	return colors
}
