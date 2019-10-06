def reverse(string):
    elements=[]
    stack=[]
    for i in string:
        elements.append(i)
    for _ in range(len(elements)):
        p = elements.pop()
        stack.append(p)
    return ''.join(str(i) for i in stack)

print("Enter the string you want to reverse")
print(reverse("helloworld"))