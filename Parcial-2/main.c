#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "peliculas.h"
int main()
{
    srand(time(NULL));
    char seguir = 's';
    LinkedList* listaPeliculas = ll_newLinkedList();

    do
    {
           system("cls");
            switch (menu())
            {
            case 1:
                if ( !controller_loadFromText("movies.csv", listaPeliculas) )
                {
                    printf("Error al cargar desde texto\n");
                }
                system("cls");
                break;
            case 2:
                 if ( !controller_ListMovie(listaPeliculas) )
                {
                    printf("Error al listar las peliculas\n");
                }
                system("pause");
            break;
            case 3:
                if ( !controller_setearRating(listaPeliculas) )
                {
                    printf("Error en setear Rating\n");
                }
                break;
            case 4:
                break;
            case 5:
               break;
            case 6:
                break;
            case 7:
                if ( !controller_saveAsText("movies1.csv", listaPeliculas) )
                {
                    printf("Error al guardar en modo texto\n");
                }
                break;
            case 8:
               seguir='n';

            default:
                printf("Opcion invalida\n");
            }

        }while(seguir == 's');
        return 0;
    }






