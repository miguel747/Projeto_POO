#ifndef JOGO_H
#define JOGO_H

#include "Tabuleiro.h"
#include <exception>
#include <QList>
#include "iview.h"

class jogo
{
    public:

        /** Default destructor */
        virtual ~jogo();


        static jogo *getInstance();

        void attach(iView *observer);
        void dettach(iView *observer);
        void notify(QString changeId);

        Tabuleiro* getTab(){ return tab; }
        /** move peça */
        void move(int xOrigem,int yOrigem,int xDest,int yDest) throw(exception);
        void newGame();

    private:
        /** Default constructor */
        jogo();
        static jogo *instance;

        QList<iView*> observers;

        Tabuleiro *tab;

        QString Player1;
        QString Player2;

        bool ehDistanciaValida(Casa,Casa,float);
        bool ehDirecaoMoveValida(Casa,Casa);
        bool ehMovimentoValido(Casa,Casa);
        bool ehCapturaValida(Casa origem,Casa destino);
        bool ehCapPecaItermValida(Casa origem,Casa destino);
        bool ehDestCapValido(Casa destino);
        Casa* getPecaItermValida(Casa origem,Casa destino);
        int calcDirecaoCaptura(Casa origem, Casa destino) throw (exception);

};

#endif // JOGO_H

