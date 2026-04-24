import dado as dd
from random import Random

class RolaDados:
    def __init__(self, n=5, seed=0):
        self.dados = []
        
        if seed != 0:
            rd = Random(seed)
        else:
            rd = Random()

        for i in range(n):
            self.dados.append(dd.Dado(6, rd.randint(1, 10000)))

    def rolar(self, quais=None):
        if quais is None:
            # rola todos
            for d in self.dados:
                d.rolar()
        else:
            for i in quais:
                self.dados[i-1].rolar()  # índice começa em 1

    def valores(self):
        return [d.getLado() for d in self.dados]

    def __str__(self):
        return " ".join(str(d) for d in self.dados)