#include "nbtrees.h"

/*
Nama    :
NIM     :
*/
void Create_tree(Isi_Tree X, int Jml_Node);

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
Nama    :
NIM     :
*/
int NSearch(Isi_Tree P, infotype X);

/*
Nama    :
NIM     :
*/
int nbElmt(Isi_Tree P);

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
