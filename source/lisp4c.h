//-------------------------------------------------------------------
// Biblioth�que : Lisp4c
// Version      : 1.1
// Description  : Biblioth�que de fonctions lisp en C
// Par          : Philippe BOUSQUET
// Le           : 28/02/2001
// Copyright    : (c) 2001 - Philippe BOUSQUET
//-------------------------------------------------------------------

// IsAtom : Renvoie vraie si le param�tre est une donn�e atomique
int IsAtom (char X []);

// IsList : Renvoie vraie si le param�tre est une donn�e liste
int IsList (char L []);

// Liste : Transforme une donn�e en donn�e liste
char * List (char X []);

// Car : Renvoie le premier �l�ment d'une liste
char * Car (char L []);

// Cdr : Renvoie la partie droite d'une liste
char * Cdr (char L []);

// Append : Ajoute un �l�ment � une liste
char * Append (char L [], char X []);

// Merge : Fusionne deux listes
char * Merge (char L1 [], char L2 []);

// Cons : Cr�e une liste � deux �l�ments
char * Cons (char E1 [], char E2 []);

// LstLength : Renvoie le nombre d'�l�ments d'une liste
int LstLength (char L []);

// LstFind : Renvoie vrai si l'�l�ment est present dans la liste
int LstFind (char E [], char L []);

// LstDel : Supprime la premi�re occurence de E dans la liste L
char * LstDel (char E [], char L []);

// LstDelAll : Supprime toutes les ocurences de E sans la liste L
char * LstDelAll (char E [], char L []);

// Intersec : Cr�e l'intersection de deux listes
char * Intersec (char L1 [], char L2 []);

// InvIntersec : Fonction inverse de Intersec
char * InvIntersec (char L1 [], char L2 []);

// Union : Cr�e l'union de deux Listes
char * Union (char L1 [], char L2 []);

// Assoc : renvoi la paire ayant pour �l�ment gauche E
char * Assoc (char E [], char L []);

// Rssoc : renvoi la paire ayant pour �l�ment droit E
char * Rssoc (char E [], char L []);
