/* 
 * File:   testmain.cpp
 * Author: Laís
 *
 * Created on 17 de Fevereiro de 2013, 12:40
 */

#include <cstdlib>
#include <iostream>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include "Tabuleiro.h"
#include "testClassTabuleiro.h"

using namespace std

int main() {
    
    CPPUNIT_NS::TestResult controller;
    
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener( &result ); 

    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener( &progress );   
    
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run( controller );
    
    CPPUNIT_NS::CompilerOutputter outputter( &result,CPPUNIT_NS::stdCOut() );
    outputter.write();   
    
    return 0;
}

