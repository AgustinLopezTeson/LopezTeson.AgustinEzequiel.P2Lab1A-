#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED


typedef struct
{
    int id;
    char user[300];
    int likes;
    int dislikes;
    int followers;
}ePost;


ePost* new_post();
ePost* post_newParam(int id,char* user,float rating);


int post_setId(ePost* this,int id);
int post_getId(ePost* this,int* id);

int post_setUser(ePost* this,char* user);
int post_getUser(ePost* this,char* user);

int post_setLikes(ePost* this,int likes);
int post_getLikes(ePost* this,int* likes);

int post_setDislikes(ePost* this,int dislikes);
int post_getDislikes(ePost* this,int* dislikes);

int post_setFollowers(ePost* this,int followers);
int post_getFollowers(ePost* this,int* followers);

void list_Post(ePost* this);
int searchPostId(LinkedList* pArrayListPost, int id);
int buscarMayorId(LinkedList* pArrayListPost);
int filtrar_likes(void* post);
int filtrar_hate(void* post);


#endif // POST_H_INCLUDED
