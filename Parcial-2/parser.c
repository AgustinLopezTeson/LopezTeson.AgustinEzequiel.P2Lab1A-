#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"

/** \brief Parsea los datos los  (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int parser_postFromText(FILE* pFile , LinkedList* pArrayListPost)
{
    int todoOk=1;
    int cant;
    char buffer[5][300];
    ePost* auxPost=NULL;

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            while(!feof(pFile)){
                    auxPost=new_post();
                    if(auxPost!=NULL)
                    {
                        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
                        post_setId(auxPost,atoi(buffer[0]));
                        post_setUser(auxPost,buffer[1]);
                        post_setLikes(auxPost,atoi(buffer[2]));
                        post_setDislikes(auxPost,atoi(buffer[3]));
                        post_setFollowers(auxPost,atoi(buffer[4]));

                        ll_add(pArrayListPost,auxPost);

                        todoOk=0;
                    }
                        if(cant<4){
                            break;
                        }
                }

    return todoOk;
}

