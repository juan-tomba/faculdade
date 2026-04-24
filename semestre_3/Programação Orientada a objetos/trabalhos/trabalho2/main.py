import math
import sys
from tabuleiro import Tabuleiro


def entrada_tab(linha):
    partes = linha.strip().split()
    # calcula tamanho N da matriz
    n = int(math.sqrt(len(partes)))
    # converte tudo de string pra int
    config = list(map(int, partes))
    return Tabuleiro(n, config)


def main():
    # lê tudo de uma vez
    linhas = sys.stdin.read().splitlines()
    # tratamento de erro se linha estiver vazia
    if len(linhas) == 0:
        return
    # a primeira linha define inicialização
    tabuleiro = entrada_tab(linhas[0])

    if len(linhas) > 1:
        tabuleiro.execMov(linhas[1])


if __name__ == "__main__":
    main()