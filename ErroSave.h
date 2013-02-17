/* 
 * File:   ErroSave.h
 * Author: Laís
 *
 * Created on 12 de Fevereiro de 2013, 01:04
 */

#ifndef ERROSAVE_H
#define	ERROSAVE_H

#include <string>
#include<iostream>

using namespace std;

class ErroSave {
public:
    ErroSave(string erro);
    virtual ~ErroSave();
    void ShowErro(string excessao);
private:
    string excessao;

};

#endif	/* ERROSAVE_H */

