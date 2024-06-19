#include <stdio.h>
#include "funciones.h"
#include <string.h>

void ingresarCliente(char clientes[][2][40]){
   
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(clientes[i][0],"")==0){
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s",clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s",clientes[i][1]);
            break;
        }
    } 
    imprimirClientes(clientes);}

void imprimirClientes(char clientes[][2][40]){
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t\t%s\n",clientes[i][0],clientes[i][1]);
    }   }

void listarPeliculas(char peliculas[][4][40]){
    for (int i = 0; i < 10; i++)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
    }  }

void buscarporNombre(char peliculas[][4][40]){
    char nombrePeliculas[40];
    printf("Que pelicula desea buscar?\n");
    scanf("%s",nombrePeliculas);
    for(int i=0; i<10;i++){
        if(strcmp(peliculas[i][1],nombrePeliculas)==0){
            printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }}

void buscarporGenero(char peliculas[][4][40]){
    char nombreGenero[40];
    printf("Que genero de pelicula desea buscar?\n");
    scanf("%s",nombreGenero);
    for(int i=0; i<10;i++){
        if(strcmp(peliculas[i][3],nombreGenero)==0){
            printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }}

void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    char cedula[40];
    int encontrado = -1;

    for (int k = 0; k < 10; k++) {
        if (reserva[k][0] == -1) {
            printf("Ingrese su cedula: ");
            scanf("%s", cedula);
            getchar();
            
            for (int i = 0; i < 5; i++) {
                if (strcmp(clientes[i][1], cedula) == 0) {
                    encontrado = i;
                    reserva[k][1] = i;
                    break;
                }
            }

            if (encontrado == -1) {
                printf("Cedula no encontrada.\n");
                return;
            }

            listarPeliculas(peliculas);
            printf("Ingrese el numero de la pelicula: ");
            scanf("%d", &reserva[k][0]);
            printf("El valor de la pelicula es: %d\n", reserva[k][0]);

            printf("Tipos de entrada:\n 0  Normal ($7)\n 1  Ninos ($3.5)\n 2  Adulto mayor ($3)\n");
            printf("Ingrese el tipo de entrada: ");
            scanf("%d", &reserva[k][2]);

            printf("Ingrese la cantidad de entradas: ");
            scanf("%d", &reserva[k][3]);

            double total = reserva[k][3] * precio[reserva[k][2]];
            printf("Compra realizada exitosamente. Total: $%.2f\n", total);
            break;
        }
    }
}
             
void verCompras(char peliculas[][4][40],double precio[], char clientes[][2][40],int reserva[][4]){
    char cedula[40];
    int found = -1;

    printf("Ingrese su cedula: \n");
    scanf("%s", cedula);
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            found = i;
            break;
        }
    }
    for (int a = 0; a < 10; a++){
        if(reserva[a][1]==found){
            printf("%s\t\t%s\t\t%.2f\t\t%d\n",peliculas[reserva[a][0]-1][1],clientes[reserva[a][1]][0],precio[reserva[a][2]],reserva[a][3]); 
            
        }
    } 

    
    
}  
