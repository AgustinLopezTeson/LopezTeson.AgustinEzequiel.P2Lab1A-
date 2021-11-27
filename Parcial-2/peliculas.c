#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "peliculas.h"

eMovie* new_movie()
{

    eMovie* new_M;


    new_M = (eMovie*) malloc (sizeof(eMovie));

    if(new_M!=NULL)
    {
            new_M->id_peli= 0;
            strcpy(new_M->titulo," ");
            strcpy(new_M->genero,"");
            new_M->rating= 0.0;
    }else{

    printf("Hubo un problema");
    }

    return new_M;
}


void movie_delete(eMovie* movie)
{

    free(movie);
}

int movie_setId(eMovie* this,int id)
{
    int todoOk=0;

    if(this !=NULL && id>=0 && id<= 50000)
    {
        this->id_peli=id;
        todoOk =1;
    }

    return todoOk;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
    int todoOk=0;

    if(this != NULL && titulo!=NULL)
    {
        strcpy(this->titulo,titulo);
        todoOk =1;
    }


    return todoOk;
}

int movie_setGenero(eMovie* this,char* genero)
{
    int todoOk=0;
    if(this != NULL && genero!=NULL)
    {
        strcpy(this->genero,genero);
        todoOk =1;
    }



    return todoOk;


}

int movie_setRating(eMovie* this,float rating)
{
    int todoOk=0;

    if(this !=NULL && rating>0)
    {
        this->rating=rating;
        todoOk =1;
    }


    return todoOk;


}

void list_movie(eMovie* this)
{

    printf("%3d   %30s           %s          %5.2f\n\n",this->id_peli,this->titulo,this->genero,this->rating);

}





int searchMovieId(LinkedList* pArrayListMovie, int id)
{
    int indice = -1;
    int idAux;
    eMovie* auxMovie;

    for (int i = 0; i < ll_len(pArrayListMovie); i++)
    {
        auxMovie = ll_get(pArrayListMovie, i);
        if( movie_getId(auxMovie, &idAux) && idAux == id)
        {
            indice = i;
        }
    }
    return indice;
}

int movie_getId(eMovie* this,int* id_peli)
{
    int todoOk = 0;
    if (this != NULL && id_peli != NULL)
    {
        *id_peli = this->id_peli;
        todoOk = 1;
    }
    return todoOk;

}

int movie_getTitulo(eMovie* this,char* titulo)
{

    int todoOk = 0;
    if (this != NULL && titulo != NULL )
    {
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }
    return todoOk;

}

int movie_getGenero(eMovie* this,char* genero)
{
   int todoOk = 0;
    if (this != NULL && genero != NULL )
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }
    return todoOk;

}

int movie_getRating(eMovie* this,float* rating)
{

    int todoOk = 0;
    if (this != NULL && rating > 0)
    {
        *rating=this->rating;
        todoOk = 1;
    }
    return todoOk;
}


int buscarMayorId(LinkedList* pArrayListMovie)
{
    eMovie* auxMovie = NULL;
    int mayor = 0;
    int id;
    if(pArrayListMovie != NULL)
    {
        for( int i = 0; i < ll_len(pArrayListMovie); i++)
        {
            auxMovie = (eMovie*) ll_get(pArrayListMovie, i);
            movie_getId(auxMovie, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }
    }
    return mayor;
}
