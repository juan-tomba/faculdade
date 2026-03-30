
## Fatos curiosos

Trabalho só pode ser feito em C, vamos mexer com arquivos
Utilizar registros fixos
Modularizar código
- fopen(string nome_arquivo, modo_abertura)
	- Texto(csv): w, r, a
	- Binários: wb, rb, ab, r + h
	- Escolher o modo certo
- fclose()
- fread(buffer, sizeof(), qntd, File)
- fwrite(buffer, sizeof(), qntd, File)
- ftell(File* )
	- Operação cara, cuidado ao usar
	- NÃO USAR DENTRO DE LOOP
- fseek(File*, qntd, flag)
	- 0, seek_set  *// começo do arquivo*
	- n>0, seek_set  *// vai até N*
	- -1, seek_set  *// volta um*
	- Cuidado ao usar, pode estragar seu disco
	- Vamos considerar que fseek funciona 100% das vezes

```c
struct{
	char status;
	int num_est;
	int num_pares;
	// desse jeito, essa struct tem 12 bytes (padding), o sistema completa os bytes do char para 4
	//em vez de usar fread na struct, DE Fread CAMPO A CAMPO
}
```

## Especificação do trabalho

- Registro tem 80 bytes
- 7 minutos de vídeo apresentando o trabalho