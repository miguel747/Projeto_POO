/* 
 * File:   testClassTabuleiro.cpp
 * Author: Laís
 * 
 * Created on 17 de Fevereiro de 2013, 14:28
 */

#include "testClassTabuleiro.h"
#include "Tabuleiro.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

testClassTabuleiro::testClassTabuleiro() {
}

void testClassTabuleiro::setUp(){
    tabuleiro = Tabuleiro ();
}

void testClassTabuleiro::tearDown(){
    delete tabuleiro;
}

testClassTabuleiro::~testClassTabuleiro(){
}

testClassTabuleiro::testClassTabuleiro() {
}

void testClassTabuleiro::testGetDadosCasa(){
    
    CPPUNIT_ASSERT(!tabuleiro.GetDadosCasa(8,8));
    CPPUNIT_ASSERT(tabuleiro.GetDadosCasa(7,7));
    CPPUNIT_ASSERT(tabuleiro.GetDadosCasa(6,6));
    
}

void testClassTabuleiro::testSetDadosCasas(){
}

void testClassTabuleiro::testGetPecasBrancas(){
}

void testClassTabuleiro::testGetPecasPretas(){
}

void testClassTabuleiro::testAtualizaCasasMS(){
    Pecas *pedra1 = new Pecas(false);
    Pecas *pedra2 = new Pecas(true);
    Casa casa1 = Casa(1,1,false,pedra1);
    Casa casa2 = Casa(2,2,true,pedra2);
    
    CPPUNIT_ASSERT(tabuleiro.AtualizaCasasMS(casa1, casa2));
    CPPUNIT_ASSERT_EQUAL(false,casa2->GetPedra()->GetCor());
    CPPUNIT_ASSERT_EQUAL(NULL,casa2->GetPedra());
}

void testClassTabuleiro::testAtualizaCasasCap(){
    Pecas *pedra1 = new Pecas(false);
    Pecas *pedra2 = new Pecas(true);
    Casa casa1 = Casa(1,1,false,pedra1);
    Casa casa2 = Casa(2,2,true,pedra2);
    Casa casa3 = Casa(3,3,false,pedra2); 
    
    CPPUNIT_ASSERT(tabuleiro.AtualizaCasasCap(casa1, casa3, casa2));
    CPPUNIT_ASSERT_EQUAL(NULL,casa1->GetPedra());
    CPPUNIT_ASSERT_EQUAL(NULL,casa2->GetPedra());
    CPPUNIT_ASSERT_EQUAL(false,casa3->GetPedra()->GetCor());
}
