#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noeud
{
    char val;
    float taille;
    char type;
    struct noeud *g;
    struct noeud *d;
}noeud;
typedef struct noeud *ArbreB;

///////////////////////////////////////////////////////////////////////////////
ArbreB AjoutN(char *c,float taille,char *type,ArbreB *g,ArbreB *d)
{
  ArbreB R;
  R=(ArbreB)malloc(sizeof(noeud));
  R->val=*c;
  R->taille = taille;
  R->type = *type;
  R->g=(*g);
  R->d=(*d);
  return R;
}

/////////////////////////////////////
void infix(ArbreB R)
{
    
    if (R!=NULL)
    {
        infix(R->g);
        printf("%c",R->val);
        infix(R->d);
    }
}
void RDG (ArbreB R){
    if(R!=NULL)
    {
        printf("%c",R->val);
        RDG(R->d);
        RDG(R->g); 
    }
}
/////////////////////////////////////
//si On cosidère ici que les fichiers sont les feuilles de l'arbre
void stat (ArbreB R)
{
    int fichier = 0, dossier = 0;
    float taille_fichiers = 0;
    if((R!=NULL) && (R->g == NULL) && (R->d == NULL)){
        fichier ++;
        taille_fichiers = taille_fichiers + R->taille;
    }    
    if (R->g != NULL){
        dossier++;
        stat(R->g);
    }
    if (R->d != NULL){
        dossier++;
        stat(R->d);
    }
    printf("Il existe %d fichiers de taille %f, et %d dossiers", fichier, taille_fichiers, dossier);
    
}
// Autre methode en comparant le type de noeud si ("dossier")ou non ///////
void statistics(ArbreB R)
{
    int fichier = 0, dossier = 0;
    float taille_fichiers = 0;
    if(R!=NULL)
    {
        if (!strcmp(R->type,"dossier"))   dossier++;
        else {
            fichier ++;
            taille_fichiers = taille_fichiers + R->taille;
        }
        statistics(R->d);
        statistics(R->g);
    }
    printf("Il existe %d fichiers de taille %f, et %d dossiers", fichier, taille_fichiers, dossier);
}
/////////////////////////////////////

int main()
{
    ArbreB R,Rg,Rd,Rgg,Rgd,Rdg,Rdd,Rggg,Rggd,Rdgg,Rddg,Rddd,Rgggg,Rgggd,Rggdg,Rggdd,Rddgg,Rdddg,Rdddd,Rggggg,Rgggdg,Rgggdd;
    R=AjoutN("C:",0,"dossier",&Rg,&Rd);
    Rg=AjoutN("net",0,"dossier",&Rgg,&Rgd);
    Rd=AjoutN("docs",0,"dossier",&Rdg,&Rdd);
    Rgg=AjoutN("media",0,"dossier",&Rggg,&Rggd);
    Rgd=AjoutN("f.html",76,"fichier",NULL,NULL);
    Rdg=AjoutN("excel",0,"dossier",&Rdgg,NULL);
    Rdd=AjoutN("word",0,"dossier",&Rddg,&Rdd);
    Rggg=AjoutN("movie",0,"dossier",&Rgggg,&Rgggd);
    Rggd=AjoutN("sound",0,"dossier",&Rggdg,&Rggdd);
    Rdgg=AjoutN("fold",0,"dossier",NULL,NULL);
    Rddg=AjoutN("pdf",1.3,"dossier",&Rddgg,NULL);
    Rddd=AjoutN("fold",0,"dossier",&Rdddg,&Rdddd);
    Rgggg=AjoutN("other",0,"dossier",&Rggggg,NULL);
    Rgggd=AjoutN("big",0,"dossier",&Rgggdg,&Rgggdd);
    Rggdg=AjoutN("f.wav",11,"fichier",NULL,NULL);
    Rggdd=AjoutN("f.mp3",8,"fichier",NULL,NULL);
    Rddgg=AjoutN("f.pdf",2.6,"fichier",NULL,NULL);
    Rdddg=AjoutN("f2.doc",2,"fichier",NULL,NULL);
    Rdddd=AjoutN("f1.doc",1.5,"fichier",NULL,NULL);
    Rggggg=AjoutN("f.mp4",11.53,"fichier",NULL,NULL);
    Rgggdg=AjoutN("f.occ",5.3,"fichier",NULL,NULL);
    Rgggdd=AjoutN("f.mp4",10,"fichier",NULL,NULL);
    
    Rgggg->taille = (Rggggg->taille) + 1;
    Rgggd->taille = (Rgggdg->taille) + (Rgggdd->taille) + 1;
    Rggg->taille = (Rgggg->taille) + (Rgggd->taille) + 1;
    Rggd->taille = (Rggdg->taille) + (Rggdd->taille) + 1;
    Rgg->taille = (Rggd->taille) + (Rggg->taille) + 1;
    Rg->taille = (Rgg->taille) + (Rgd->taille) + 1;
    Rddg->taille = (Rddgg->taille) + 1;
    Rddd->taille = (Rdddg->taille) + (Rdddd->taille) + 1;
    Rdg->taille = (Rdgg->taille) + 1;
    Rdd->taille = (Rddg->taille) + (Rddd->taille) + 1;
    Rd->taille = (Rdd->taille) + (Rdg->taille) + 1;
    R->taille = (Rg->taille) + (Rd->taille) + 1;
    printf("le parcours infix");
    infix(R);
    printf("le parcours Racine-Droite-Gauche");
    RDG(R);
    statistics(R);
    
    return 0;
}