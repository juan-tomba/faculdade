

void mover(int n, char origem, char temporaria, char destino){
    if (n == 1){
        printf("Mova o disco 1 da haste %c para a haste %c", origem, destino);
    }
    else{
        mover(n - 1, origem, destino, temporaria);
        printf("")
    }
}