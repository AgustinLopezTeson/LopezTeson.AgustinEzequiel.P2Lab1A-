#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "peliculas.h"

/** \brief Parsea los datos los  (modo texto).
 *
 * \param path char*
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int parser_MoviesFromText(FILE* pFile , LinkedList* pArrayListMovie)
{
    int todoOk=1;
    int cant;
    char buffer[4][150];
    eMovie * aux=NULL;

            fscanf(pFile,"%[^,],%[^,],%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            while(!feof(pFile)){
                    aux=new_movie();
                    if(aux!=NULL)
                    {
                        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                        movie_setId(aux,atoi(buffer[0]));
                        movie_setTitulo(aux,buffer[1]);
                        movie_setGenero(aux,buffer[2]);
                        movie_setRating(aux,atof(buffer[3]));

                        ll_add(pArrayListMovie,aux);

                        todoOk=0;
                    }
                        if(cant<4){
                            break;
                        }
                }

    return todoOk;
}

