- *Problema*: Algumas dependências param a pipeline e fazem com que não se tenha essa instrução finalizada por ciclo de clock. Isso é um **HAZARD**
- *Soluções*:
	- **Compilador/montador** Insere instruções **NOP** para criar atrasos e evitar conflitos.
	- **Arquitetura**
		- 1) Parar o pipeline (stall) até que a instrução que produz o resultado chegue no estágio de Write Back (WB)
		- 2) Unidade de Forwarding (antecipação) : usamos o resultado já pronto no pipeline para a instrução que precisa desse resultado


## Unidade de Forwarding



## Observação

- **Hazard de dados (data hazard)**: ocorre quando uma instrução precisa de um operando que ainda está sendo produzido por uma instrução anterior.
	- NOP, stall e forwarding são especificamente soluções para _data hazards_.

