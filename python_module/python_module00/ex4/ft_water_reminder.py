def ft_water_reminder() -> None:
    """
    This function receives the number of days since the last watering.
    It prints "Water the plants" if it has been more than 2 days
    otherwise it prints "Plants are fine"
    """
    days = int(input("Days since last watering: "))
    if days > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
