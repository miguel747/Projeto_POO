/* 
 * File:   testClassTabuleiro.h
 * Author: Laís
 *
 * Created on 17 de Fevereiro de 2013, 14:28
 */

#ifndef TESTCLASSTABULEIRO_H
#define	TESTCLASSTABULEIRO_H

#include <cppunit/extensions/HelperMacros.h>
#include "Tabuleiro.h"

class testClassTabuleiro : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testClassTabuleiro);

    CPPUNIT_TEST(testCarregar);
    CPPUNIT_TEST(testSalvar);
    CPPUNIT_TEST(testSalvarCarregar);

    CPPUNIT_TEST_SUITE_END();
    
public:
    testClassTabuleiro();
    virtual ~testClassTabuleiro();
    void setUp();
    void tearDown();
    
private:
    void testGetDadosCasa(); 
    void testGetDadosCasa();
     void testSetDadosCasas();
     void testGetPecasBrancas();
     void testGetPecasPretas();
     void testAtualizaCasasMS();
     void testAtualizaCasasCap();
     Tabuleiro tabuleiro;
};

#endif	/* TESTCLASSTABULEIRO_H */


