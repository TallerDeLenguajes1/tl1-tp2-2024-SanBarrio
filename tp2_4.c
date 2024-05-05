#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PC 5

struct compu
{
    int velocidad;  // entre 1 y 3 GHz
    int anio;       // entre 2015 y 2023
    int cantidad;   // entre 1 y 8
    char *tipo_cpu; // valores del arreglo tipos
};

void listas(struct compu pc[], int a);
void vieja(struct compu pc[], int a);
void rapida(struct compu pc[], int a);

int main()
{

    srand(time(NULL));
    struct compu PCs[MAX_PC];
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    for(int i=0; i<MAX_PC;i++){
        PCs[i].velocidad = 1 + rand() % 3;
        PCs[i].anio =  rand() % 8 + 2015;
        PCs[i].cantidad = 1 + rand() % 8;
        PCs[i].tipo_cpu = (char *) malloc(10*sizeof(char));
        strcpy(PCs[i].tipo_cpu, tipos[rand()%6]);
    }
    listas(PCs, MAX_PC);
    vieja(PCs, MAX_PC);
    rapida(PCs, MAX_PC);


    return 0;
}

void listas(struct compu pc[], int a){
    for (int i = 0; i < a; i++)
    {
        /* code */
        printf("-------------- PC Numero: %d--------------\n", i+1);
        printf("Velocidad de la PC: %d GHz\n",pc[i].velocidad);
        printf("Año de la PC: %d\n",pc[i].anio);
        printf("Nucleos de la PC: %d\n",pc[i].cantidad);
        printf("tipo de CPU de la PC: %s\n\n",pc[i].tipo_cpu);
    }
    
}

void vieja(struct compu pc[], int a){
int aux = 2025, indice;
 
for (int i = 0; i < a; i++)
    {
        if(pc[i].anio<aux){
            aux = pc[i].anio;
            indice=i;
        }
        
    }
    printf("------------- LA PC VIEJA-------------\n");
    printf("La PC Numero: %d es la mas vieja por ser del año %d\n",indice+1, pc[indice].anio);
}

void rapida(struct compu pc[], int a){
int aux = 0, indice;
 
for (int i = 0; i < a; i++)
    {
        if(pc[i].velocidad>aux){
            aux = pc[i].velocidad;
            indice=i;
        }
        
    }
    printf("------------- LA PC MAS RAPIDA-------------\n");
    printf("La PC Numero: %d es la mas rapida por tener de velocidad %d\n",indice+1, pc[indice].velocidad);
}