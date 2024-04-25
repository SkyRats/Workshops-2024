class Drone:
    def __init__(self, manufacturer, model, max_speed):
        self.manufacturer = manufacturer
        self.model = model
        self.max_speed = max_speed  # in meters per second

    # Method to fly the drone
    def fly(self):
        print("The drone is flying.")

    # Method to get drone details
    def get_details(self):
        print("Manufacturer:", self.manufacturer)
        print("Model:", self.model)
        print("Max Speed:", self.max_speed, "m/s")

# Creating an instance of Drone
drone = Drone("DJI", "Mavic Air", 20.0)

# Flying the drone
drone.fly()

# Getting drone details
drone.get_details()
