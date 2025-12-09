val = 50
zero_crossing = 0

with open("input.txt", "r") as f:
    for line in f:
        word = line.strip()
        direction = word[0]
        num = int(word[1:])

        # Step per click
        step = 1 if direction == "R" else -1

        for _ in range(num):
            val = (val + step) % 100
            if val == 0:
                zero_crossing += 1

print(zero_crossing)
