
def findKnapsack(capacity:int, weights:[int], values:[int], n:int):
    dp = [[0 for i in range(capacity + 1)] for j in range(n + 1)]
    for idx in range(len(dp)):
        for weight in range(len(dp[0])):
            if idx == 0 or weight == 0:
                dp[idx][weight] = 0
            elif weights[idx - 1] <= weight:
                dp[idx][weight] = max(values[idx-1] + dp[idx-1][weight - weights[idx -1]], dp[idx-1][weight])
            else:
                dp[idx][weight] = dp[idx-1][weight]

    return dp[-1][-1] #dp[n][capacity]

def display(capacity:int, weights:[int], values:[int], n:int, maxValue:int, expectedValue:int):
    print("---------------------------------------------------------------------------------")
    print("                                     Input                                       ")
    print("---------------------------------------------------------------------------------")
    print("Capacity of Knapsack: ", capacity)
    print("Values:", values)
    print("Weights: ", weights)
    print("---------------------------------------------------------------------------------")
    print("                                     Output                                       ")
    print("---------------------------------------------------------------------------------")
    print("MaxValue: ", maxValue)
    print("ExpectedValue: ", expectedValue)
def test_Knapsack():
    capacity = 6
    n = 4
    weights = [1, 2, 3, 5]
    values = [1, 5, 4, 8]

    maxValue = findKnapsack(capacity, weights, values, n)
    expectedValue = 10
    display(capacity, weights, values, n, maxValue, expectedValue)

def main():
    test_Knapsack()

if __name__ == '__main__':
    main()
