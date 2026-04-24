from roladados import RolaDados
from placar import Placar

class Bozo:
    
    def main():
        try:
            seed = int(input("Digite a semente (zero para aleatório): "))
        except:
            seed = 0
            
        r = RolaDados(5, seed)
        p = Placar()

        print(p)

        for rodada in range(1, 11):
            print(f"\n****** Rodada {rodada}")
            print("Pressione ENTER para lançar os dados")
            try:
                input()
            except EOFError:
                pass

            # 1ª rolagem
            r.rolar()
            imprimir_dados(r.valores())

            # 2ª
            print("\nDigite os números dos dados que quiser TROCAR. Separados por espaços.")
            try:
                troca = input()
                if troca.strip():
                    quais = []
                    for x in troca.split():
                        if x.isdigit():
                            num = int(x)
                            if 1 <= num <= 5 and num not in quais:
                                quais.append(num)
                    if quais:
                        r.rolar(quais)
            except EOFError:
                pass
            imprimir_dados(r.valores())

            # 3ª
            print("\nDigite os números dos dados que quiser TROCAR. Separados por espaços.")
            try:
                troca = input()
                if troca.strip():
                    quais = []
                    for x in troca.split():
                        if x.isdigit():
                            num = int(x)
                            if 1 <= num <= 5 and num not in quais:
                                quais.append(num)
                    if quais:
                        r.rolar(quais)
            except EOFError:
                pass
            imprimir_dados(r.valores())

           
            print("\n\n\n")
            print(str(p) + "\n")
           
            
            while True:
                try:
                    pos = int(input("Escolha a posição que quer ocupar com essa jogada ===> "))
                    p.add(pos, r.valores())
                    break
                except ValueError:
                    print("Valor inválido. Posição ocupada ou inexistente.")
                except EOFError:
                    break
            
            # \n salvador da pátria
            print("\n")
            print("\n" + str(p))

        print("\n***********************************")
        print("***")
        print(f"*** Seu escore final foi: {p.getScore()}")
        print("***")
        print("***********************************")

# func auxiliar
def monta_dados(valor):
    faces = {
        1: ["|     |",
            "|  *  |",
            "|     |"],

        2: ["|*    |",
            "|     |",
            "|    *|"],

        3: ["|*    |",
            "|  *  |",
            "|    *|"],

        4: ["|*   *|",
            "|     |",
            "|*   *|"],

        5: ["|*   *|",
            "|  *  |",
            "|*   *|"],

        6: ["|* * *|",
            "|     |",
            "|* * *|"]   
    }
    return faces[valor]

def imprimir_dados(valores):
    s = ""
    for i in range(len(valores)):
        if i == len(valores) - 1:
            s += f"{i+1}"
        else:
            s += f"{i+1}          "
    print(s)

    linhas = ["", "", "", "", ""]

    for v in valores:
        face = monta_dados(v)
        linhas[0] += "+-----+    "
        linhas[1] += f"{face[0]}    "
        linhas[2] += f"{face[1]}    "
        linhas[3] += f"{face[2]}    "
        linhas[4] += "+-----+    "

    for l in linhas:
        print(l)


if __name__ == "__main__":
    Bozo.main()