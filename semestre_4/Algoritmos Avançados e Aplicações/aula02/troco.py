n = 3
moedas = [1, 7, 10, 2]

def resolve(n, moedas):

    if n == 0:
        return True

    if n < 0:
        return False

    if len(moedas) == 0:
        return False

    a = resolve(n-moedas[0], moedas[1:])
    b = resolve(n, moedas[1:])

    return a or b


def main():
    print(resolve(n, moedas))

if __name__ == '__main__':
    main()