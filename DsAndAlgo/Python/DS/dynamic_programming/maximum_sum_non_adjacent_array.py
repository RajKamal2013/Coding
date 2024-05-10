def maximum_sum_non_adjacent_array_solution(array):
    if len(array) == 0:
        return -1
    if len(array) == 1:
        return array[0]
    incl:list[int] = [0 for range in range(len(array))]
    excl:list[int] = [0 for range in range(len(array))]

    incl[0] = array[0]
    excl[0] = 0

    for i in range(1, len(array),1):
        incl[i] = excl[i-1] + array[i]
        excl[i] = max(excl[i-1], incl[i-1])

    return max(incl[len(array) -1], excl[len(array)-1])
