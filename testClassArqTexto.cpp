/*
 * File:   newtestclass.cpp
 * Author: Laís
 *
 * Created on 17/02/2013, 04:27:30
 */

#include "testClassArqTexto.h"
#include "arqtexto.h"


CPPUNIT_TEST_SUITE_REGISTRATION(arqtextTeste);

arqtextTeste::arqtextTeste() {
}

arqtextTeste::~arqtextTeste() {
}

void arqtextTeste::setUp() {
    teste_1 = arqtexto();
}

void arqtextTeste::tearDown() {
    delete teste_1;
    
}

void arqtextTeste::testCarregar() {
    jogo* result = teste_1.Carregar();
    
    CPPUNIT_ASSERT(result);
}

void arqtextTeste::testSalvar() {
    jogo *Partida = new getInstance();
    
    int linha,coluna;
    
    CPPUNIT_ASSERT(teste_1.Salvar(*Partida));
}

void arqtextTeste::testSalvarCarregar(){
    
    int linha,coluna;
    
    jogo* result = new getInstance();
    jogo *Partida = new getInstance();
    
    teste_1.Salvar(*Partida);
    result = teste_1.Carregar();
    
    for(linha=0;linha<8;linha++)
    {
            for(coluna=0;coluna<8;coluna++)
            {
                CPPUNIT_ASSERT_EQUAL(this->CorPedra(linha,coluna,Partida),this->CorPedra(linha,coluna,result));
                CPPUNIT_ASSERT_EQUAL(this->StatusPedra(linha,coluna,Partida),this->StatusPedra(linha,coluna,result));
            }
    }
}

