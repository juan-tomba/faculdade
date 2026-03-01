#include <stdio.h>

int main(){
    float mf,mi;
    int sec,min,horas;
    sec=0;
    min=0;
    horas=0;
    scanf("%f",&mi);
    mf=mi;
    if (mi>0.5){
        while (mf>0.5){
            mf=(mf/2);
            sec=(sec+50);
        }
    }
    min=(sec/60);
    horas=(min/60);
    sec=sec%60;
    printf("A massa inicial eh %.2fg, a massa final eh %.2fg, e o tempo para a massa ser menor que 0.5g eh %d horas, %d minutos e %d segundos", mi,mf,horas,min,sec);
    return 0;
}