#ifndef JOGO_H
#define JOGO_H

#include "Tabuleiro.h"
#include <exception>

class jogo
{
    public:

        /** Default destructor */
        virtual ~jogo();


        static jogo *getInstance();
        /** move peça */
        Tabuleiro move(int xOrigem,int yOrigem,int xDest,int yDest) throw(exception);
        Tabuleiro newGame();

    private:
        /** Default constructor */
        jogo();
        static jogo *instance;

        Tabuleiro *tab;
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

