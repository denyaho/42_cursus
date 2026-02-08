#!/usr/bin/env python3


class Plant:
    """
    Base class representing a general plant in the garden
    """

    def __init__(self, name: str, height: int):
        """
        Initialize an instance of the Plant class

        Args:
            name(str) : The name of the plants
            height(int) : The initial height
        """
        self.name = name
        self.height = height

    def __str__(self) -> str:
        """
        Return plant information as a string.
        """
        return f"- {self.name}: {self.height}cm"


class FloweringPlant(Plant):
    """
    Class representing a flowering plant (inherits from Plant).
    """

    def __init__(self, name: str, height: int, color: str):
        """
        Initialize an instance of the FloweringPlant class.

        color (str): The color of the flower
        """
        super().__init__(name, height)
        self.color = color

    def __str__(self) -> str:
        """
        Return plant information including flowers as a string
        """

        return (f"- {self.name}: {self.height}cm"
                f", {self.color} flowers (blooming)")


class PrizeFlower(FloweringPlant):
    """
    Class representing a special prize-winning
    flower (inherits from FloweringPlant).
    """

    def __init__(self, name: str, height: int, color: str, points: int):
        """
        Initialize an instance of the PrizeFlower class.

        points(int): The prize points.
        """
        super().__init__(name, height, color)
        self.points = points

    def __str__(self) -> str:
        """
        Return flower information including prize points as a string.
        """
        return (
            f"- {self.name}: {self.height}cm, "
            f"{self.color} flowers (blooming), Prize points: {self.points}"
        )


