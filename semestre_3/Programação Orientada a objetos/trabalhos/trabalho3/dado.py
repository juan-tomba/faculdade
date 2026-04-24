import random

class Dado:
    def __init__(self, lados=6, seed=None):
        self.lados = lados
        self.random = random.Random(seed)
        self.valor = self.random.randint(1, lados)

    def rolar(self):
        self.valor = self.random.randint(1, self.lados)
        return self.valor

    def getLado(self):
        return self.valor

    def __str__(self):
        return str(self.valor)