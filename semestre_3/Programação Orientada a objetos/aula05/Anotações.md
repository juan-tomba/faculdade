# Jogo do Bozó

- Vai ser fornecido o código em Java
- (fornecido no JavaDoc)
- Devemos entender e implementar em Python :(
### Classe Dado

- getLado()
- rolar()
- toString()
	- em python usamos \__str\__ (self)

### Classe RolaDados

- *Classe auxiliar para gerenciar um conjunto de vários dados simultaneamente*
- rolar(...)
- toString()

### Classe Placar

- *Representa o placar do jogo*
- add(...)
- getScore()
- toString()

### Classe Bozo

- *classe principal*
- método main:

```
Criar um objeto RolaDados e um objeto Placar
Repetir 10x (uma por rodada)
	Pedir para o usuário pressionar ENTER para iniciar a rodada
	Rolar os dados e exibir o resultado (1° vez)
	Pedir para o usuário escolher os dados a serem rolados
	Rolar os dados que o usuário selecionou (2° vez)
	Pedir para o usuário escolher os dados a serem rolados
	Rolar os dados que o usuário selecionou (3° vez)
	
	Mostrar o placar atual
	Pedir para o usuário selecionar a posição que quer ocupar
	Mostrar o placar atualizado
	
No final, mostrar o número de pontos obtidos
```

