#with open('data.txt') as data:
#     lines = [l.split('\n')[0] for l in data.readlines()]

#     elf = [0]; idx = 0

#     for l in lines:
#         if not l:
#             elf.append(0)
#             idx += 1
#         else: 
#             elf[idx] += int(l)

# print(elf)
# # elf.sort(reverse=True)
# # print(sum(elf[0:3]))

with open('data.txt') as data:
    print(sorted([sum([int(x) for x in l.split('\n')]) for l in data.read().split('\n\n')], reverse=True)[0:3])

    #print(data)
# test = [elf[idx] += int(l) for l in lines if l else elf.append(0) and idx += 1]