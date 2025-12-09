val = 50
zero_crossing = 0

with open("input.txt", "r") as f:
    for line in f:
        word = line.strip()
        direction = word[0]
        num = int(word[1:])

        if direction == "R":
            val = (val + num) % 100
        elif direction == "L":
            val = (val - num + 100) % 100

        if val == 0:
            zero_crossing += 1
print(zero_crossing)
