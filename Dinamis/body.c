#include "nbtrees.h"

/*
Nama    :
NIM     :
*/
void Create_tree(address X, int Jml_Node);

/*
Nama    : Muhammad Azharuddin Hamid
NIM     : 221524018
*/
boolean IsEmpty (address P){

    if (P != nil)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

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
address NSearch (address P, infotype X);

/*
Nama    :
NIM     :
*/
int nbElmt (address P);

/*
Nama    : Muhamad Rendi Zul Fauzi
NIM     : 221524015
*/
int nbDaun (address P){
    if(P == nil){
        return 0;
    }
    else if (P->ps_fs == nil){
        return 1;
    }
    else{
        int count = 0;
        address son = P->ps_fs;
        while (son != nil){
            count += nbDaun(son);
            son = son ->ps_nb;
        }
        return count;
    }
}

/*
Nama    : Welsya Almaira Indra
NIM     : 221524032
*/
int Level (address P, infotype X)
{
	if (P == nil) {
        return -1;
    }

    int level = 1;
    address currentNode = P;

    while (currentNode != nil) {
        address childNode = currentNode->ps_fs;
        while (childNode != nil) {
            if (childNode->info == X) {
                return level;
            }
            childNode = childNode->ps_nb;
        }
        currentNode = currentNode->ps_fs;
        level++;
    }
    return -1;
}

/*
Nama    : Muhammad Alvin Abdul Rozak
NIM     : 221524016
*/
int Depth (address P){
        int max_depth = 0;
    for (int i = 1; i <= P[0].ps_fs; i++) {
        int current_depth = Depth(P[P[i].ps_fs]);
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
    }
    return max_depth + 1;
}

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
Nama    : Farhan Muhammad Yasin
NIM     : 221524008
*/
int Degree (address P, infotype X){
    address temp;
    int count=0;
    if (!IsEmpty(P))
    {
        temp = NSearch(P,X);
        if (temp->ps_fs!=nil)
        {
            count++;
            temp=temp->ps_fs;
            while (temp->ps_nb!=nil)
            {
                count++;
                temp=temp->ps_nb;
            }
        }
    }
    return count;
}