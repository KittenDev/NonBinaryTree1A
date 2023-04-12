#ifndef nbtrees_h
#define nbtrees_h

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

//Maksimal node yang dapat ditampung dalam array

#define nil NULL


/***************************/
/*  Type data */
/***************************/

/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */

/* Kamus */

typedef char infotype;
typedef struct tnbtree *address;
typedef struct tnbtree { 
	infotype  info;
   	address ps_fs, ps_nb, ps_pr;
}nbtree;


/***************************/
/*  S P E S I F I K A S I  */
/***************************/


void Create_tree(address X, int Jml_Node);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order 
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input


boolean IsEmpty (address P);
/* Mengirimkan true jika Isi_Tree KOSONG */



/***** Traversal *****/

void PreOrder (address P);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */

void InOrder (address P);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */

void PostOrder (address P);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder :  fs, nb, Parent */

void Level_order(address X, int Maks_node);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */

void PrintTree (address P);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */



/***** Search *****/

boolean Search (address P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

address NSearch (address P, infotype X);
/* Mengirimkan posisi/indeks node jika ada node dari P yang bernilai X */

/***** Fungsi Lain *****/

int nbElmt (address P);
/* Mengirimkan banyak elemen (node) di pohon non biner P */

int nbDaun (address P);
/* Mengirimkan banyak daun (node) pohon non biner P */

int Level (address P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul */ 
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */

int Depth (address P);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */

int Max (infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */

int Derajat(address P,infotype X);
/* Pohon Non Biner mungkin Kosong, mengirimkan 'derajat' yaitu jml path satu node menuju terminal node */
/* Basis : Pohon Kosong, derajatnya Nol */
/* jml path menuju terminal node ujung paling jauh */

int Degree (address P, infotype X);
/* Pohon Non Biner mungkin Kosong, mengirimkan 'degree' yaitu jumlah anak dari satu node */
/* Basis : Pohon Kosong, degreenya Nol */

#endif

