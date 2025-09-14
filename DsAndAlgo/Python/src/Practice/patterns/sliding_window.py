
def findLongestSubstring(s: str) -> int:
    if s is None:
        return -1
    if s == "":
        return 0
    if len(s) == 1:
        return 1

    last_index: dict[str, int] = {}
    start = 0
    max_len = 0

    for i, ch in enumerate(s):
        if ch in last_index and last_index[ch] >= start:
            start = last_index[ch] + 1
        last_index[ch] = i
        max_len = max(max_len, i - start + 1)

    return max_len

