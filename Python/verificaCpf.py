def calcula_digitos_verificacao(cpf):

    multiplicador = 2
    somador = 0
    for i in range(len(cpf) - 1, - 1, -1):

        somador += int(cpf[i]) * multiplicador
        multiplicador += 1

        primeiro_digito = str((somador * 10) % 11)

    if primeiro_digito == '10':
        primeiro_digito = '0'

    cpf = cpf + primeiro_digito

    multiplicador = 2
    somador = 0
    for e in range(len(cpf) - 1, - 1, -1):

        somador += int(cpf[e]) * multiplicador
        multiplicador += 1

        segundo_digito = str((somador * 10) % 11)

    if segundo_digito == '10':
        segundo_digito = '0'

    return primeiro_digito + segundo_digito
