#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"
int main()
{
    srand(time(NULL));
    char seguir = 's';
    LinkedList* listaPost = ll_newLinkedList();
    char cadenaArchivo[20];

    do
    {
           system("cls");
            switch (menu())
            {
            case 1:
                printf("Nombre del Archivo a cargar (posts)\n");
                fflush(stdin);
                gets(cadenaArchivo);
                strcat(cadenaArchivo, ".csv");
                if ( !controller_loadFromText(cadenaArchivo, listaPost) )
                {
                    printf("Error al cargar desde texto\n");
                }
                system("cls");
                break;
            case 2:
                 if ( !controller_ListPost(listaPost) )
                {
                    printf("Error al listar post\n");
                }
                system("pause");
                break;
            case 3:
                 if ( !controller_map(listaPost) )
                {
                    printf("Error al listar post\n");
                }
                    system("pause");
                break;
            case 4:

                if ( !controller_filterLikes(listaPost))
                {
                    printf("Error al listar post\n");
                }
                    system("pause");
                break;
            case 5:
                 if ( !controller_filterhate(listaPost))
                {
                    printf("Error al listar post\n");
                }
                    system("pause");
               break;
            case 6:
                controller_ordenarPost(listaPost);
                break;
            case 7:
                break;
            case 8:
               seguir='n';
                break;
            default:
                printf("Opcion invalida\n");
            }

        }while(seguir == 's');
        return 0;
    }






