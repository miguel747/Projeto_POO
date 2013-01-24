#ifndef CASA_H
#define CASA_H
#include "Pecas.h"

class Casa
{
    private:
        int x,y;
        bool cor;//true eh branca e false eh preta
        Pecas* pedra;
    public:
        Casa();
        Casa(int ,int ,bool ,Pecas*);
        int GetX() const{return x;} int GetY() const{return y;} bool GetCor() const{return cor;}
        Pecas* GetPedra() const{return pedra;}
        void SetX(int); void SetY(int);
        float Distancia(Casa outra);//distancia entre duas casas quaisquer
        void SetPedras(Pecas* outra); //throw(string);//insere uma referida pedra na correpondente casa caso esteja vazia
};

#endif // CASA_H
