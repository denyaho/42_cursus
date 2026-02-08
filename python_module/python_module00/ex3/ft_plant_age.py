def ft_plant_age():
    """
    This function receives the age of plants
    it prints "Plant is ready to harvest!" if the age is more than 60.
    otherwise it prints "Plant needs more time to grow."
    """
    age = int(input("Enter plant age in days: "))
    if age > 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
