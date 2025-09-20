def sort_colors(colors)-> int:
    """
    Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

    Args:
    colors (List[int]): List of integers where 0 represents red, 1 represents white, and 2 represents blue.

    Returns:
    List[int]: The sorted list with colors in the order red (0), white (1), and blue (2).

    Example:
    >>> sort_colors([2,0,2,1,1,0])
    [0, 0, 1, 1, 2, 2]
    """
    firstPtr = 0
    secondPtr = len(colors) - 1

    firstPtr = pivot_array(colors, 0, firstPtr)

    if (firstPtr == len(colors) - 1):
        return colors

    firstPtr = pivot_array(colors, 1, firstPtr)

    return colors

def pivot_array(colors, pivot, firstIdx):
    secondIdx = len(colors) - 1
    while (firstIdx < secondIdx):
        while (firstIdx < len(colors) and colors[firstIdx] == pivot):
            firstIdx = firstIdx + 1
        while (secondIdx > 0 and colors[secondIdx] != pivot):
            secondIdx = secondIdx - 1
        if (firstIdx < secondIdx):
            colors[firstIdx], colors[secondIdx] = colors[secondIdx], colors[firstIdx]

    return firstIdx
