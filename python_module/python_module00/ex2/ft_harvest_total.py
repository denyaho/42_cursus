def ft_harvest_total() -> None:
    """
    This function requires to input the weight
    of vegetables to harvest in each day.
    Then, calculate the sum of the weight of all vegetables and print it.
    """
    weight1 = input("Day 1 harvest: ")
    weight2 = input("Day 2 harvest: ")
    weight3 = input("Day 3 harvest: ")
    total = int(weight1) + int(weight2) + int(weight3)
    print("Total harvest:", total)
