def mutate_string(string, position, character):
    string_list = list(string)
    string_list[position] = character
    string_list_new = ''.join(string_list)
    return string_list_new


if __name__ == '__main__':
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)