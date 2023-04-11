#include "nbtrees.h"

/*
Nama    :
NIM     :
*/
void Create_tree(address X, int Jml_Node);

/*
Nama    :
NIM     :
*/
boolean IsEmpty (address P);

/*
Nama    : Dafa Alfarizki Pratama
NIM     : 221524004
*/
void PreOrder (address P)
{
    address current;
    boolean valid;

    current = P;
    printf("%c ", current->info);
    valid = true;
    
    do 
    {
        if (current->ps_fs != nil && valid)
        {
            current = current->ps_fs;
            printf("%c ", current->info);
        }
        else if (current->ps_nb != nil)
        {
            current = current->ps_nb;
            printf("%c ", current->info);
            valid = true;
        }
        else
        {
            current = current->ps_pr;
            valid = false;
        }
    }while (current->ps_pr != nil);
}

/*
Nama    :
NIM     :
*/
void InOrder (address P);

/*
Nama    :
NIM     :
*/
void PostOrder (address P);

/*
Nama    :
NIM     :
*/
void Level_order(address X, int Maks_node);

/*
Nama    :
NIM     :
*/
void PrintTree (address P);

/*
Nama    :
NIM     :
*/
boolean Search (address P, infotype X);

/*
Nama    :
NIM     :
*/
int NSearch (address P, infotype X);

/*
Nama    :
NIM     :
*/
int nbElmt (address P);

/*
Nama    :
NIM     :
*/
int nbDaun (address P);

/*
Nama    :
NIM     :
*/
int Level (address P, infotype X);

/*
Nama    :
NIM     :
*/
int Depth (address P);

/*
Nama    :
NIM     :
*/
int Max (infotype Data1, infotype Data2);

/*
Nama    :
NIM     :
*/
int Derajat(address P,infotype X);

/*
Nama    :
NIM     :
*/
int Degree (address P, infotype X);
