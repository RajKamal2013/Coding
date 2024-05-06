import logging

logger = logging.getLogger(__name__)
logging.basicConfig(level=logging.DEBUG)

def validations(n: int, denoms: list[int]) -> int:
    ret:int = 0
    if n == 0:
        ret = 1
        return ret
    if n < 0:
        ret = -1
        return ret
    if len(denoms) <= 0:
        ret = -1
        return ret

    return ret

def number_of_ways_to_make_change_naive_int(n: int, denoms: list[int], max_denom_coin: int) -> int:
    if (n < 0):
        return 0;

    if (n == 0):
        return 1

    number_of_ways: int = 0

    for denom in denoms:
        if (denom <= max_denom_coin) and (n - denom >= 0):
            number_of_ways = number_of_ways + number_of_ways_to_make_change_naive_int(n - denom, denoms, denom)

    return number_of_ways



def number_of_ways_to_make_change_naive(n:int, denoms:list[int]) -> int:
    ret = validations(n, denoms)

    if ret < 0:
        logging.error("Validations Failed: ", ret)
        return ret

    if ret == 1:
        logging.info("Base case: n:{}, ret: {}".format(n, ret))
        return ret

    denoms.sort()
    max_idx = len(denoms) -1
    max_denom_coin:int = denoms[max_idx]
    number_of_ways =  number_of_ways_to_make_change_naive_int(n, denoms, max_denom_coin)
    logging.info("Number of ways to make n:{} using denoms:{} is {}".format( n, denoms, number_of_ways))

    return number_of_ways

def number_of_ways_to_make_change_dp_top_down_int(n:int, denoms:list[int], max_denom_idx:int, dp) -> int:
    if n == 0:
        return 1

    if n < 0:
        return 0

    if dp[max_denom_idx][n] != -1:
        return dp[max_denom_idx][n]

    number_of_ways:int = 0
    for denom in denoms:
        if (denom <= denoms[max_denom_idx]) and (n - denom >= 0):
            number_of_ways = number_of_ways + number_of_ways_to_make_change_dp_top_down_int(n - denom, denoms, denoms.index(denom), dp)

    dp[max_denom_idx][n] = number_of_ways
    return number_of_ways

def number_of_ways_to_make_change_dp_top_down(n:int, denoms:list[int])->int:
    ret = validations(n, denoms)

    if ret < 0:
        logging.error("Validations Failed: ", ret)
        return ret

    if ret == 1:
        logging.info("Base case: n:{}, ret: {}".format(n, ret))
        return ret

    denoms.sort()
    rows:int = len(denoms)
    cols:int =  n + 1

    dp:list[int][int] = [[-1 for i in range(cols)] for j in range(rows)]
    max_denom_idx:int = len(denoms) - 1
    number_of_ways = number_of_ways_to_make_change_dp_top_down_int(n, denoms, max_denom_idx, dp)
    logging.info("Number of ways to make n:{} using denoms:{} is {}".format( n, denoms, number_of_ways))
    return number_of_ways

def number_of_ways_to_make_change_dp_bottoms_up(n:int, denoms:list[int]) -> int:
    ret = validations(n, denoms)

    if ret < 0:
        logging.error("Validations Failed: ", ret)
        return ret

    if ret == 1:
        logging.info("Base case: n:{}, ret: {}".format(n, ret))
        return ret

    denoms.sort()
    rows: int = n + 1
    cols: int = len(denoms)

    dp: list[int][int] = [[0 for i in range(cols)] for j in range(rows)]
    for idx in range(len(denoms)):
        dp[0][idx] = 1

    incl:int = 0
    excl:int = 0

    for i in range(1, rows, 1):
        for j in range(cols):
            incl = excl = 0
            if (i - denoms[j] >= 0):
                incl = dp[i-denoms[j]][j]
            if (j - 1 >= 0):
                excl = dp[i][j-1]
            dp[i][j] = incl + excl

    logging.info("Number of ways to make n:{} using denoms:{} is {}".format( n, denoms,  dp[n][len(denoms) - 1]))
    return  dp[n][len(denoms) - 1]


def number_of_ways_to_make_change(n, denoms) -> int:
    number_of_ways:int = number_of_ways_to_make_change_naive(n, denoms)
    logging.info("Naive way: Number of ways to make n:{} using denoms:{} is {}".format( n, denoms, number_of_ways))

    number_of_ways: int = number_of_ways_to_make_change_dp_top_down(n, denoms)
    logging.info("DP Top Down: Number of ways to make n:{} using denoms:{} is {}".format(n, denoms, number_of_ways))

    number_of_ways: int = number_of_ways_to_make_change_dp_bottoms_up(n, denoms)
    logging.info("DP Bottoms Up: Number of ways to make n:{} using denoms:{} is {}".format(n, denoms, number_of_ways))
    return number_of_ways

def  __main__():
    denoms:list[int] = [1, 5]
    n: int = 6
    number_of_ways: int = number_of_ways_to_make_change(n, denoms)
    logging.info("Number of ways to make n:{} using denoms:{} : {}".format( n, denoms, number_of_ways))

    denoms = [1, 5, 10, 25]
    n = 5
    number_of_ways: int = number_of_ways_to_make_change(n, denoms)
    logging.info("Number of ways to make n:{} using denoms:{} : {}".format(n, denoms, number_of_ways))


__main__()