def ft_water_reminder():
    water_rem = int(input("Days since last watering: "))
    if water_rem > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")