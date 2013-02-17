#ifndef TABULEIRO_H
#define TABULEIRO_H
#include "Casa.h"

class Tabuleiro
{
    private:
    Casa *matriz[8][8];
    int numPecasBrancas, numPecasPretas;

    public:
        Tabuleiro();//ta faltando implementar o que eh preciso receber como parametro
        Casa* GetDadosCasa(int,int);
        void SetDadosCasas(int,int,Casa);
        int GetPecasBrancas() const {return numPecasBrancas;}
        int GetPecasPretas() const {return numPecasPretas;}
        void AtualizaCasasMS(Casa,Casa);
        void AtualizaCasasCap(Casa, Casa, Casa);
};

#endif // TABULEIRO_H
