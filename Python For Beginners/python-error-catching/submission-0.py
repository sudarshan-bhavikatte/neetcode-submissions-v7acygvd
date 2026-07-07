def divide_numbers(a: str, b: str) -> None:
    try:
        a = int(a)
        b = int(b)
        print(a / b)
    except Exception as error:
        print("An error occurred:", error)



# do not modify below this line
divide_numbers("10", "2")
divide_numbers("12", "0")
divide_numbers("2", "not a number")
