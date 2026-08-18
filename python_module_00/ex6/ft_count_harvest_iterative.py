def ft_count_harvest_iterative():
    num = int(input("Days until harvest: "))
    i = 1
    while i <= num:
        print(f"Day {i}")
        if i == num:
            print("Harvest time!")
        i += 1