class GardenManager:
    """
    Garden management system. Handles plant addition,
    growth, and statistics management.
    """

    def __init__(self, owner: str):
        """
        Initialize the GardenManager.
        owner (str): The name of the garden owner.
        self.plants self.flowers self.prize_flowers
        -> list managing plants
        """
        self.owner = owner
        self.plants = []
        self.flowers = []
        self.prize_flowers = []
        self.initial_height = 0

    def add_plant(self, plant: Plant) -> None:
        """
        Add a general plant to the garden.

        Args:
            plant (Plant): The Plant object to add.
        """
        self.plants.append(plant)
        self.initial_height += plant.height
        print(f"Added {plant.name} to {self.owner}'s garden.")

    def add_flowering_plant(self, plant: FloweringPlant) -> None:
        """
        Add a flowering plant to the garden.

        Args:
            plant (FloweringPlant): The FloweringPlant object to add.
        """
        self.flowers.append(plant)
        self.initial_height += plant.height
        print(f"Added {plant.name} to {self.owner}'s garden.")

    def add_prize_flower(self, plant: PrizeFlower) -> None:
        """
        Add a prize flower to the garden.

        Args:
            plant (PrizeFlower): The PrizeFlower object to add.
        """
        self.prize_flowers.append(plant)
        self.initial_height += plant.height
        print(f"Added {plant.name} to {self.owner}'s garden.")

    def grow_all(self, grow: int) -> None:
        """
        Grow all plants in the garden by a specified height.

        Args:
            grow (int): The height to grow (cm).
        """
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            plant.height += grow
            print(f"{plant.name} grew {grow}cm")
        for flower in self.flowers:
            flower.height += grow
            print(f"{flower.name} grew {grow}cm")
        for prize_flower in self.prize_flowers:
            prize_flower.height += grow
            print(f"{prize_flower.name} grew {grow}cm")

    class GardenStats:
        """
        Helper class for calculating and validating garden statistics.
        """

        @staticmethod
        def is_valid_height(height: int) -> bool:
            """
            Utility function to validate if height is a positive value.
            height(int): The height to validate
            """
            return height >= 0

        @staticmethod
        def validate_height(manager: "GardenManager") -> None:
            """
            Validate if the height of all plants in the garden is valid.

            Args:
                manager (GardenManager): The target garden manager instance.
            """
            for plant in manager.plants:
                if not GardenManager.GardenStats.is_valid_height(plant.height):
                    print("Height validation test: False")
                    return
            for flw in manager.flowers:
                if not GardenManager.GardenStats.is_valid_height(flw.height):
                    print("Height validation test: False")
                    return
            for prize in manager.prize_flowers:
                if not GardenManager.GardenStats.is_valid_height(prize.height):
                    print("Height validation test: False")
                    return
            print("Height validation test: True")

        @staticmethod
        def total_growth(manager: "GardenManager") -> None:
            """
            Calculate total current plant height and
            return the difference from initial height (growth).
            """
            total_height = 0

            for plant in manager.plants:
                total_height += plant.height
            for flower in manager.flowers:
                total_height += flower.height
            for prize_flower in manager.prize_flowers:
                total_height += prize_flower.height
            return total_height - manager.initial_height

        @staticmethod
        def total_num(manager: "GardenManager"):
            """
            Calculate the total number of all plants in the garden.
            """
            result = len(manager.plants) + len(manager.flowers)
            +len(manager.prize_flowers)
            return result

        @staticmethod
        def total_prize_points(manager: "GardenManager"):
            """
            Calculate the total points of all prize flowers in the garden.
            """
            total_points = 0
            for prize_flower in manager.prize_flowers:
                total_points += prize_flower.points
            return total_points

        @staticmethod
        def num_plant(manager: "GardenManager") -> int:
            """
            Return the number of general plants.
            """
            cnt = 0
            for _ in manager.plants:
                cnt += 1
            return cnt

        @staticmethod
        def num_flower(manager: "GardenManager") -> int:
            """
            Return the number of flowering plants.
            """
            cnt = 0
            for _ in manager.flowers:
                cnt += 1
            return cnt

        @staticmethod
        def num_prize_flower(manager: "GardenManager") -> int:
            """
            Return the number of prize flowers.
            """
            cnt = 0
            for _ in manager.prize_flowers:
                cnt += 1
            return cnt

        @staticmethod
        def calculate_statistics_data(manager: "GardenManager") -> dict:
            """
            Return a dictionary containing statistical
             data required for reporting.
            """
            total_height = GardenManager.GardenStats.total_growth(manager)
            number_plant = GardenManager.GardenStats.total_num(manager)
            type_plant = GardenManager.GardenStats.num_plant(manager)
            type_flower = GardenManager.GardenStats.num_flower(manager)
            type_prize = GardenManager.GardenStats.num_prize_flower(manager)
            return {
                "total_height": total_height,
                "number_plant": number_plant,
                "type_plant": type_plant,
                "type_flower": type_flower,
                "type_prize": type_prize,
            }

    @classmethod
    def create_garden_network(cls, owner_list: list) -> list:
        """
        Create garden managers from a list of
        owner names and return them as a list.

        owner_list (list): List of owner names (strings).
        """
        result = []
        for owner in owner_list:
            result.append(cls(owner))
        return result

    def report(self):
        """
        Print the current status and statistics of the garden to the console.
        """
        stats = self.GardenStats.calculate_statistics_data(self)

        print(f"=== {self.owner}'s Garden Report ===")
        print("Plants in garden:")
        for plant in self.plants:
            print(plant)
        for flower in self.flowers:
            print(flower)
        for prize_flower in self.prize_flowers:
            print(prize_flower)
        print()
        print(
            f"Plants added: {stats['number_plant']},"
            f"Total growth: {stats['total_height']}cm"
        )
        print(
            f"Plant types: {stats['type_plant']} regular,"
            f" {stats['type_flower']} "
            f"flowering, {stats['type_prize']} prize flowers"
        )


if __name__ == "__main__":
    print("=== Garden Management System Demo ===")
    print()
    gardens = GardenManager.create_garden_network(["Alice", "Bob"])

    gardens[0].add_plant(Plant("Oak Tree", 10))
    gardens[0].add_flowering_plant(FloweringPlant("Rose", 25, "red"))
    gardens[0].add_prize_flower(PrizeFlower("Tulip", 30, "yellow", 50))

    print()
    gardens[1].add_plant(Plant("Pine", 15))
    gardens[1].add_flowering_plant(FloweringPlant("Daisy", 20, "white"))
    gardens[1].add_prize_flower(PrizeFlower("Sunflower", 40, "yellow", 70))
    print()
    gardens[0].grow_all(5)
    print()
    gardens[1].grow_all(3)
    print()
    for garden in gardens:
        garden.report()
        print()
    GardenManager.GardenStats.validate_height(gardens[0])
    print(
        f"Garden scores - {gardens[0].owner}: "
        f"{GardenManager.GardenStats.total_prize_points(gardens[0])}, "
        f"{gardens[1].owner}: "
        f"{GardenManager.GardenStats.total_prize_points(gardens[1])}"
    )
    print("Total gardens managed:", len(gardens))
