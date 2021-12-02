#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"

ePost* new_post()
{

    ePost* new_p;


    new_p = (ePost*) malloc (sizeof(ePost));

    if(new_p!=NULL)
    {
            new_p->id= 0;
            strcpy(new_p->user," ");
            new_p->likes= 0;
            new_p->dislikes= 0;
            new_p->followers= 0;
    }else{

    printf("Hubo un problema");
    }

    return new_p;
}


void post_delete(ePost* post)
{

    free(post);
}

int post_setId(ePost* this,int id)
{
    int todoOk=0;

    if(this !=NULL && id>=0 && id<= 50000)
    {
        this->id=id;
        todoOk =1;
    }

    return todoOk;
}

int post_setUser(ePost* this,char* user)
{
    int todoOk=0;

    if(this != NULL && user!=NULL)
    {
        strcpy(this->user,user);
        todoOk =1;
    }


    return todoOk;
}

int post_setLikes(ePost* this,int likes)
{
    int todoOk=0;

    if(this !=NULL && likes>=0 && likes<= 50000)
    {
        this->likes=likes;
        todoOk =1;
    }

    return todoOk;
}

int post_setDislikes(ePost* this,int dislikes)
{
    int todoOk=0;

    if(this !=NULL && dislikes>=0 && dislikes<= 50000)
    {
        this->dislikes=dislikes;
        todoOk =1;
    }

    return todoOk;
}

int post_setFollowers(ePost* this,int followers)
{
    int todoOk=0;

    if(this !=NULL && followers>=0 && followers<= 50000)
    {
        this->followers=followers;
        todoOk =1;
    }

    return todoOk;
}

void list_Post(ePost* this)
{

    int todoOk = 0;
    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;
    if (this != NULL)
    {
        todoOk = 1;
        if (    post_getId( this, &id ) &&
                post_getUser( this, user ) &&
                post_getLikes( this, &likes) &&
                post_getDislikes(this, &dislikes)&&
                post_getFollowers(this,&followers)
           )
        {
            printf ("%-7d      %-15s          %-8d                %-6d              %-6d \n", id, user, likes, dislikes,followers);
            todoOk = 1;
        }
    }
    return todoOk;

}

int filtrar_likes(void* post)
{
    int todoOk = 0;
    ePost* auxPost = NULL;
    if (post != NULL)
    {
            auxPost=(ePost*) post;

        if (auxPost->likes > 3500)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrar_hate(void* post)
{
    int todoOk = 0;
    ePost* auxPost = NULL;
    if (post != NULL)
    {

            auxPost=(ePost*) post;
        if(auxPost->likes < auxPost->dislikes)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}


int searchPostId(LinkedList* pArrayListPost, int id)
{
    int indice = -1;
    int idAux;
    ePost* auxPost;

    for (int i = 0; i < ll_len(pArrayListPost); i++)
    {
        auxPost = ll_get(pArrayListPost, i);
        if( post_getId(auxPost, &idAux) && idAux == id)
        {
            indice = i;
        }
    }
    return indice;
}

int post_getId(ePost* this,int* id)
{
    int todoOk = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;

}

int post_getUser(ePost* this,char* user)
{

    int todoOk = 0;
    if (this != NULL && user != NULL )
    {
        strcpy(user, this->user);
        todoOk = 1;
    }
    return todoOk;

}

int post_getLikes(ePost* this,int* likes)
{

    int todoOk = 0;
    if (this != NULL && likes != NULL)
    {
        *likes = this->likes;
        todoOk = 1;
    }
    return todoOk;

}

int post_getDislikes(ePost* this,int* dislikes)
{

    int todoOk = 0;
    if (this != NULL && dislikes != NULL)
    {
        *dislikes = this->dislikes;
        todoOk = 1;
    }
    return todoOk;

}

int post_getFollowers(ePost* this,int* followers)
{

    int todoOk = 0;
    if (this != NULL && followers != NULL)
    {
        *followers = this->followers;
        todoOk = 1;
    }
    return todoOk;

}

int buscarMayorId(LinkedList* pArrayListPost)
{
    ePost* auxPost = NULL;
    int mayor = 0;
    int id;
    if(pArrayListPost != NULL)
    {
        for( int i = 0; i < ll_len(pArrayListPost); i++)
        {
            auxPost = (ePost*) ll_get(pArrayListPost, i);
            post_getId(auxPost, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }
    }
    return mayor;
}
