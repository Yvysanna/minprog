with open('data.txt') as data:
    print(sorted([sum([int(x) for x in l.split('\n')]) for l in data.read().split('\n\n')], reverse=True)[0:3])
