/* 
 * File:   Persistencia.h
 * Author: Laís
 *
 * Created on 11 de Fevereiro de 2013, 19:38
 */

#ifndef PERSISTENCIA_H
#define	PERSISTENCIA_H

#include <string>
using namespace std;

class Persistencia {
public:
    Persistencia();
    void Salvar (jogo Partida) = 0;
    jogo Carregar () = 0;
    virtual ~Persistencia();
private:

};

#endif	/* PERSISTENCIA_H */

