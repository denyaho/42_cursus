def ft_count_harvest_recursive() -> None:
    """
    This function counts the days of harvest in recursive way
    """
    days = int(input("Days until harvest: "))

    def recursive(current):
        if current > days:
            return
        print("Day", current)
        recursive(current + 1)

    recursive(1)
    print("Harvest time!")
