from src.Practice.patterns.two_pointer import sort_colors


def sort_colors_handles_sorted_input():
    assert sort_colors([0, 0, 1, 1, 2, 2]) == [0, 0, 1, 1, 2, 2]

def sort_colors_handles_reverse_sorted_input():
    assert sort_colors([2, 2, 1, 1, 0, 0]) == [0, 0, 1, 1, 2, 2]

def sort_colors_handles_mixed_input():
    assert sort_colors([2, 0, 2, 1, 1, 0]) == [0, 0, 1, 1, 2, 2]

def sort_colors_handles_single_color_input():
    assert sort_colors([1, 1, 1]) == [1, 1, 1]

def sort_colors_handles_empty_input():
    assert sort_colors([]) == []

def sort_colors_handles_single_element_input():
    assert sort_colors([0]) == [0]
    assert sort_colors([1]) == [1]
    assert sort_colors([2]) == [2]

def sort_colors_handles_large_input():
    assert sort_colors([2, 0, 1] * 1000) == [0] * 1000 + [1] * 1000 + [2] * 1000