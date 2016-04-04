//-------------------------------------------------------------------
// Bibliothèque : Lisp4c
// Version      : 1.1
// Description  : Bibliothèque de fonctions lisp en C
// Par          : Philippe BOUSQUET
// Le           : 28/02/2001
// Copyright    : (c) 2001 - Philippe BOUSQUET
//-------------------------------------------------------------------
# include <string.h>
# include "lisp4c.h"
//-------------------------------------------------------------------
// IsAtom : Renvoie vraie si le paramètre est une donnée atomique
int IsAtom (char X [])
{
  int i;
  int isatom_ret=1;
  for (i=0;i<strlen(X);i++)
    isatom_ret=!((X[i]=='(') || (X[i]==' ') || (X[i]==')'));
  return(isatom_ret);
}
//-------------------------------------------------------------------
// IsList : Renvoie vraie si le paramètre est une donnée liste
int IsList (char L [])
{
  int i;
  int islist_ret=1;
  int npo=0,npf=0;
  for (i=0;i<strlen(L);i++)
  {
    if (L[i]=='(') npo++;
    if (L[i]==')') npf++;
  }
  if ((npo!=npf) || (npo==0) || (strcmp(L,"()\0")==0)) islist_ret=0;
  return(islist_ret);
}
//-------------------------------------------------------------------
// List : Transforme une donnée en donnée liste
char * List (char X [])
{
  char *list_ret;
  list_ret = (char *) malloc(strlen(X)+2);
  strcpy(list_ret,"\0");
  if (strcmp(X,"()\0")==0) strcpy(list_ret,X);
  else
  {
    strcpy(list_ret,"(\0");
    strcat(list_ret,X);
    strcat(list_ret,")\0");
  }
  return(list_ret);
}
//-------------------------------------------------------------------
// Car : Renvoie le premier élément d'une liste
char * Car (char L [])
{
  int i=1,np=0;
  char *car_ret;
  if (IsList(L))
  {
    if (L[i]=='(')
    {
      i++;
      np++;
      while (np!=0)
      {
        if (L[i]=='(') np++;
        if (L[i]==')') np--;
        i++;
      }
    }
    else
    {
      while ((L[i]!=' ') && (L[i]!=')')) i++;
    }
    car_ret = (char *) malloc(i);
    strcpy(car_ret,"\0");
    strncpy(car_ret,&L[1],i-1);
    strcat(car_ret,"\0");
  }
  else
  {
    car_ret = (char *) malloc(3);
    strcpy(car_ret,"()\0");
  }
  return(car_ret);
}
//-------------------------------------------------------------------
// Cdr : Renvoie la partie droite d'une liste
char * Cdr (char L [])
{
  int i=1,np=0;
  char *cdr_ret;
  if (IsList(L))
  {
    if (L[i]=='(')
    {
      i++;
      np++;
      while (np!=0)
      {
        if (L[i]=='(') np++;
        if (L[i]==')') np--;
        i++;
      }
    }
    else
    {
      while ((L[i]!=' ') && (L[i]!=')')) i++;
    }
    cdr_ret = (char *) malloc(strlen(L)-i);
    strcpy(cdr_ret,"(\0");
    strcat(cdr_ret,&L[i+1]);
  }
  else
  {
    cdr_ret = (char *) malloc(3);
    strcpy(cdr_ret,"()\0");
  }
  return(cdr_ret);
}
//-------------------------------------------------------------------
// Append : Ajoute un élément à une liste
char * Append (char L [], char X [])
{
  char *append_ret;
  if (IsList(L))
  {
    if (IsList(X) || IsAtom(X))
    {
      append_ret = (char *) malloc((strlen(L)+strlen(X))+2);
      strcpy(append_ret,"\0");
      memcpy(append_ret,L,strlen(L)-1);
      strcat(append_ret," \0");
      strcat(append_ret,X);
      strcat(append_ret,")\0");
    }
    else
    {
      append_ret = (char *) malloc(strlen(L)+1);
      strcpy(append_ret,"\0");
      strcpy(append_ret,L);
    }
  }
  else
  {
    append_ret = (char *) malloc(3);
    strcpy(append_ret,"()\0");
  }
  return(append_ret);
}
//-------------------------------------------------------------------
// Merge : Fusionne deux listes
char * Merge (char L1 [], char L2 [])
{
  char *merge_ret;
  if (IsList(L1))
  {
    if (IsList(L2))
    {
      merge_ret = (char *) malloc((strlen(L1)+strlen(L2)));
      strcpy(merge_ret,"\0");
      memcpy(merge_ret,L1,strlen(L1)-1);
      strcat(merge_ret," \0");
      strcat(merge_ret,&L2[1]);
    }
    else
    {
      merge_ret = (char *) malloc(strlen(L1)+1);
      strcpy(merge_ret,"\0");
      strcpy(merge_ret,L1);
    }
  }
  else
  {
    merge_ret = (char *) malloc(3);
    strcpy(merge_ret,"()\0");
  }
  return(merge_ret);
}
//-------------------------------------------------------------------
// Cons : Crée une liste à deux éléments
char * Cons (char E1 [], char E2 [])
{
  return(Merge(List(E1),List(E2)));
}
//-------------------------------------------------------------------
// LstLength : Renvoie le nombre d'éléments d'une liste
int LstLength (char L [])
{
  int lstlength_ret=0;
  char *liste;
  liste = (char *) malloc(strlen(L)+1);
  strcpy(liste,L);
  while (IsList(liste))
  {
    lstlength_ret++;
    liste=Cdr(liste);
  }
  free(liste);
  return(lstlength_ret);
}
//-------------------------------------------------------------------
// LstFind : Renvoie vrai si l'élément est present dans la liste
int LstFind (char E [], char L [])
{
  int lstfind_ret=0;
  char *elt;
  char *lst;
  lst = (char *) malloc(strlen(L)+1);
  strcpy(lst,L);
  while ((IsList(lst)) && (!lstfind_ret))
  {
    elt=Car(lst);
    lstfind_ret=(strcmp(elt,E)==0);
    lst=Cdr(lst);
  }
  free(lst);
  return(lstfind_ret);
}
//-------------------------------------------------------------------
// LstDel : Supprime la première oucurence de E dans la liste L
char * LstDel (char E [], char L [])
{
  char *lstdel_ret;
  char *lst;
  int supp=0;
  lst = (char *) malloc(strlen(L)+1);
  strcpy(lst,L);
  if (IsList(lst))
  {
    lstdel_ret = (char *) malloc(strlen(L)+1);
    strcpy(lstdel_ret,"\0");
    while (IsList(lst))
    {
      if ((strcmp(Car(lst),E)!=0) || (supp))
      {
        if (strlen(lstdel_ret)==0) lstdel_ret=List(Car(lst));
        else lstdel_ret=Merge(lstdel_ret,List(Car(lst)));
      }
      else supp++;
      lst=Cdr(lst);
    }
  }
  else
  {
    lstdel_ret = (char *) malloc(3);
    strcpy(lstdel_ret,"()\0");
  }
  free(lst);
  return(lstdel_ret);
}
//-------------------------------------------------------------------
// LstDelAll : Supprime toutes les ocurences de E sans la liste L
char * LstDelAll (char E [], char L [])
{
  char *lstdelall_ret;
  char *lst;
  lst = (char *) malloc(strlen(L)+1);
  strcpy(lst,L);
  if (IsList(lst))
  {
    lstdelall_ret = (char *) malloc(strlen(L)+1);
    strcpy(lstdelall_ret,"\0");
    while (IsList(lst))
    {
      if (strcmp(Car(lst),E)!=0)
      {
        if (strlen(lstdelall_ret)==0) lstdelall_ret=List(Car(lst));
        else lstdelall_ret=Merge(lstdelall_ret,List(Car(lst)));
      }
      lst=Cdr(lst);
    }
  }
  else
  {
    lstdelall_ret = (char *) malloc(3);
    strcpy(lstdelall_ret,"()\0");
  }
  free(lst);
  return(lstdelall_ret);
}
//-------------------------------------------------------------------
// Intersec : Crée l'intersection de deux listes
char * Intersec (char L1 [], char L2 [])
{
  char *intersec_ret;
  char *lst;
  if (IsList(L1) && IsList(L2))
  {
    lst = (char *) malloc(strlen(L1)+1);
    intersec_ret = (char *) malloc(strlen(L1)+1);
    strcpy(intersec_ret,"\0");
    strcpy(lst,L1);
    while (IsList(lst))
    {
      if (LstFind(Car(lst),L2))
      {
        if (strlen(intersec_ret)==0) { strncpy(intersec_ret,Car(lst),strlen(Car(lst)));strcpy(intersec_ret,List(intersec_ret)); }
        else intersec_ret=Merge(intersec_ret,List(Car(lst)));
      }
      lst=Cdr(lst);
    }
    free(lst);
  }
  else
  {
    intersec_ret = (char *) malloc(3);
    strcpy(intersec_ret,"()\0");
  }
  return(intersec_ret);
}
//-------------------------------------------------------------------
// InvIntersec : Fonction inverse de Intersec
char * InvIntersec (char L1 [], char L2 [])
{
  char *invintersec_ret;
  char *lst;
  if (IsList(L1) && IsList(L2))
  {
    invintersec_ret = (char *) malloc(strlen(L1)+1);
    strcpy(invintersec_ret,"\0");
    // Elements de L1 absents dans L2
    lst = (char *) malloc(strlen(L1)+1);
    strcpy(lst,L1);
    while (IsList(lst))
    {
      if (!LstFind(Car(lst),L2))
      {
        if (strlen(invintersec_ret)==0) invintersec_ret=List(Car(lst));
        else invintersec_ret=Merge(invintersec_ret,List(Car(lst)));
      }
      lst=Cdr(lst);
    }
    free(lst);
    // Elements de L2 absents dans L1
    lst = (char *) malloc(strlen(L2)+1);
    strcpy(lst,L2);
    while (IsList(lst))
    {
      if (!LstFind(Car(lst),L1))
      {
        if (strlen(invintersec_ret)==0) invintersec_ret=List(Car(lst));
        else invintersec_ret=Merge(invintersec_ret,List(Car(lst)));
      }
      lst=Cdr(lst);
    }
    free(lst);
  }
  else if (IsList(L1))
  {
    invintersec_ret = (char *) malloc(strlen(L1)+1);
    strcpy(invintersec_ret,L1);
  }
  else if (IsList(L2))
  {
    invintersec_ret = (char *) malloc(strlen(L2)+1);
    strcpy(invintersec_ret,L2);
  }
  else
  {
    invintersec_ret = (char *) malloc(3);
    strcpy(invintersec_ret,"()\0");
  }
  return(invintersec_ret);
}
//-------------------------------------------------------------------
// Union : Crée l'union de deux Listes
char * Union (char L1 [], char L2 [])
{
  char *union_ret;
  if (strcmp(Merge(Intersec(L1,L2),InvIntersec(L1,L2)),"()\0")!=0)
  {
    union_ret = (char *) malloc(strlen(Merge(Intersec(L1,L2),InvIntersec(L1,L2))));
    strcpy(union_ret,"\0");
    strcpy(union_ret,Merge(Intersec(L1,L2),InvIntersec(L1,L2)));
  }
  else
  {
    union_ret = (char *) malloc(strlen(InvIntersec(L1,L2)));
    strcpy(union_ret,"\0");
    strcpy(union_ret,InvIntersec(L1,L2));
  }
  return(union_ret);
}
//-------------------------------------------------------------------
// Assoc : renvoi la paire ayant pour élément gauche E
char * Assoc (char E [], char L [])
{
  char *assoc_ret;
  char *lst;
  int find=0;
  if (IsList(L))
  {
    lst = (char *) malloc(strlen(L)+1);
    strcpy(lst,L);
    while (IsList(lst) && !find)
    {
      if (strcmp(Car(Car(lst)),E)==0)
      {
        assoc_ret = (char *) malloc(strlen(Car(lst)));
        strcpy(assoc_ret,"\0");
        strcpy(assoc_ret,Car(lst));
        find=1;
      }
      lst=Cdr(lst);
    }
    free(lst);
    if (!find)
    {
      assoc_ret = (char *) malloc(3);
      strcpy(assoc_ret,"()\0");
    }
  }
  else
  {
    assoc_ret = (char *) malloc(3);
    strcpy(assoc_ret,"()\0");
  }
  return(assoc_ret);
}
//-------------------------------------------------------------------
// Rssoc : renvoi la paire ayant pour élément droit E
char * Rssoc (char E [], char L [])
{
  char *rssoc_ret;
  char *lst;
  int find=0;
  if (IsList(L))
  {
    lst = (char *) malloc(strlen(L)+1);
    strcpy(lst,L);
    while (IsList(lst) && !find)
    {
      if (strcmp(Car(Cdr(Car(lst))),E)==0)
      {
        rssoc_ret = (char *) malloc(strlen(Car(lst)));
        strcpy(rssoc_ret,"\0");
        strcpy(rssoc_ret,Car(lst));
        find=1;
      }
      lst=Cdr(lst);
    }
    free(lst);
    if (!find)
    {
      rssoc_ret = (char *) malloc(3);
      strcpy(rssoc_ret,"()\0");
    }
  }
  else
  {
    rssoc_ret = (char *) malloc(3);
    strcpy(rssoc_ret,"()\0");
  }
  return(rssoc_ret);
}
//-------------------------------------------------------------------