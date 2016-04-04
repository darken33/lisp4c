//-------------------------------------------------------------------
// Bibliothèque : Lisp4c
// Version      : 1.1
// Description  : Bibliothèque de fonctions lisp en C
// Par          : Philippe BOUSQUET
// Le           : 28/02/2001
// Copyright    : (c) 2001 - Philippe BOUSQUET
//-------------------------------------------------------------------

// IsAtom : Renvoie vraie si le paramètre est une donnée atomique
int IsAtom (char X []);

// IsList : Renvoie vraie si le paramètre est une donnée liste
int IsList (char L []);

// Liste : Transforme une donnée en donnée liste
char * List (char X []);

// Car : Renvoie le premier élément d'une liste
char * Car (char L []);

// Cdr : Renvoie la partie droite d'une liste
char * Cdr (char L []);

// Append : Ajoute un élément à une liste
char * Append (char L [], char X []);

// Merge : Fusionne deux listes
char * Merge (char L1 [], char L2 []);

// Cons : Crée une liste à deux éléments
char * Cons (char E1 [], char E2 []);

// LstLength : Renvoie le nombre d'éléments d'une liste
int LstLength (char L []);

// LstFind : Renvoie vrai si l'élément est present dans la liste
int LstFind (char E [], char L []);

// LstDel : Supprime la première occurence de E dans la liste L
char * LstDel (char E [], char L []);

// LstDelAll : Supprime toutes les ocurences de E sans la liste L
char * LstDelAll (char E [], char L []);

// Intersec : Crée l'intersection de deux listes
char * Intersec (char L1 [], char L2 []);

// InvIntersec : Fonction inverse de Intersec
char * InvIntersec (char L1 [], char L2 []);

// Union : Crée l'union de deux Listes
char * Union (char L1 [], char L2 []);

// Assoc : renvoi la paire ayant pour élément gauche E
char * Assoc (char E [], char L []);

// Rssoc : renvoi la paire ayant pour élément droit E
char * Rssoc (char E [], char L []);
