//-------------------------------------------------------------------
// Bibliothèque : testlisp4c
// Version      : 1.0
// Description  : Programme de test de la bibliothèque lisp4c
// Par          : Philippe BOUSQUET
// Le           : 05/03/2001
//-------------------------------------------------------------------
#include <stdio.h>
#include "lisp4c.h"
//-------------------------------------------------------------------
int main (void)
{
  fprintf(stdout,"Programme de test de la bibliothèque lisp4c\n");
  fprintf(stdout,"Par Philippe BOUSQUET\n");
  fprintf(stdout,"Copyright (c) 2001 - Philippe BOUSQUET\n\n");

  // Test de la fonction IsAtom(A)
  fprintf(stdout,"-> Test de la fonction IsAtom(A):\n");
  fprintf(stdout,"IsAtom(\"Philippe\")=%d.\n",IsAtom("Philippe"));
  fprintf(stdout,"IsAtom(\"(a b c)\")=%d.\n",IsAtom("(a b c)"));
  fprintf(stdout,"IsAtom(\"()\")=%d.\n\n",IsAtom("()"));

  // Test de la fonction IsList(L)
  fprintf(stdout,"-> Test de la fonction IsList(L):\n");
  fprintf(stdout,"IsList(\"Philippe\")=%d.\n",IsList("Philippe"));
  fprintf(stdout,"IsList(\"(a b c)\")=%d.\n",IsList("(a b c)"));
  fprintf(stdout,"IsList(\"()\")=%d.\n\n",IsList("()"));

  // Test de la fonction List(X)
  fprintf(stdout,"-> Test de la fonction List(X):\n");
  fprintf(stdout,"List(\"Philippe\")=%s.\n",List("Philippe"));
  fprintf(stdout,"List(\"(a b c)\")=%s.\n",List("(a b c)"));
  fprintf(stdout,"List(\"()\")=%s.\n\n",List("()"));

  // Test de la fonction Car(L)
  fprintf(stdout,"-> Test de la fonction Car(L):\n");
  fprintf(stdout,"Car(\"Philippe\")=%s.\n",Car("Philippe"));
  fprintf(stdout,"Car(\"(a b c)\")=%s.\n",Car("(a b c)"));
  fprintf(stdout,"Car(\"((a b) c)\")=%s.\n",Car("((a b) c)"));
  fprintf(stdout,"Car(\"()\")=%s.\n\n",Car("()"));

  // Test de la fonction Cdr(L)
  fprintf(stdout,"-> Test de la fonction Cdr(L):\n");
  fprintf(stdout,"Cdr(\"Philippe\")=%s.\n",Cdr("Philippe"));
  fprintf(stdout,"Cdr(\"(a b c)\")=%s.\n",Cdr("(a b c)"));
  fprintf(stdout,"Cdr(\"((a b) c)\")=%s.\n",Cdr("((a b) c)"));
  fprintf(stdout,"Cdr(\"()\")=%s.\n\n",Cdr("()"));

  // Test de la fonction Append(L, X)
  fprintf(stdout,"-> Test de la fonction Append(L, X):\n");
  fprintf(stdout,"Append(\"Philippe\",\"Toto\")=%s.\n",Append("Philippe","Toto"));
  fprintf(stdout,"Append(\"(a b c)\",\"d\")=%s.\n",Append("(a b c)","d"));
  fprintf(stdout,"Append(\"((a b) c)\",\"(d e)\")=%s.\n",Append("((a b) c)","(d e)"));
  fprintf(stdout,"Append(\"(a b c)\",\"()\")=%s.\n\n",Append("(a b c)","()"));

  // Test de la fonction Merge(L1, L2)
  fprintf(stdout,"-> Test de la fonction Merge(L1, L2):\n");
  fprintf(stdout,"Merge(\"Philippe\",\"Toto\")=%s.\n",Merge("Philippe","Toto"));
  fprintf(stdout,"Merge(\"(a b c)\",\"d\")=%s.\n",Merge("(a b c)","d"));
  fprintf(stdout,"Merge(\"((a b) c)\",\"(d e)\")=%s.\n",Merge("((a b) c)","(d e)"));
  fprintf(stdout,"Merge(\"(a b c)\",\"()\")=%s.\n\n",Merge("(a b c)","()"));

  // Test de la fonction Cons(E1, E2)
  fprintf(stdout,"-> Test de la fonction Cons(E1, E2):\n");
  fprintf(stdout,"Cons(\"Philippe\",\"Toto\")=%s.\n",Cons("Philippe","Toto"));
  fprintf(stdout,"Cons(\"(a b c)\",\"d\")=%s.\n",Cons("(a b c)","d"));
  fprintf(stdout,"Cons(\"((a b) c)\",\"(d e)\")=%s.\n",Cons("((a b) c)","(d e)"));
  fprintf(stdout,"Cons(\"(a b c)\",\"()\")=%s.\n\n",Cons("(a b c)","()"));

  // Test de la fonction LstLength(L)
  fprintf(stdout,"-> Test de la fonction LstLength(L):\n");
  fprintf(stdout,"LstLength(\"Philippe\")=%d.\n",LstLength("Philippe"));
  fprintf(stdout,"LstLength(\"(a b c)\")=%d.\n",LstLength("(a b c)"));
  fprintf(stdout,"LstLength(\"((a b) c)\")=%d.\n",LstLength("((a b) c)"));
  fprintf(stdout,"LstLength(\"()\")=%d.\n\n",LstLength("()"));

  // Test de la fonction LstFind(E, L)
  fprintf(stdout,"-> Test de la fonction LstFind(E, L):\n");
  fprintf(stdout,"LstFind(\"a\",\"a\")=%d.\n",LstFind("a","a"));
  fprintf(stdout,"LstFind(\"b\",\"(a b c)\")=%d.\n",LstFind("b","(a b c)"));
  fprintf(stdout,"LstFind(\"a\",\"((a b) c)\")=%d.\n",LstFind("a","((a b) c)"));
  fprintf(stdout,"LstFind(\"(a b)\",\"((a b) c)\")=%d.\n\n",LstFind("(a b)","((a b) c)"));

  // Test de la fonction LstDel(E, L)
  fprintf(stdout,"-> Test de la fonction LstDel(E, L):\n");
  fprintf(stdout,"LstDel(\"a\",\"a\")=%s.\n",LstDel("a","a"));
  fprintf(stdout,"LstDel(\"a\",\"(a b c a)\")=%s.\n",LstDel("a","(a b c a)"));
  fprintf(stdout,"LstDel(\"a\",\"((a b) c)\")=%s.\n",LstDel("a","((a b) c)"));
  fprintf(stdout,"LstDel(\"(a b)\",\"((a b) c (a b))\")=%s.\n\n",LstDel("(a b)","((a b) c (a b))"));

  // Test de la fonction LstDelAll(E, L)
  fprintf(stdout,"-> Test de la fonction LstDelAll(E, L):\n");
  fprintf(stdout,"LstDelAll(\"a\",\"a\")=%s.\n",LstDelAll("a","a"));
  fprintf(stdout,"LstDelAll(\"a\",\"(a b c a)\")=%s.\n",LstDelAll("a","(a b c a)"));
  fprintf(stdout,"LstDelAll(\"a\",\"((a b) c)\")=%s.\n",LstDelAll("a","((a b) c)"));
  fprintf(stdout,"LstDelAll(\"(a b)\",\"((a b) c (a b))\")=%s.\n\n",LstDelAll("(a b)","((a b) c (a b))"));

  // Test de la fonction Intersec(L1, L2)
  fprintf(stdout,"-> Test de la fonction Intersec(L1, L2):\n");
  fprintf(stdout,"Intersec(\"a\",\"a\")=%s.\n",Intersec("a","a"));
  fprintf(stdout,"Intersec(\"(b c d)\",\"(a b c)\")=%s.\n",Intersec("(b c d)","(a b c)"));
  fprintf(stdout,"Intersec(\"(a b c)\",\"((a b) c)\")=%s.\n",Intersec("(a b c)","((a b) c)"));
  fprintf(stdout,"Intersec(\"a\",\"(a b c)\")=%s.\n\n",Intersec("a","(a b c)"));

  // Test de la fonction InvIntersec(L1, L2)
  fprintf(stdout,"-> Test de la fonction InvIntersec(L1, L2):\n");
  fprintf(stdout,"InvIntersec(\"a\",\"a\")=%s.\n",InvIntersec("a","a"));
  fprintf(stdout,"InvIntersec(\"(b c d)\",\"(a b c)\")=%s.\n",InvIntersec("(b c d)","(a b c)"));
  fprintf(stdout,"InvIntersec(\"(a b c)\",\"((a b) c)\")=%s.\n",InvIntersec("(a b c)","((a b) c)"));
  fprintf(stdout,"InvIntersec(\"a\",\"(a b c)\")=%s.\n\n",InvIntersec("a","(a b c)"));

  // Test de la fonction Union(L1, L2)
  fprintf(stdout,"-> Test de la fonction Union(L1, L2):\n");
  fprintf(stdout,"Union(\"a\",\"a\")=%s.\n",Union("a","a"));
  fprintf(stdout,"Union(\"(b c d)\",\"(a b c)\")=%s.\n",Union("(b c d)","(a b c)"));
  fprintf(stdout,"Union(\"(a b c)\",\"((a b) c)\")=%s.\n",Union("(a b c)","((a b) c)"));
  fprintf(stdout,"Union(\"(d e)\",\"(a b c)\")=%s.\n\n",Union("(d e)","(a b c)"));

  // Test de la fonction Assoc(E, L)
  fprintf(stdout,"-> Test de la fonction Assoc(E, L):\n");
  fprintf(stdout,"Assoc(\"a\",\"((1 titi) (b tata) (a toto))\")=%s.\n",Assoc("a","((1 titi) (b tata) (a toto))"));
  fprintf(stdout,"Assoc(\"b\",\"(a b c)\")=%s.\n",Assoc("b","(a b c)"));
  fprintf(stdout,"Assoc(\"b\",\"((a b) c)\")=%s.\n",Assoc("b","((a b) c)"));
  fprintf(stdout,"Assoc(\"(d e)\",\"(((d e) t) (a b)  (c c))\")=%s.\n\n",Assoc("(d e)","(((d e) t) (a b)  (c c))"));

  // Test de la fonction Rssoc(E, L)
  fprintf(stdout,"-> Test de la fonction Rssoc(E, L):\n");
  fprintf(stdout,"Rssoc(\"tata\",\"((1 titi) (b tata) (a toto))\")=%s.\n",Rssoc("tata","((1 titi) (b tata) (a toto))"));
  fprintf(stdout,"Rssoc(\"b\",\"(a b c)\")=%s.\n",Rssoc("b","(a b c)"));
  fprintf(stdout,"Rssoc(\"b\",\"((a b) c)\")=%s.\n",Rssoc("b","((a b) c)"));
  fprintf(stdout,"Rssoc(\"(d e)\",\"(((d e) t) (a b)  (c c))\")=%s.\n\n",Rssoc("(d e)","(((d e) t) (a b)  (c c))"));

  return(0);
}
