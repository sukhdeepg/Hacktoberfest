word = input()

reverse = ''
for i in range(len(word) -1, -1, -1):
    reverse += word[i]

print(reverse)
