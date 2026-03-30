# Java

- O mais utilizado é da Oracle
- Open JDK
- Nome do arquivo tem que ser o mesmo da classe
- javac meuPrograma.java- compila
- Java meuPrograma.java - executa em uma máquina virtual
- private - esse membro só pode ser acessado dentro da própria classe onde foi definido
	- Variáveis são privadas, se quiser saber o valor, deve-se criar um método
	- **ENCAPSULAMENTO**
- Construtor é um método que tem o mesmo nome da classe
	- podemos ter mais que um construtor
- Java tem verificação estática de tipos (Python não)
- Comentários igual C
- Operadores tipo C
- Em Java é obrigatório em muitos casos fazer o Casting
- Variáveis podem ser declaradas na hora que forem usadas

### Tipos

- int - 4 bytes
- long - 8 bytes
- float - 4 bytes
- double - 8 bytes
- char - 2 bytes
- short - 2 bytes
- byte - 1 byte
- boolen - 1 bit

## Comandos

- Igual a C:
	- if
	- switch case
	- for
	- while
	- do-while

- for (int k : v)
	- tipo aquele for do Python, que pega os elementos da lista no índice

- break
	- podemos ter um rótulo que indica qual comando quebrar
	- break label1

## Exceções

- fscanf(arq, "%d", &k)
```java
if (fscanf(arq, "%d", &k) != 1){
	printf("Erro na leitura do arquivo");
	return -1;
}
```

```java
try{
}
catch(Exception e){
	System.out.println("Erro ao ler o arquivo")
}
```

- Tratamento de exceções