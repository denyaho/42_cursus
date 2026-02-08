#! /usr/bin/env python3


def list_comprehensions(data: dict) -> None:
    """
    This function creates result using list comprehension
    Display the user of "high scorers (>2000)" and
    doubled scores of each user and
    Active user which had +5 sessions recently
    """
    print("=== List Comprehension Examples ===")
    high_scores = [
        player
        for player, stats in data["players"].items()
        if stats["total_score"] > 2000
    ]
    scores_doubled = [
        stats["total_score"] * 2 for player, stats in data["players"].items()
    ]
    session_data = {}
    for session_list in data["sessions"]:
        session_data[session_list["player"]] = (
            session_data.get(session_list["player"], 0) + 1
        )
    active_players = [
        p for p, session_cnt in session_data.items() if session_cnt >= 5
    ]
    print(f"High scorers (>2000): {high_scores}")
    print(f"Scores doubled: {scores_doubled}")
    print(f"Active players (5+ sessions): {active_players}")


def dict_comprehensions(data: dict) -> None:
    """
    This function display each results using dict comprehension
    Display scores of each player in a dict form {player: total_score} and
    score categories of each player using "high", "medium", "low",
    achivements_count of each player.
    """
    print("=== Dictionary Comprehension Examples ===")
    player_scores = {
        p: stats["total_score"] for p, stats in data["players"].items()
    }
    score = {
        player: (
            "high"
            if stats["total_score"] > 4000
            else "medium" if 2000 <= stats["total_score"] <= 4000 else "low"
        )
        for player, stats in data["players"].items()
    }

    score_category = {
        category: (sum(1 for value in score.values() if value == category))
        for category in ["high", "medium", "low"]
    }
    achivement_counts = {
        player: stats["achievements_count"]
        for player, stats in data["players"].items()
        if stats["achievements_count"] >= 3
    }
    print(f"Player scores: {player_scores}")
    print(f"Score categories: {score_category}")
    print(f"Achievement counts (3+): {achivement_counts}")


def set_comprehensions(data: dict) -> None:
    """
    This function display each result using set comprehensions
    shows unique players and unique achivements earned by
    each player
    """
    print("=== Set Comprehension Examples ===")
    unique_players = {player for player in data["players"].keys()}
    unique_achievements = {
        data["achievements"][stats["achievements_count"]]
        for stats in data["players"].values()
    }
    print(f"Unique players: {unique_players}")
    print(f"Unique achievements: {unique_achievements}")


def combined_analysis(data: dict) -> None:
    """
    This function displays result.
    Display "the number of players", "the number of total unique
    achivements", "Average score" earned by each player.
    Also display top performer chosen based on
    "the number of achivements_count" and "total_score", "level"
    """
    print("=== Combined Analysis ===")
    total_players = len(data["players"])
    total_unique_achivements = len(
        {
            data["achievements"][stats["achievements_count"]]
            for stats in data["players"].values()
        }
    )
    average_scores = (
        sum(s["total_score"] for s in data["players"].values()) / total_players
    )

    sorted_achivements = sorted(
        data["players"].items(),
        key=lambda x: x[1]["achievements_count"], reverse=True
    )
    sorted_scores = sorted(
        sorted_achivements,
        key=lambda x: x[1]["total_score"], reverse=True
    )
    sorted_levels = sorted(
        sorted_scores,
        key=lambda x: x[1]["level"], reverse=True
    )
    print(f"Total players: {total_players}")
    print(f"Total unique achievements: {total_unique_achivements}")
    print(f"Average score: {average_scores:.2f}")
    print(
        f"Top performer: {sorted_levels[0][0]}"
        f"({sorted_levels[0][1]['total_score']}"
        f" points, {sorted_levels[0][1]['achievements_count']} achievements)"
    )


