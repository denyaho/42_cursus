#! /usr/bin/env python3


def achievement_analytics(data: dict) -> None:
    """
    This function displays detailed information of achievement
    data of each user.
    For example, unique achievement, total achievement,
    rare achievement etc.
    """
    print("=== Achievement Analytics ===")
    all_unique_data = set()
    for key, value in data.items():
        all_unique_data = all_unique_data.union(set(value))
    print(f"All unique achievements: {all_unique_data}")
    print(f"Total unique achievements: {len(all_unique_data)}")
    print()
    common_data = all_unique_data
    for key, value in data.items():
        common_data = common_data.intersection(set(value))
    print(f"Common to all players: {common_data}")
    rare_data = set()
    rare_player = set()
    for player, values in data.items():
        other_player_data = set()
        for other_player, other_data in data.items():
            if player != other_player:
                other_player_data = other_player_data.union(set(other_data))
        for value in set(values):
            if value not in other_player_data:
                rare_data.add(value)
                rare_player.add(player)
    print(f"Rare achievements ({len(rare_player)} player): {rare_data}")
    print()
    for key1, value1 in data.items():
        for key2, value2 in data.items():
            if key1 != key2:
                print(
                    f"{key1.capitalize()} vs {key2.capitalize()} common:"
                    f" {set(value1).intersection(set(value2))}"
                )
    for key1, value1 in data.items():
        user_unique_data = set(value1)
        for key2, value2 in data.items():
            if key1 != key2:
                user_unique_data = user_unique_data.difference(set(value2))
        print(f"{key1.capitalize()} unique: {user_unique_data}")


def achievement_tracker(data: dict) -> None:
    """
    This function displays the details of achivements data of each user
    and call 'achievement_analytics' for detailed information.
    param:
    Achiements set data of each user.
    """
    print("=== Achievement Tracker System ===")
    print()
    for key, value in data.items():
        print(f"Player {key} achievement: {value}")
    print()
    achievement_analytics(data)


if __name__ == "__main__":
    data = {
        "alice": [
            "first_blood",
            "pixel_perfect",
            "speed_runner",
            "first_blood",
            "first_blood",
            "level_master",
        ],
        "bob": [
            "level_master",
            "boss_hunter",
            "treasure_seeker",
            "level_master",
            "level_master",
        ],
        "charlie": [
            "level_master",
            "treasure_seeker",
            "boss_hunter",
            "combo_king",
            "first_blood",
            "boss_hunter",
            "first_blood",
            "boss_hunter",
            "first_blood",
        ],
        "diana": [
            "first_blood",
            "combo_king",
            "level_master",
            "treasure_seeker",
            "speed_runner",
            "combo_king",
            "combo_king",
            "level_master",
        ],
        "eve": [
            "level_master",
            "treasure_seeker",
            "first_blood",
            "treasure_seeker",
            "first_blood",
            "treasure_seeker",
        ],
        "frank": [
            "explorer",
            "boss_hunter",
            "first_blood",
            "explorer",
            "first_blood",
            "boss_hunter",
            "level_master",
        ],
    }
    achievement_tracker(data)
