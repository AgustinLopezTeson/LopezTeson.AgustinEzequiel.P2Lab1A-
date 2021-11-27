#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[300];
    char genero[300];
    float rating;
}eMovie;


#endif // PELICULAS_H_INCLUDED


eMovie* new_movie();
eMovie* movie_newParam(int id,char* titulo,float rating);


int movie_setId(eMovie* this,int id);
int movie_getId(eMovie* this,int* id_peli);

int movie_setTitulo(eMovie* this,char* titulo);
int movie_getTitulo(eMovie* this,char* titulo);

int movie_setGenero(eMovie* this,char* genero);
int movie_getGenero(eMovie* this,char* genero);

int movie_setRating(eMovie* this,float rating);
int movie_getRating(eMovie* this,float* rating);

void list_movie(eMovie* this);
int searchMovieId(LinkedList* pArrayListMovie, int id);
int buscarMayorId(LinkedList* pArrayListMovie);