if __name__ == "__main__":
    game_data = {
        "players": {
            "alice": {
                "level": 41,
                "total_score": 2824,
                "sessions_played": 13,
                "favorite_mode": "ranked",
                "achievements_count": 5,
            },
            "bob": {
                "level": 16,
                "total_score": 4657,
                "sessions_played": 27,
                "favorite_mode": "ranked",
                "achievements_count": 2,
            },
            "charlie": {
                "level": 44,
                "total_score": 9935,
                "sessions_played": 21,
                "favorite_mode": "ranked",
                "achievements_count": 7,
            },
            "diana": {
                "level": 3,
                "total_score": 1488,
                "sessions_played": 21,
                "favorite_mode": "casual",
                "achievements_count": 4,
            },
            "eve": {
                "level": 33,
                "total_score": 1434,
                "sessions_played": 81,
                "favorite_mode": "casual",
                "achievements_count": 7,
            },
            "frank": {
                "level": 15,
                "total_score": 8359,
                "sessions_played": 85,
                "favorite_mode": "competitive",
                "achievements_count": 1,
            },
        },
        "sessions": [
            {
                "player": "bob",
                "duration_minutes": 94,
                "score": 1831,
                "mode": "competitive",
                "completed": False,
            },
            {
                "player": "bob",
                "duration_minutes": 32,
                "score": 1478,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "diana",
                "duration_minutes": 17,
                "score": 1570,
                "mode": "competitive",
                "completed": False,
            },
            {
                "player": "alice",
                "duration_minutes": 98,
                "score": 1981,
                "mode": "ranked",
                "completed": True,
            },
            {
                "player": "diana",
                "duration_minutes": 15,
                "score": 2361,
                "mode": "competitive",
                "completed": False,
            },
            {
                "player": "eve",
                "duration_minutes": 29,
                "score": 2985,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "frank",
                "duration_minutes": 34,
                "score": 1285,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "alice",
                "duration_minutes": 53,
                "score": 1238,
                "mode": "competitive",
                "completed": False,
            },
            {
                "player": "bob",
                "duration_minutes": 52,
                "score": 1555,
                "mode": "casual",
                "completed": False,
            },
            {
                "player": "frank",
                "duration_minutes": 92,
                "score": 2754,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "eve",
                "duration_minutes": 98,
                "score": 1102,
                "mode": "casual",
                "completed": False,
            },
            {
                "player": "diana",
                "duration_minutes": 39,
                "score": 2721,
                "mode": "ranked",
                "completed": True,
            },
            {
                "player": "frank",
                "duration_minutes": 46,
                "score": 329,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "charlie",
                "duration_minutes": 56,
                "score": 1196,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "eve",
                "duration_minutes": 117,
                "score": 1388,
                "mode": "casual",
                "completed": False,
            },
            {
                "player": "diana",
                "duration_minutes": 118,
                "score": 2733,
                "mode": "competitive",
                "completed": True,
            },
            {
                "player": "charlie",
                "duration_minutes": 22,
                "score": 1110,
                "mode": "ranked",
                "completed": False,
            },
            {
                "player": "frank",
                "duration_minutes": 79,
                "score": 1854,
                "mode": "ranked",
                "completed": False,
            },
            {
                "player": "charlie",
                "duration_minutes": 33,
                "score": 666,
                "mode": "ranked",
                "completed": False,
            },
            {
                "player": "alice",
                "duration_minutes": 101,
                "score": 292,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "frank",
                "duration_minutes": 25,
                "score": 2887,
                "mode": "competitive",
                "completed": True,
            },
            {
                "player": "diana",
                "duration_minutes": 53,
                "score": 2540,
                "mode": "competitive",
                "completed": False,
            },
            {
                "player": "eve",
                "duration_minutes": 115,
                "score": 147,
                "mode": "ranked",
                "completed": True,
            },
            {
                "player": "frank",
                "duration_minutes": 118,
                "score": 2299,
                "mode": "competitive",
                "completed": False,
            },
            {
                "player": "alice",
                "duration_minutes": 42,
                "score": 1880,
                "mode": "casual",
                "completed": False,
            },
            {
                "player": "alice",
                "duration_minutes": 97,
                "score": 1178,
                "mode": "ranked",
                "completed": True,
            },
            {
                "player": "eve",
                "duration_minutes": 18,
                "score": 2661,
                "mode": "competitive",
                "completed": True,
            },
            {
                "player": "bob",
                "duration_minutes": 52,
                "score": 761,
                "mode": "ranked",
                "completed": True,
            },
            {
                "player": "eve",
                "duration_minutes": 46,
                "score": 2101,
                "mode": "casual",
                "completed": True,
            },
            {
                "player": "charlie",
                "duration_minutes": 117,
                "score": 1359,
                "mode": "casual",
                "completed": True,
            },
        ],
        "game_modes": ["casual", "competitive", "ranked"],
        "achievements": [
            "first_blood",
            "level_master",
            "speed_runner",
            "treasure_seeker",
            "boss_hunter",
            "pixel_perfect",
            "combo_king",
            "explorer",
        ],
    }
    print("=== Game Analytics Dashboard ===")
    print()
    list_comprehensions(game_data)
    print()
    dict_comprehensions(game_data)
    print()
    set_comprehensions(game_data)
    print()
    combined_analysis(game_data)
