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
Nama    : Mutiara Dwi Salma
NIM     : 221524022
*/
void PostOrder (address P);
{
    address current;
    current = P;

    if (current == nil) {
        return;
    }
    postOrder(current->ps_fs); //Traversal ke anak pertama
    postOrder(current->ps_nb); //Traversal ke next brother
    printf("%c ", current->info); //Tampilkan simpul saat traversal mundur
}

/*
Nama    : Rohiid Naufal Juliardi
NIM     : 221524029
*/

void Level_order(address X, int Maks_node);{
    address queue[Maks_node+1];
    int front = 0, rear = 0;
    address current;

    if (P != nil){
        queue[rear++] = P;

        while (front != rear){
            current = queue[front++];
            printf("%c ", current->info);

            if (current->ps_fs != nil){
                queue[rear++] = current->ps_fs;
            }
            current = current->ps_nb;
            while (current != nil){
                queue[rear++] = current;
                current = current->ps_nb;
            }
        }
    }
}

/*
Nama    : Muhamad Firman Firdaus
NIM     : 221524013
*/

void PrintTree (address P, int level){
    if (P != NULL) {
        int i;
        PrintTree(P->ps_fs, level + 1);
        printf("\n");
        for (i = 0; i < level; i++){
            printf("|   ");
        }
        printf("|---%c", P->info);
        PrintTree(P->ps_nb,level);
}
}

/*
Nama    :Farrel Rahandika
NIM     :221524010
*/
boolean Search(address P, infotype X) {
    if (P == NULL) {
        return 0;
    }
    if (P->info == X) {
        return 1;
    }
    address child = P->ps_fs;
    while (child != NULL) {
        if (Search(child, X)) {
            return 1;
        }
        child = child->ps_nb;
    }
    address sibling = P->ps_pr;
    while (sibling != NULL) {
        if (sibling->info == X) {
            return 1;
        }
        child = sibling->ps_nb;
        while (child != NULL) {
            if (Search(child, X)) {
                return 1;
            }
            child = child->ps_fs;
        }
        sibling = sibling->ps_pr;
    }
    return 0;
}

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
    if (P == NULL) {
        return 0;
    } else {
        int max_depth = 0;
        for (address child = P->ps_fs; child != NULL; child = child->ps_nb) {
            int current_depth = Depth(child);
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        }
        return max_depth + 1;
    }
}

/*
Nama    : Muhamad Fahrizal Al-Zaelani
NIM     : 221524012
*/
int Max(infotype Data1, infotype Data2){
    if(Data1>Data2){
        return Data1;
    }
    else if(Data2>Data1){
        return Data2;
    }
}
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


/*
Nama    : Roy Aziz Barera
NIM     : 221524030
*/
void addNBTree(address *treeCurrent, char info, address ps_pr, address ps_fs, address ps_nb)
/* Modul ini berfungsi untuk menambahkan node baru dengan syarat nilai info, parent, first son, next brother sudah diketahui dan akan menjadi parameter
	Parameter Output : *treeCurrent
	Parameter Input	 : info, ps_pr, ps_fs, ps_nb
*/
/*I.S: Alamat *treeCurrent yang akan diisi tidak null dan merupakan alamat yang sudah di alokasikan, info,parent, first son, next brother sudah diketahui akan diisi dengan apa 
F.S: Alamat dari *treeCurrent sudah terisi dengan nilai nilai yang ada di parameter input
*/
{
	if(*treeCurrent != nil)
	{
    	(*treeCurrent)->info = info;
    	(*treeCurrent)->ps_pr = ps_pr;
    	(*treeCurrent)->ps_fs = ps_fs;
    	(*treeCurrent)->ps_nb = ps_nb;
	}
}
