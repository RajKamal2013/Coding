import pytest

from DS.dynamic_programming.maximum_sum_non_adjacent_array import maximum_sum_non_adjacent_array_solution



def display_input(array):
    print("---------------------------------------------")
    print("Array: {}".format(array))

def display_output(expected:int, computed:int):
    print("Expected: {}".format(expected))
    print("Calculated: {}".format(computed))

def test_maximum_sum_non_adjacent_array_sum():
    array:list[int] = [75, 105, 120, 75, 90, 135]
    display_input(array)
    expected:int = 330
    computed  = maximum_sum_non_adjacent_array_solution(array)
    display_output(expected, computed)
    assert(expected, computed)

