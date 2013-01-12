#include "jogo.h"
#include <math.h>
#include <iostream>
#define pi acos(-1)
#include <stdlib.h>
using namespace std;

/* Construtores / Destrutores */
jogo::jogo()
{
   tab = NULL;
    //ctor
}

jogo::~jogo()
{
    //dtor
}

/* Logica interna  */
bool jogo::ehDistanciaValida(Casa origem, Casa destino,float distValida)
{
    if( (int)origem.Distancia(destino) == (int)distValida)
    {
        if(destino.GetPedra() != NULL)
            return true;
        else
            return false;
    }
    else
       return false;
}

bool jogo::ehDirecaoValida(Casa origem, Casa destino)
{
    try
    {
        if(origem.GetPedra() != NULL)
        {
            system("pause");
            origem.GetPedra()->GetCor();
            system("pause");
            if(origem.GetPedra()->GetCor()==true)
            {
                system("pause");
                if(origem.GetY() - destino.GetY() < 0)
                    return true;
            }
            else
            {
                if(origem.GetY() - destino.GetY() > 0)
                    return true;
            }
        }
        return false;
    }
    catch (exception)
    {
        throw exception();
    }
}

bool jogo::ehMovimentoValido(Casa origem, Casa destino)
{
    return ehDirecaoValida(origem,destino) &&
           ehDistanciaValida(origem,destino,sqrt(2));
}

bool jogo::ehCapturaValida(Casa origem,Casa destino)
{
    if(ehDistanciaValida(origem,destino,2*sqrt(2)))
    {
        switch (calcDirecaoCaptura(origem,destino))
        {
            case 1:
                try
                {
                  tab->AtualizaCasasCap(origem,destino,*AtualizaJogoCaptura(-1,1,origem));

                   break;
                }
                catch(exception)
                {
                    return false;
                }
            case 2:
                try
                {
                  tab->AtualizaCasasCap(origem,destino,*AtualizaJogoCaptura(-1,-1,origem));
                   break;
                }
                catch(exception)
                {
                    return false;
                }
            case 3:
                try
                {
                 tab->AtualizaCasasCap(origem,destino,*AtualizaJogoCaptura(1,1,origem));
                   break;
                }
                catch(exception)
                {
                    return false;
                }
            case 4:
                try
                {
                 tab->AtualizaCasasCap(origem,destino,*AtualizaJogoCaptura(1,-1,origem));
                   break;
                }
                catch(exception)
                {
                    return false;
                }


        return true;

        }
    }
}

Casa* jogo::AtualizaJogoCaptura(int x,int y, Casa origem) throw (exception)
{
    if(tab->GetDadosCasa(origem.GetX()+x,origem.GetY()+y)->GetPedra()->GetCor()!=origem.GetPedra()->GetCor())
    {
        return tab->GetDadosCasa(origem.GetX()+x,origem.GetY()+y);
    }
    else
    {
        throw exception();
    }
}

int jogo::calcDirecaoCaptura(Casa origem, Casa destino) throw (exception)
{
    if(origem.GetX() - destino.GetX() <0 && origem.GetY() - destino.GetY()<0)
        return 4;

    if(origem.GetX() - destino.GetX() <0 && origem.GetY() - destino.GetY()>0)
        return 3;

    if(origem.GetX() - destino.GetX() >0 && origem.GetY() - destino.GetY()>0)
        return 2;

    if(origem.GetX() - destino.GetX() >0 && origem.GetY() - destino.GetY()<0)
        return 1;

    else
        throw exception();
}

/* Interface do jogo */
Tabuleiro jogo::move(Casa origem, Casa destino) throw (exception)
{
    if(tab == NULL)
    {
        throw exception(); // lan�a excessao de inicializa�ao errada
    }

    if(ehMovimentoValido(origem,destino))
    {
        system("pause");
        tab->AtualizaCasasMS(origem,destino);
        return *tab;
    }
    else
    {
        throw exception(); //lan�a excessao de movimento invalido
    }
}

Tabuleiro jogo::captura(Casa origem,Casa destino) throw (exception)
{
    if(!ehCapturaValida(origem,destino))
        throw exception();
}

Tabuleiro jogo::newGame()
{
    tab = new Tabuleiro();
    return *tab;
}


