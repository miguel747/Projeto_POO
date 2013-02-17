/* 
 * File:   arqtexto.h
 * Author: Laís
 *
 * Created on 11 de Fevereiro de 2013, 19:57
 */

#ifndef ARQTEXTO_H
#define	ARQTEXTO_H

#include "jogo.h"
#include "Pecas.h"
#include "ErroSave.h"
#include<iostream>
#include <fstream.h>

using namespace std;

class arqtexto : public Persistencia {
public:
    arqtexto();
    void Salvar (jogo Partida);
    jogo* Carregar (void);
    virtual ~arqtexto();
private:
    fstream persistencia;
    void LeArquivo(fstream arquivo) throw(ErroSave);
    void EscreveArquivo (fstream arquivo) throw(ErroSave);
    void FechaArquivo (fstream arquivo);
    bool CorPedra(int, int,jogo);
    bool StatusPedra(int, int,jogo);
    void AnalisaJogo (jogo Partida) throw (ErroSave);
    

};

#endif	/* ARQTEXTO_H */

