#ifndef  DECODER_H
#define  DECODER_H
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

class Item{
  int chave;
  char letra;
  public:
  Item(){ }
  void setChave(int n){chave=n; letra= char(n);}
  int getChave(){return chave;}
  char getLetra(){return letra;}
};

class No{
  No *esq;
  No *dir;
  Item item;
  public:
  No(){item.setChave(-1); esq =NULL; dir=NULL;}
  friend class Arvore;
};

class Arvore{
No *raiz;
void insrec (No * &p,Item item){if (p==NULL){p=new No(); p->item = item;}else{if(item.getChave()<p->item.getChave())insrec(p->esq,item);else insrec(p->dir,item);}}  
void acharec(No *p, Item item){ int randnum = rand()%10; if(item.getChave()== p->item.getChave()) return;else if(item.getChave() < p->item.getChave()){ while(randnum %2==0)randnum=rand()%10; cout<< randnum;  acharec(p->esq,item); }else { while(randnum%2==1)randnum=rand()%10; cout<<randnum;acharec (p->dir,item);}}

void decodrec(No * &p, char c){ int num;if(c=='x') {cout<< p->item.getLetra(); p=raiz; }else {num = int(c);if(num%2==1){p=p->esq;} else { p= p->dir;}}}
void apgrec (No *p){  if(p->esq !=NULL){apgrec(p->esq);}   if(p->dir != NULL){ apgrec(p->dir); } if(p!=NULL){ delete p;}}
public:
void limpa (){apgrec(raiz);}
Arvore(){raiz=NULL;}
~Arvore(){limpa();}

void insere(Item item ){insrec(raiz,item);}
void codifica(Item item) {cout<<"x";acharec(raiz,item);}
void decod(string s){No *p = raiz;for(auto c:s) decodrec(p,c);cout<<p->item.getLetra()<<endl;}
};


#endif