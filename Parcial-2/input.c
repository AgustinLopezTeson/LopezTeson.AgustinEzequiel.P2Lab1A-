#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "peliculas.h"
int menu(){

    int opcionElegida;

    printf("\n                ****  Menu de Opciones  **** \n\n");
    printf("1.  Cargar desde Archivo Movies.csv.\n\n");
    printf("2. Listar peliculas \n\n");
    printf("3. Asignar Rating\n\n");
    printf("4. Asignar Genero\n\n");
    printf("5. Filtrar por genero\n\n");
    printf("6. Ordenar Peliculas \n\n");
    printf("7. Guardar peliculas\n\n");
    printf("8.Salir\n\n");
    printf( "\nIngrese la opcion correspondiente: \n");

    scanf("%d",&opcionElegida);

    return opcionElegida;
}

