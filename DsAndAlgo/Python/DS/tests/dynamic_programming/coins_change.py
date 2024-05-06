import pytest

from DS.dynamic_programming.coins_change import number_of_ways_to_make_change_naive, \
    number_of_ways_to_make_change_dp_top_down, number_of_ways_to_make_change_dp_bottomsup


def display_input(n:int, denoms:list[int]):
    print("---------------------------------------------")
    print("Amount:{}".format(n))
    print("Denominations: {}".format(denoms))

def display_output(expected:int, computed:int):
    print("Expected: {}".format(expected))
    print("Calculated: {}".format(computed))
def test_number_of_ways_to_make_change_naive():
    n: int = 6
    denoms:list[int] = [1, 5]
    expected:int = 2
    computed:int = number_of_ways_to_make_change_naive(n, denoms)
    display_input(n, denoms)
    display_output(expected, computed)
    assert(expected, computed)


def test_number_of_ways_to_make_change_dp_top_down():
    n: int = 6
    denoms:list[int] = [1, 5]
    expected:int = 2
    computed:int = number_of_ways_to_make_change_dp_top_down(n, denoms)
    display_input(n, denoms)
    display_output(expected, computed)
    assert(expected, computed)

def test_number_of_ways_to_make_change_dp_bottoms_up():
    n: int = 6
    denoms:list[int] = [1, 5]
    expected:int = 2
    computed:int = number_of_ways_to_make_change_dp_bottomsup(n, denoms)
    display_input(n, denoms)
    display_output(expected, computed)
    assert(expected, computed)