package patterns

import (
	"reflect"
	"testing"
)

func TestSortColors(t *testing.T) {
	tests := []struct {
		input    []int
		expected []int
	}{
		{[]int{2, 0, 2, 1, 1, 0}, []int{0, 0, 1, 1, 2, 2}},
		{[]int{0, 1, 2}, []int{0, 1, 2}},
		{[]int{2, 2, 2}, []int{2, 2, 2}},
		{[]int{0, 0, 0}, []int{0, 0, 0}},
		{[]int{1, 1, 1}, []int{1, 1, 1}},
		{[]int{1, 0, 2}, []int{0, 1, 2}},
		{[]int{}, []int{}},
		{[]int{0}, []int{0}},
		{[]int{1}, []int{1}},
		{[]int{2}, []int{2}},
	}

	for _, tt := range tests {
		got := sortColors(append([]int{}, tt.input...)) // copy to avoid mutation
		if !reflect.DeepEqual(got, tt.expected) {
			t.Errorf("sortColors(%v) = %v; want %v", tt.input, got, tt.expected)
		}
	}
}
