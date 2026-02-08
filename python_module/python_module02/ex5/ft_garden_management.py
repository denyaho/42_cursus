class Plant:
    """
    Represent a general plant whithin the garden system
    """

    def __init__(self, plant_name: str, water_level: int, sunlight_hours: int):
        """
        Initialize an instance of the Plant class

        Args:
            name(str) : The name of the plants
            height(int) : The initial height
        """
        self.plant_name = plant_name
        self.water_level = water_level
        self.sunlight_hours = sunlight_hours


class GardenError(Exception):
    """
    Base class for all garden-related exceptions
    """

    def __init__(self, plant: Plant):
        """
        Initialize an instance of the GardenError class
        Args:
            name(str) : the name of the plant
            waterlevel(int) : water level associated with the error state
        """
        self.name = plant.plant_name
        self.waterlevel = plant.water_level
        self.sunlight_hours = plant.sunlight_hours


class PlantNameError(GardenError):
    """
    Exception raised when a plant name is missing or invalid
    """

    def __str__(self) -> str:
        return "Error adding plant: Plant name cannot be empty!"


class WaterlevelError(GardenError):
    """
    Exception raised when a plant's water requirement
    exceeds health safety limit
    """

    def __str__(self) -> str:
        return (
            f"Error checking {self.name}"
            f"Water level {self.waterlevel} is too high (max 10)"
        )


class SunlightHourError(GardenError):
    """
    Exception raised when sunlight hours are outside
    the safe biological range
    """

    def __str__(self) -> str:
        return f"Error: Sunlight hours {self.sunlight_hours}" f" is too hight (max 10)"


class WaterError(GardenError):
    """
    Exception raised when the garden's water supply
    is insufficient.
    """

    def __str__(self):
        return "Caught WaterError: Not enough water in tank!"


class GardenManager:
    """
    Garden management system. Handles plant addition,
    growth, and statistics management.
    """

    def __init__(self, tank_capacity=30):
        """
        Initialize the GardenManager.
        """
        self.plants = []
        self.tank_capacity = tank_capacity

    def add_plant(self, plant: Plant) -> None:
        """
        Add a general plant to the garden.

        Args:
            plant (Plant): The Plant object to add.
        """
        try:
            if plant.plant_name is None:
                raise PlantNameError(plant)
        except PlantNameError as e:
            print(e)
            return
        self.plants.append(plant)
        print(f"Added {plant.plant_name} successfully")

    def water_plants(self) -> None:
        """
        Waters all registered plants and manages tank depletion
        """
        print("Watering plants...")
        print("Opening watering system")
        try:
            for plant in self.plants:
                if self.tank_capacity < plant.water_level:
                    raise WaterError(plant)
                print(f"Watering {plant.plant_name} - success")
                self.tank_capacity -= plant.water_level
        except WaterError as e:
            print(e)
            print("System recovered and continuing...")
        except (TypeError, IndexError):
            print("Error: Cannot water None - invalid plant!")
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self) -> None:
        """
        check the health status of all plants in the garden.
        Checks for waterlevelError and SunlightHourError
        for each plant.
        """
        print("Checking plant health...")
        for plant in self.plants:
            try:
                if plant.water_level > 10:
                    raise WaterlevelError(plant)
                if plant.sunlight_hours < 2:
                    raise SunlightHourError(plant)
            except (WaterlevelError, SunlightHourError) as e:
                print(e)
                return
            print(
                f"{plant.plant_name}: healthy (water: "
                f"{plant.water_level}, sun: {plant.sunlight_hours})"
            )


if __name__ == "__main__":
    print("=== Garden Management System ===")
    print()
    Garden = GardenManager()
    plants_list = [
        ["tomato", 10, 8],
        ["lettuce", 15, 9],
        [None, 10, 10],
    ]
    print("Adding plants to garden...")
    Garden.add_plant(Plant(*plants_list[0]))
    Garden.add_plant(Plant(*plants_list[1]))
    Garden.add_plant(Plant(*plants_list[2]))
    print()
    Garden.water_plants()
    print()
    Garden.check_plant_health()
    print()
    print("Testing error recovery...")
    try:
        plant_water_huge = Plant("Tree", 100, 10)
        if Garden.tank_capacity < plant_water_huge.water_level:
            raise WaterError(plant_water_huge)
    except WaterError as e:
        print(e)
        print("System recovered and continuing...")

    print()
    print("Garden management system test complete!")
