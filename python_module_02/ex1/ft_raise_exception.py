<<<<<<< HEAD
def input_temperature(temp_str: str) -> int:
=======
def input_temperature(temp_str : str) -> int:
>>>>>>> cf50b79 (finish py02)
    temp = int(temp_str)

    if temp > 40:
        raise ValueError(f"{temp}°C is too hot for plants (max 40°C)")

    if temp < 0:
        raise ValueError(f"{temp}°C is too cold for plants (min 0°C)")

    return temp

<<<<<<< HEAD

=======
>>>>>>> cf50b79 (finish py02)
def test_temperature() -> None:
    print("=== Garden Temperature Checker ===")
    print("")

<<<<<<< HEAD
    test_values = ["25", "abc", "100", "-50"]
=======
    test_values =["25", "abc", "100", "-50"]
>>>>>>> cf50b79 (finish py02)

    for value in test_values:
        print(f"Input data is '{value}'")
        try:
            temp = input_temperature(value)
            print(f"Temperature is now {temp}°C")
        except Exception as e:
            print(f"Caught input_temperature error: {e}")
        print("")

<<<<<<< HEAD
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
=======
        print("All tests completed - program didn't crash!")

if __name__ == "__main__":
    test_temperature()
>>>>>>> cf50b79 (finish py02)
