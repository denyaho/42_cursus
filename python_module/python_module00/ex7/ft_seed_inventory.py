def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    """
    Display received args in a certain format
    The sentence will change depends on the type
    if type is "packets" -> ~~ packets available
    if type is "grams" -> ~~ grams total
    if type is "area" -> ~~ square metes
    """
    seed_type = seed_type.capitalize()
    if unit == "packets":
        print("{} seeds: {} packets available".format(seed_type, quantity))
    elif unit == "grams":
        print("{} seeds: {} grams total".format(seed_type, quantity))
    elif unit == "area":
        print("{} seeds: covers {} square meters".format(seed_type, quantity))
    else:
        print("Unknown unit type.")
