
- A próxima instrução não está no endereço subsequente ao da instrução em execução

## Possíveis Soluções

1. Congelar o pipeline até saber o endereço destino (insere bolhas no pipeline)
2. Considerar que o desvio não será tomado e, portanto continua no fluxo sequencial
3. Reduzir o atraso dos desvios
4. Utilização do Delayed Branch (desvio atrasado)
	- A instrução após o desvio é sempre executada
	- A próxima instrução é chamada Delay Slot (posição de atraso)
5. Predição
	- Tenta prever o comportamento do desvio
	- **Estática**
		- Não permite adaptações com relação ao complemento do programa
	- **Dinâmica**
		- Existem mecanismos de hardware que fazem a previsão baseada no comportamento daquele desvio no passado
