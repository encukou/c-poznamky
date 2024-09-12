# Uses rur.txt from: https://www.gutenberg.org/cache/epub/13083/pg13083.txt

with open('rur.txt', 'r') as f1:
    with open('rur-processed.txt', 'w') as f2:
        for line in f1:
            prcoessed = ""
            for char in line:
                if char.isalpha():
                    prcoessed += char.lower()
                elif char in [' ', '\n']:
                    prcoessed += char
            f2.write(prcoessed)

print("done")
