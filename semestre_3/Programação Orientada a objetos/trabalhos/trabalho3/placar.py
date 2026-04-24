class Placar:
    
    def __init__(self):
        self.posicoes = [None] * 10  # 10 posições

    def add(self, pos, dados):
        if pos < 1 or pos > 10:
            raise ValueError("Posição inexistente")
        if self.posicoes[pos-1] is not None:
            raise ValueError("Posição já ocupada")

        cont = [0]*7  # índice 1..6
        for d in dados:
            cont[d] += 1

        pontos = 0

        # 1 a 6
        if 1 <= pos <= 6:
            pontos = cont[pos] * pos

        # full house
        elif pos == 7:
            if 3 in cont and 2 in cont:
                pontos = 15

        # sequência
        elif pos == 8:
            if cont[1]==1 and cont[2]==1 and cont[3]==1 and cont[4]==1 and cont[5]==1:
                pontos = 20
            elif cont[2]==1 and cont[3]==1 and cont[4]==1 and cont[5]==1 and cont[6]==1:
                pontos = 20

        # quadra
        elif pos == 9:
            if max(cont) >= 4:
                pontos = 30

        # quina
        elif pos == 10:
            if max(cont) == 5:
                pontos = 40

        self.posicoes[pos-1] = pontos

    def getScore(self):
        return sum(p for p in self.posicoes if p is not None)

    def __str__(self):
        def val(i):
            if self.posicoes[i] is None:
                return f"({i+1})"
            else:
                return str(self.posicoes[i])
        
        def fmt_left(s):
            if s.startswith('('):
                return f"{s:7}"
            else:
                return f" {s}".ljust(7)

        def fmt_mid(s):
            if s.startswith('('):
                if len(s) == 3: # (7), (8), (9)
                    return f"   {s}    "
                else:           # (10)
                    return f"   {s}   "
            else:
                if len(s) == 1:
                    return f"    {s}     "
                else:
                    return f"    {s}    "
        
        def fmt_right(s):
            if s.startswith('('):
                return f"  {s} "
            else:
                if len(s) == 1:
                    return f"   {s}  "
                else:
                    return f"   {s} "
        
        s = ""
        s += f"{fmt_left(val(0))}|{fmt_mid(val(6))}|{fmt_right(val(3))}\n"
        s += "-------|----------|-------\n"
        s += f"{fmt_left(val(1))}|{fmt_mid(val(7))}|{fmt_right(val(4))}\n"
        s += "-------|----------|-------\n"
        s += f"{fmt_left(val(2))}|{fmt_mid(val(8))}|{fmt_right(val(5))}\n"
        s += "-------|----------|-------\n"
        s += f"       |{fmt_mid(val(9))}|\n"
        s += "       +----------+"

        return s