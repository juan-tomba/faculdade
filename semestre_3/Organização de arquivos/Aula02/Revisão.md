- **Arquivo**: Sequência de bytes armazenados no disco (armazenamento secundário)
- Um arquivo contém **n** páginas de disco, uma página de disco contém dados de **UM** arquivo
- Para melhor desempenho, diminuímos o **Número de acessos a disco**


- **Exemplo de algoritmo**
```clike
if a página de disco está em RAM:
	usa a página sem acessos a disco
	else:
		acessa o disco para transferir 1 página de disco para RAM
		if existe espaço disponível na RAM:
			escreve a página de disco em RAM
		else: //falha de página //Políticas de substituição de páginas (LRU)
			Aplico política de substituição e escolho a página X
			if a página X foi alterada:
				escreve a página X no disco
			escreve a página de disco em RAM
```

- **Least Recently Used(LRU)**: é um algoritmo de substituição de cache e memória virtual que remove o item acessado há mais tempo quando o cache atinge sua capacidade máxima.