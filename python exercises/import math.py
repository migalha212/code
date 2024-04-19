import math

# Input angle in degrees
angle_degrees = int(input())

# Convert angle to radians
angle_radians = angle_degrees * math.pi / 180

# Constants
velocity = 18  # m/s
gravity = -10  # m/s²

# Calculate horizontal distance
horizontal_distance = (velocity ** 2) * math.sin(2 * angle_radians) / (-gravity)

# Round the result and print
rounded_distance = round(horizontal_distance)
print(rounded_distance)