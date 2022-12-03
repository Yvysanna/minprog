# 1 7878
with open('day3.txt', 'r') as infile:
    rucksacks = infile.readlines()

    items = list()
    for rucksack in rucksacks:
        left, right = set(rucksack[:len(rucksack)//2]), set(rucksack[len(rucksack)//2:])
        items.extend(left.intersection(right))

    # Calculate score based on ascii
    total = sum([ord(item) - 96 if ord(item) >= 97 else ord(item) - 38 for item in items])
print(total)

# 2 2760
with open('day3.txt', 'r') as infile:
    rucksacks = infile.read().split('\n')
    rucksacks = [rucksacks[i:i+3] for i in range(0, len(rucksacks), 3)]

    # Check which items all elves have in common
    items = list()
    items.extend(set(rucksack[0]) & set(rucksack[1]) & set(rucksack[2]) for rucksack in rucksacks)      

    # Get intersection out of set
    items = list(map(set.pop, items))
        
    # Calculate score 
    total = sum([ord(item) - 96 if ord(item) >= 97 else ord(item) - 38 for item in items])
print(total)