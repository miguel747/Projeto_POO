/*
 * File:   Interface.h
 * Author: Laís
 *
 * Created on 15 de Dezembro de 2012, 02:34
 */

#ifndef INTERFACE_H
#define	INTERFACE_H

#include <string>
#include "jogo.h"

class Interface {
public:
    Interface();
    virtual ~Interface();
    void OpcoesIniciais();

private:
    jogo Jogo;
    Tabuleiro Mesa; //Essa parte tem que verificar quais parametros ele vai receber
    //Instrucoes Manual;
    string Player1, Player2;

    void MostraTabuleiro(Tabuleiro Mesa);
    void TelaJogo(string , string );
    int Pontuacao (Tabuleiro );
    char Jogada(Tabuleiro ,string);
};

#endif	/* INTERFACE_H */

