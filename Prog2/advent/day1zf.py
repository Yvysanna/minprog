with open('data.txt') as data:
    data = data.readlines()

    arr = [0]
    idx = 0

    for value in data:
        if value != '\n':
            arr[idx] += int(value)
        else:
            arr.append(0)
            idx += 1

    print(sorted(arr, reverse=True)[0:3])