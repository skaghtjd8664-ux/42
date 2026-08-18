def ft_count_harvest_recursive():
    num = int(input("Days until harvest: "))

    def helper(day):
        if day > num:
            print("Harvest time!")
            return
        print(f"Day {day}")
        helper(day + 1)
    helper(1)
    
