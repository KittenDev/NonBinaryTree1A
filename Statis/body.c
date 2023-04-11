#include "nbtrees.h"

/*
Nama    : 
NIM     :
*/
void init_tree(Isi_Tree *X);

/*
Nama    : Muhammad Rama Nurimani
NIM     : 221524021
*/
void Create_tree(Isi_Tree X, int Jml_Node)
{
    int i, nb_idx, pr_idx;
    infotype node_value, parent_value;
    init_tree(X);

    printf("Masukan root: ");
    scanf(" %c", &node_value);
    X[1].info = node_value;
    X[1].ps_fs = 0;
    X[1].ps_nb = 0;
    X[1].ps_pr = 0;

    for (i = 2; i <= Jml_Node+1; i++)
    {
        printf("Masukan node ke-%d: ", i - 1);
        scanf(" %c", &node_value);
        X[i].info = node_value;
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;

        // relationship
        do
        {
            printf("Masukan parent dari node %c: ", node_value);
            scanf(" %c", &parent_value);
            pr_idx = find_node(X, Jml_Node, parent_value);

            if (pr_idx != -1)
            {
                //check fs nya
                if (X[pr_idx].ps_fs == 0)
                {
                    X[pr_idx].ps_fs = i;
                }
                else
                { //cari brother terakhir
                    nb_idx = X[pr_idx].ps_fs;
                    while (X[nb_idx].ps_nb != 0)
                    {
                        nb_idx = X[nb_idx].ps_nb;
                    }
                    X[nb_idx].ps_nb = i;
                }

                //set parent nya
                X[i].ps_pr = pr_idx;
            }
            else
            {
                printf("Parent node dengan nilai %c tidak ditemukan.\n", parent_value);
            }
        } while (pr_idx == -1);
    }
}

/*
Nama    : 
NIM     :
*/
boolean IsEmpty(Isi_Tree P);

/*
Nama    :
NIM     :
*/
void PreOrder(Isi_Tree P);

/*
Nama    :
NIM     :
*/
void InOrder(Isi_Tree P);

/*
Nama    :
NIM     :
*/
void PostOrder(Isi_Tree P);

/*
Nama    :
NIM     :
*/
void Level_order(Isi_Tree X, int Maks_node);

/*
Nama    : Aryo Rakatama
NIM     : 221524003
*/
// Penggunaan pertama pada modul utama adalah
// PrintTree(X, 1, 0);
// Dimana X adalah variabel bertipe Isi_Tree yang menujuk pada Tree yang dimaksud
// 1 adalah index awal yang digunakan, jangan menggunakan 0 karena akan membuat sistem kebingungan antara null dan index ke 0
// 0 adalah initialisasi awal dari level, karena perlu mengunjungi root terlebih dahulu, maka diisi 0
void PrintTree(Isi_Tree p, address P, int level)
{
    if (P != 0)
    {
        for (int i = 1; i <= level; i++)
        {
            if (i < level)
            {
                printf("|  ");
            }
            else
            {
                printf("|--");
            }
        }
        printf("%c\n", p[P].info);
        PrintTree(p, p[P].ps_fs, level + 1);
        PrintTree(p, p[P].ps_nb, level);
    }
}

/*
Nama    :
NIM     :
*/
boolean Search(Isi_Tree P, infotype X);

/*
Nama    : Akmal G. Hartono
NIM     : 221524002
*/
int NSearch(Isi_Tree P, infotype X){
    int i;
    for(i = 1; i <= jml_maks; i++){
	if(P[i].info == X){
	   return i;
           break;
	}
    }
}

/*
Nama    : Naffa Lenteranisa
NIM     : 221524023
*/
int nbElmt(Isi_Tree P){
    int count = 0;
    int i;

    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') { // Node tidak kosong
            count++;
        }
    }

    return count;
}

/*
Nama    :
NIM     :
*/
int nbDaun(Isi_Tree P);

/*
Nama    :
NIM     :
*/
int Level(Isi_Tree P, infotype X);

/*
Nama    :
NIM     :
*/
int Depth(Isi_Tree P);

/*
Nama    :
NIM     :
*/
int Max(infotype Data1, infotype Data2);

/*
Nama    :
NIM     :
*/
int Derajat(Isi_Tree P, infotype X);

/*
Nama    :
NIM     :
*/
int Degree(Isi_Tree P, infotype X);
