#include "jogo.h"
#include <math.h>
#include "Casa.h"
#include <QDebug>

jogo * jogo::instance = NULL;
jogo::jogo()
{
   tab = NULL;
   newGame();
    //ctor
}

jogo::~jogo()
{
    //dtor
}

void jogo::attach(iView *observer)
{
    observers.append(observer);
}

void jogo::dettach(iView *observer)
{
    observers.removeOne(observer);
}
void jogo::notify(QString changeId)
{
    for(int i=0;i<observers.size();i++)
        observers.at(i)->updateView(changeId);
}

void jogo::move(int xOrigem,int yOrigem,int xDest,int yDest) throw (exception)
{

        // Testes de inicialização                                              // Tabuleiro nao foi inicializdo ?? exceção de inicializacão
        if(tab == NULL)
            throw exception();
        // Fim dos testes de inicialização


        Casa *origem  = tab->GetDadosCasa(xOrigem,yOrigem);
        Casa *destino = tab->GetDadosCasa(xDest,yDest);

        //Testes Inicias do movimeto
        if(origem->GetCor() == true ||                                         // Casas sao brancas ?? exceção de movimento
           destino->GetCor() == true)
            throw exception();

        if(origem->GetPedra() == NULL)                                          // Existe peça a ser movida ?? exceção de movimento
            throw exception();

        if(destino->GetPedra() != NULL)                                         // Casa de destino ocupada ?? exceção de movimento
            throw exception();

        if(!ehDistanciaValida(*origem,*destino,sqrt(2)) &&                      // Distancia entre as casas eh valida ?? exceção de movimento
           !ehDistanciaValida(*origem,*destino,2*sqrt(2)))
            throw exception();
         // Fim dos teste inicias  !

        if(ehMovimentoValido(*origem,*destino))                                 // eh movimento ?
        {
            tab->AtualizaCasasMS(*origem,*destino);
            notify("Moved");
        }
        else if(ehCapturaValida(*origem,*destino))                              // eh Captura ?
        {
            tab->AtualizaCasasCap(*origem,*destino,
                                  *getPecaItermValida(*origem,*destino));
            notify("Moved");

        }
        else                                                                    // Nao eh movimento nem captura ?? exceção de movimento
        {
            throw  exception();
        }
}

void jogo::newGame()
{
    tab = new Tabuleiro();
    notify("Begin");
}

bool jogo::ehDistanciaValida(Casa origem, Casa destino,float distValida)
{
    if( (int)origem.Distancia(destino) == (int)distValida)                      // Distancia valida ?
        return true;
    else
       return false;
}

bool jogo::ehDirecaoMoveValida(Casa origem, Casa destino)
{
        if(origem.GetPedra()->GetCor()==true)                                   // Peça branca ou preta ?
        {
            if(origem.GetX() - destino.GetX() < 0)                              // Direção valida para peça branca ?
                return true;
        }
        else
        {
            if(origem.GetX() - destino.GetX() > 0)                              // Direção valida para peça preta ?
                return true;
        }
        return false;
}

bool jogo::ehMovimentoValido(Casa origem, Casa destino)
{
    return ehDirecaoMoveValida(origem,destino) &&                               // Direção e distancia validas ?
            ehDistanciaValida(origem,destino,sqrt(2));

}

bool jogo::ehCapturaValida(Casa origem,Casa destino)
{
    Pecas * CasaInter = getPecaItermValida(origem,destino)->
                                                    GetPedra();

    if(CasaInter!=NULL)                                                         // Existe peça intermediaria ? -- senão captura eh invalida!
        if(CasaInter->GetCor() != origem.GetPedra()->GetCor())                  // Peça a ser captura eh de cor diferente da peça a ser movida ?
                    return true;

    return false;
}

Casa* jogo::getPecaItermValida(Casa origem,Casa destino)
{
    return tab->GetDadosCasa((origem.GetX() + destino.GetX())/2,
                             (origem.GetY() + destino.GetY())/2);
}

jogo* jogo::getInstance()
{
    if(instance == 0)
    {
        instance = new jogo();
        return instance;
    }
    return instance;
}
