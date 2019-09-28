while True:
    try:
        age = int(input("What is your age"))
        break
    except:
        print("Please input a valid number")


print age
