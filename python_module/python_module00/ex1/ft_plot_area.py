def ft_plot_area() -> None:
    """
    This function requires the input of length and width of rectangular area.
    Then, print the area.
    """
    length = input("Enter length: ")
    width = input("Enter width: ")
    area = int(length) * int(width)
    print("Plot area:", area)
