#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "decoder.h"
using namespace std;


int main()
{
  srand (time (NULL));
  ifstream entrada;
  entrada.open("entrada.txt");
  string s;
  Arvore a; 
  Item itemaux;
  while(!entrada.eof())
  {
    entrada>>s;
    //cout <<s<< endl;
    if(s=="A:")
    {
      getline(entrada, s);
      s.erase(0,1);
       //cout<< s<<endl; 
      int num;
      for (auto i : s )
      {
         num = int(i);
        itemaux.setChave(num);
        a.insere(itemaux);
      }
    }
    else if (s=="C:")
    {
      getline(entrada, s);
      s.erase(0,1);
       //cout<< s<<endl; 
      int num;
        for(auto i:s)
        {  
          num= int(i);
          itemaux.setChave(num);
          a.codifica(itemaux);
        }
      cout<<endl;
    }
    else if (s=="D:")
    {
      getline(entrada, s);
      s.erase(0,2);
        a.decod(s);
    }
  } 
  return 0;
}
