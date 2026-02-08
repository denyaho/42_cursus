def ft_count_harvest_iterative() -> None:
    """
    This function counts the days of harvest in iterative way
    """
    days = int(input("Days until harvest: "))
    for i in range(days):
        print("Day", i + 1)
    print("Harvest time!")
