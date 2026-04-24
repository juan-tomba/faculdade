class Tabuleiro:
    def __init__(self, tam, config):
        self.size = tam
        # cria a matriz quadrada vazia
        self.table = [[0] * tam for _ in range(tam)]

        k = 0
        for i in range(tam):
            for j in range(tam):
                self.table[i][j] = config[k]
                # salva onde ta o zero pra saber quem movimentar
                if config[k] == 0:
                    self.posX = i
                    self.posY = j
                k += 1

        self.imprimir()

    def execMov(self, movimentos):
        for m in movimentos:
            # tenta mover o espaco vazio
            if m == 'u':
                self.trocar(self.posX + 1, self.posY)
            elif m == 'd':
                self.trocar(self.posX - 1, self.posY)
            elif m == 'l':
                self.trocar(self.posX, self.posY + 1)
            elif m == 'r':
                self.trocar(self.posX, self.posY - 1)

            self.imprimir()

        # mostra se o resultado ta certo
        if self.jogo_certo():
            print("Posicao final: True")
        else:
            print("Posicao final: False")

    def imprimir(self):
        borda = "+"
        for _ in range(self.size):
            borda += "------+"

        for i in range(self.size):
            print(borda)
            for j in range(self.size):
                print("|", end="")
                valor = self.table[i][j]
                saida = " " if valor == 0 else valor
                if valor > 9:
                    print(f"  {saida}  ", end="")
                else:
                    print(f"   {saida}  ", end="")
            print("|")
        print(borda)
        print()

    def jogo_certo(self):
        num = 1
        for i in range(self.size):
            for j in range(self.size):
                # o zero tem que estar na primeira posicao (0,0)
                if i == 0 and j == 0:
                    if self.table[i][j] != 0:
                        return False
                else:
                    # o resto tem que estar em ordem crescente
                    if self.table[i][j] != num:
                        return False
                    num += 1
        return True

    def trocar(self, i, j):
        # so troca se a posicao nova estiver dentro do tabuleiro
        if 0 <= i < self.size and 0 <= j < self.size:
            self.table[i][j], self.table[self.posX][self.posY] = \
                self.table[self.posX][self.posY], self.table[i][j]
            # atualiza a posicao oficial do zero
            self.posX = i
            self.posY = j