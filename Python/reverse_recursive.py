word = "hello"

def reverse_recursive(word):
	x = ""
	if len(word) != 1:
		x = reverse_recursive(word[1:])
		
	return x + word[0]
	

print(reverse_recursive(word))
