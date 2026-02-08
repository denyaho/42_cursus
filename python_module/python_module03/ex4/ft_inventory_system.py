#! /usr/bin/env python3

import sys


def inventory_system_analytics(data: dict, total_data: int) -> None:
    """
    Analyzes and prints the overall status of the inventory system.
    """
    print("=== Inventory System Analysis ===")
    print(f"Total items in inventory: {total_data}")
    num_items = 0
    for _ in data.keys():
        num_items += 1
    print(f"Unique item types: {num_items}")


def display_inventory(data: dict, total_data: int) -> None:
    """
    Displays each item in the inventory with its quality
    and percentage of the total
    """
    print("=== Current Inventory ===")
    for key, value in data.items():
        ratio = value / total_data * 100
        print(f"{key}: {value} units ({ratio:.1f}%)")


def inventory_statistics(data: dict) -> None:
    """
    Identifies and prints the most and least
    abundant items in the inventory
    """
    print("=== Inventory Statisticws ===")
    max_number = 0
    min_number = 1000000
    for value in data.values():
        if value > max_number:
            max_number = value
        if value < min_number:
            min_number = value
    for key, value in data.items():
        if value == max_number:
            print(f"Most abundant: {key} ({value} units)")
            break
    for key, value in data.items():
        if value == min_number:
            print(
                f"Least abundant: {key} ({value}"
                f" {'unit' if value == 1 else 'units'})"
            )
            break


def item_category(data: dict):
    """
    Categorizes items into 'Moderate' or 'Scarses'
    based on their quantities
    """
    print("=== Item Categories ===")
    moderate_value = {}
    scarce_value = {}
    for key, value in data.items():
        if value >= 5:
            moderate_value[key] = value
        else:
            scarce_value[key] = value
    print(f"Moderate: {moderate_value}")
    print(f"Scarce: {scarce_value}")


def display_restock_items(data: dict):
    """
    Identifies items that are critically low
    (exactly 1 unit) and suggests restock
    """
    print("=== Management Suggestions ===")
    restock_list = []
    for key, value in data.items():
        if value == 1:
            restock_list.append(key)
    print(f"Restock needed: {restock_list}")


def display_dictionary_properties(data: dict):
    """
    Demonstrates basic python dictionary properties
    using the inventory data.
    """
    print("=== Dictionary Properties Demo ===")
    print(f"Dictionary keys: {list(data.keys())}")
    print(f"Dictionary values: {list(data.values())}")
    print(f"Sample lookup - 'sword' in inventory: {'sword' in data}")


if __name__ == "__main__":
    args = sys.argv
    data = {}
    total_data = 0
    try:
        for i in range(1, len(args)):
            key, value = args[i].split(":", 1)
            data[key] = int(value)
            total_data += int(value)
    except ValueError as e:
        print(e)
    else:
        inventory_system_analytics(data, total_data)
        print()
        display_inventory(data, total_data)
        print()
        inventory_statistics(data)
        print()
        item_category(data)
        print()
        display_restock_items(data)
        print()
        display_dictionary_properties(data)
