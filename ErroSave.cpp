/* 
 * File:   ErroSave.cpp
 * Author: Laís
 * 
 * Created on 12 de Fevereiro de 2013, 01:04
 */

#include "ErroSave.h"

ErroSave::ErroSave(string erro) {
    this->excessao=erro;
}

void ErroSave::ShowErro() {
    cout<<this->excessao<<endl;
}

ErroSave::~ErroSave() {
}

