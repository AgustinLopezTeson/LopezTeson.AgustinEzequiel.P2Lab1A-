#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"

/** \brief Carga las peliculas desde el archivo movies.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPost)
{
    FILE* f= fopen(path,"r");

    if(f==NULL && pArrayListPost==NULL)
    {
        printf("No se pudo cargar el archivo");
    }
    else
    {

        if(parser_postFromText(f,pArrayListPost))
        {
            printf("Hubo un error en cargar los post");
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


int controller_ListPost(LinkedList* pArrayListPost)
{
    int todoOk=0;
    ePost* auxPost=NULL;
    if(pArrayListPost!=NULL)
    {
        printf("   ID           user               Likes              Dislikes          Followers\n\n");
        for(int i = 0 ; i<ll_len(pArrayListPost); i++)
        {
            auxPost=(ePost* )ll_get(pArrayListPost,i);
            list_Post(auxPost);

        }
        todoOk=1;
    }

    return todoOk;
}

/** \brief Ordenar Post
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_ordenarPost(LinkedList* pArrayListPost)
{
    int todoOk = 0;

    if (pArrayListPost != NULL)
    {
        ll_sort(pArrayListPost, compFollowersPost, 0);
        system("cls");
        controller_ListPost(pArrayListPost);
        printf("Post ordenados con exito\n");
        system("pause");
        todoOk = 1;
    }
    return todoOk;
}

int compFollowersPost(void* postA, void* postB)
{
    int todoOk= 0;

    if(((ePost*)postA)->followers <
            ((ePost*)postB)->followers)
    {
        todoOk = -1;
    }
    return todoOk;

}


void* asignarLikesPost(void* post)
{
    ePost* auxPost = NULL;
    int likes;
    if (post != NULL)
    {
        auxPost = (ePost*) post;
        likes = (int)(rand() % (5000 - 500 + 1) + 500);
        post_setLikes(auxPost, likes);
    }
    return auxPost;
}

void* asignarDislikesPost(void* post)
{
    ePost* auxPost = NULL;
    int dislikes;
    if (post != NULL)
    {
        auxPost = (ePost*) post;
        dislikes = (int)(rand() % (3500 - 300 + 1) + 300);
        post_setDislikes(auxPost, dislikes);
    }
    return auxPost;
}

void* asignarFollowerPost(void* post)
{
    ePost* auxPost = NULL;
    int followers;
    if (post != NULL)
    {
        auxPost = (ePost*) post;
        followers = (int)(rand() % (20000 - 10000 + 1) + 10000);
        post_setFollowers(auxPost, followers);
    }
    return auxPost;
}


int controller_map(LinkedList* pArrayListPost)
{
    int todoOk = 0;
    pArrayListPost = ll_map(pArrayListPost, asignarLikesPost);
    pArrayListPost = ll_map(pArrayListPost, asignarDislikesPost);
    pArrayListPost = ll_map(pArrayListPost, asignarFollowerPost);

    if(pArrayListPost != NULL)
    {
        controller_ListPost(pArrayListPost);
        printf("ESTADISTICAS ASINGADAS CON EXITO\n");
        todoOk = 1;
    }
    return todoOk;
}

int controller_filterLikes(LinkedList* pArrayListPost)
{
    int todoOk = 0;
    char auxCadenaPath[20];
    if (pArrayListPost != NULL)
    {
        printf("Buscando\n");
        pArrayListPost = ll_filter(pArrayListPost,filtrar_likes);
        strcpy(auxCadenaPath, "postMasLikes.csv");

        if(pArrayListPost != NULL)
        {
            controller_ListPost(pArrayListPost);
            system("pause");
            controller_saveAsText(auxCadenaPath, pArrayListPost);
            todoOk = 1;
        }

    }
    return todoOk;
}

int controller_filterhate(LinkedList* pArrayListPost)
{
    int todoOk = 0;
    char auxCadenaPath[20];
    if (pArrayListPost != NULL)
    {
        printf("Buscando\n");
        pArrayListPost = ll_filter(pArrayListPost,filtrar_hate);
        strcpy(auxCadenaPath, "postMasHate.csv");

        if(pArrayListPost != NULL)
        {
            controller_ListPost(pArrayListPost);
            system("pause");
            controller_saveAsText(auxCadenaPath, pArrayListPost);
            todoOk = 1;
        }

    }
    return todoOk;
}





/** \brief Guarda los datos de las (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPost)
{
    int todoOk = 0;
    FILE* f;
    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;
    ePost* auxPost;

    if ( path != NULL && pArrayListPost != NULL )
    {

        f = fopen(path, "w"); // abro el archivo
        if ( f == NULL )
        {
            printf("No se pudo abrir el archivo\n");

        }

        fprintf( f, "id,user,likes,dislikes,followers\n" );

        for (int i = 0; i < ll_len(pArrayListPost); i++)
        {
            auxPost = ll_get(pArrayListPost, i);
            if (    post_getId( auxPost, &id ) &&
                    post_getUser( auxPost, user ) &&
                    post_getLikes( auxPost, &likes) &&
                    post_getDislikes(auxPost, &dislikes)&&
                    post_getFollowers(auxPost,&followers)
               )
            {
                fprintf(f, "%d,%s,%d,%d,%d\n", id,user, likes, dislikes,followers);
                todoOk = 1;
            }
        }
        system("cls");
        printf("\nGuardado correctamente.\n");
        system("pause");
    }
    fclose(f);
    return todoOk;
}

