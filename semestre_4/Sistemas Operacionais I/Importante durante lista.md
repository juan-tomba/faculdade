- trap - instrução que permite o acesso ao modo kernel
- *multiprogramação* - varios processos na memória concorrendo por uma CPU
- *multiprocessamento* ter mais de uma CPU, com paralelismo real
- *multitarefa*
- troca de contexto - "Antes de parar o processo A, o sistema precisa **guardar o estado atual dele**. Depois, precisa **carregar o estado que o processo B tinha quando foi interrompido**."
	- O estado fica registrado no **BCP (Bloco de Controle do Processo)**.

- Transições

# Diagrama de Estados de um Processo

```text
                     criar
                       │
                       ▼
                  ┌─────────┐
                  │  Pronto │◄──────────────────┐
                  └────┬────┘                   │
                       │ despachar              │
                       ▼                        │
                  ┌───────────┐                 │
                  │Executando │                 │
                  └─┬─────┬──┘                 │
                    │     │                     │
              bloquear     │ destruir           │
                    │     │                     │
                    ▼     ▼                     │
              ┌──────────┐ ┌─────────┐           │
              │Bloqueado │ │Destruído│           │
              └────┬─────┘ └─────────┘           │
                   │                             │
                 acordar                         │
                   │                             │
                   └─────────────────────────────┘

Executando ───── preempção/suspender ─────► Pronto
```

- **FCFS / FIFO** - Ordem de requisição; fácil de programar. Ineficiente com processos demorados
- **SJF** - menores primeiros (que ja chegaram)
- **SRTN** - Menor tempo restante possível (meio dinamico), suspende o atual se o novo for menor, meior ruim pq fica trocando de processo (**TEMPO DE CHAVEAMENTO**)
- *Região crítica*
	- Dois processos não podem estar simultaneamente na região crítica; 
	- Não se podem fazer suposições sobre velocidade e número de CPUs; 
	- Um processo fora da região crítica não deve bloquear outro; 
	- Um processo não pode esperar infinitamente para entrar.
- o down do semáforo de sincronização vem sempre antes do down do mutex.
- 