# Returns 'n' tetrahedral numbers


def tetrahedral_number(n):
    if n <= 0:
        raise ValueError('"n" must be greater than or equal to 1')

    if n == 1:
        tetra_number = 1
        tri_number = 1
    else:
        tri_number, tetra_number = tetrahedral_number(n - 1)

        tri_number = tri_number + n
        tetra_number = tetra_number + tri_number

    print(f'{n} Tetrahedral -> {tetra_number}')

    return tri_number, tetra_number


nt = input('(n): ')
try:
    nt = int(nt)
except ValueError:
    print('Invalid number.')

tetrahedral_number(nt)
