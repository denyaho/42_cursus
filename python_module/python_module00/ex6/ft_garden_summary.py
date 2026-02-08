def ft_garden_summary() -> None:
    """
    Receive garden name and the number of plants
    Display "Garden" and "Plants", "Status" with print
    """
    name = input("Enter garden name: ")
    number = int(input("Enter number of plants: "))
    print("Garden:", name)
    print("Plants:", number)
    print("Status: Growing well!")
