package patterns

import "testing"

func TestFindLongestSubstring(t *testing.T) {
	tests := []struct {
		name string
		in   string
		want int
	}{
		{"EmptyString_returnsMinusOne", "", -1}, // matches current code behavior
		{"SingleChar", "a", 1},
		{"AllUnique", "abcde", 5},
		{"AllSame", "aaaaaa", 1},
		{"RepeatingPattern1", "abcabcbb", 3}, // classic example -> "abc"
		{"RepeatingPattern2", "pwwkew", 3},   // classic example -> "wke"
		{"WithSpaces", " a bca ", 4},         // space counts as a char for this byte-based impl
		{"LongerMix", "abcaefghib", 8},       // sanity check on longer string
	}

	for _, tc := range tests {
		t.Run(tc.name, func(t *testing.T) {
			got := findLongestSubstring(tc.in)
			if got != tc.want {
				t.Fatalf("findLongestSubstring(%q) = %d; want %d", tc.in, got, tc.want)
			}
		})
	}
}
