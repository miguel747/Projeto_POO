/*
 * File:   newtestclass.h
 * Author: Laís
 *
 * Created on 17/02/2013, 04:27:29
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "arqtexto.h"
#include "jogo.h"

class arqtextTeste : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(arqtextTeste);

    CPPUNIT_TEST(testCarregar);
    CPPUNIT_TEST(testSalvar);
    CPPUNIT_TEST(testSalvarCarregar);

    CPPUNIT_TEST_SUITE_END();

public:
    arqtextTeste();
    virtual ~arqtextTeste();
    void setUp();
    void tearDown();

private:
    void testCarregar();
    void testSalvar();
    void testSalvarCarregar();
    arqtexto teste_1;
    

};

#endif	/* NEWTESTCLASS_H */

