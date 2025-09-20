package patterns

func findLongestSubstring(str string) int {

	if str == "" {
		return -1
	}
	if len(str) == 0 {
		return 0
	}

	if len(str) == 1 {
		return 1
	}

	firstIdx := 0
	secondIdx := 0
	maxLen := 0

	set := make(map[byte]struct{})

	set[str[firstIdx]] = struct{}{}
	secondIdx = 1
	for secondIdx < len(str) {
		for _, ok := set[str[secondIdx]]; ok; _, ok = set[str[secondIdx]] {
			delete(set, str[firstIdx])
			firstIdx++
		}
		set[str[secondIdx]] = struct{}{}
		maxLen = max(maxLen, len(set))
		secondIdx++
	}

	maxLen = max(maxLen, len(set))

	return maxLen
}
