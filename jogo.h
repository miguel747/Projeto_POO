#ifndef JOGO_H
#define JOGO_H

#include "Tabuleiro.h"

class jogo
{
    public:
        /** Default constructor */
        jogo();
        /** Default destructor */
        virtual ~jogo();

        /** move pe�a */
        Tabuleiro move(Casa origem, Casa destino) throw(exception);
        Tabuleiro captura(Casa origem,Casa destino) throw(exception);
        Tabuleiro newGame();

    //protected:
    private:
        Tabuleiro *tab; //!< Member variable "tab"
        /**/
        bool ehDistanciaValida(Casa,Casa,float);
        bool ehDirecaoValida(Casa,Casa);
        bool ehMovimentoValido(Casa,Casa);
        bool ehCapturaValida(Casa origem,Casa destino);
        int calcDirecaoCaptura(Casa origem, Casa destino) throw (exception);
        Casa* AtualizaJogoCaptura(int x,int y,Casa origem) throw (exception);
};

#endif // JOGO_H

