#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"
int menu(){

    int opcionElegida;

    printf("\n                ****  Menu de Opciones  **** \n\n");
    printf("1.  Cargar desde Archivo post.csv.\n\n");
    printf("2. Listar post \n\n");
    printf("3. Asignar Estadisticas\n\n");
    printf("4. Filtrar mejores Posteos\n\n");
    printf("5. Filtrar por Haters\n\n");
    printf("6. Ordenar por cantidad de Followers \n\n");
    printf("7. Mostrar mas popular\n\n");
    printf("8.Salir\n\n");
    printf( "\nIngrese la opcion correspondiente: \n");

    scanf("%d",&opcionElegida);

    return opcionElegida;
}

