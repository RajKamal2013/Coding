import dynamic_programming.maximum_sum_non_adjacent_array

def display_input(array):
    print("---------------------------------------------")
    print("Array: {}".format(array))

def display_output(expected:int, computed:int):
    print("Expected: {}".format(expected))
    print("Calculated: {}".format(computed))

def maximum_sum_non_adjacent_array_sum_test():
    array:list[int] = [75, 105, 120, 75, 90, 135]
    display_input(array)
    expected:int = 330
    computed  = dynamic_programming.maximum_sum_non_adjacent_array_solution(array)
    display_input(expected, computed)

