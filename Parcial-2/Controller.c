#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "peliculas.h"

/** \brief Carga las peliculas desde el archivo movies.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListMovie)
{
    FILE* f= fopen("movies.csv","r");

    if(f==NULL && pArrayListMovie==NULL)
    {
        printf("No se pudo cargar el archivo");
    }
    else
    {

        if(parser_MoviesFromText(f,pArrayListMovie))
        {
            printf("Hubo un error en cargar los empleados");
        }
        else
        {
            printf("Carga exitosa!!!!\n\n");
            system("pause");
            fclose(f);
        }

    }
    return 1;
}


int controller_ListMovie(LinkedList* pArrayListMovie)
{
    int todoOk=0;
    eMovie* auxMovie=NULL;
    if(pArrayListMovie!=NULL)
    {
        printf(" ID             Titulo                            Genero                  Rating\n\n");
        for(int i = 0 ; i<ll_len(pArrayListMovie); i++)
        {
            auxMovie=(eMovie* )ll_get(pArrayListMovie,i);
            list_movie(auxMovie);

        }
        todoOk=1;
    }

    return todoOk;
}

/** \brief Ordenar Peliculas
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListMovie)
{

    int todoOk = 0;
    int opcion;
    if ( pArrayListMovie != NULL )
    {


        for(int i =0; i = ll_len(pArrayListMovie;i++)
        {
        system("cls");

                controller_ListMovie(pArrayListMovie);

        }



    }
    return todoOk;




    return 1;
}

/** \brief Guarda los datos de las peliculas (modo texto).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListMovie)
{
    int todoOk = 0;
    FILE* f;
    int id_peli;
    char titulo[50];
    char genero[50];
    float rating;
    eMovie* auxMovie;

    if ( path != NULL && pArrayListMovie != NULL )
    {

        f = fopen(path, "w"); // abro el archivo
        if ( f == NULL )
        {
            printf("No se pudo abrir el archivo\n");

        }

        fprintf( f, "Id,Titulo,Genero,Rating\n" );

        for (int i = 0; i < ll_len(pArrayListMovie); i++)
        {
            auxMovie = ll_get(pArrayListMovie, i);
            if (    movie_getId( auxMovie, &id_peli ) &&
                    movie_getTitulo( auxMovie, titulo ) &&
                    movie_getGenero( auxMovie, genero) &&
                    movie_getRating(auxMovie, &rating)
               )
            {
                fprintf(f, "%d,%s,%s,%f\n", id_peli, titulo, genero, rating);
                todoOk = 1;
            }
        }
        system("cls");
        printf("\nGuardado correctamente en Movies1.CSV.\n");
        system("pause");
    }
    fclose(f);
    return todoOk;
}

controller_setearRating(LinkedList* pArrayListMovie)
{
    int todoOk=0;
    int random;
    eMovie* auxMovie=NULL;

    if(pArrayListMovie!=NULL)
    {


        for(int i = 0 ; i<ll_len(pArrayListMovie); i++)
        {
            auxMovie=(eMovie*)ll_get(pArrayListMovie,i);
            random=rand() % (4-1+1)+1;

            switch(random)
            {
            case 1:
                movie_setGenero(auxMovie,"Drama");
                break;
            case 2:
                movie_setGenero(auxMovie,"Comedia");
                break;
            case 3:
                movie_setGenero(auxMovie,"Comedia");
                break;
            case 4:
                movie_setGenero(auxMovie,"Comedia");
                break;
            }

        }
        todoOk=1;
    }

    return todoOk;
}
