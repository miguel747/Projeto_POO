//#include "..\include\BancoDeDados.h"
#include <exception>
#include <stdio.h>
#include <stdlib.h>

BancoDeDados::BancoDeDados() throw(exception)
{
    m_BD = fopen("position.txt","w");
    if(m_BD == NULL)
      throw exception();
    fclose(m_BD);
}

BancoDeDados::~BancoDeDados()
{
    //dtor
}

void BancoDeDados::salvaPosicao(posicaoAtualJogo P)
{
    string hi;
    char di[30];
    this->m_BD = fopen("position.txt","w+");
    if(m_BD == NULL)
        throw exception();
    fprintf(m_BD,"%s\n",P.Getjogador1().c_str());
    fprintf(m_BD,"%s",P.Getjogador2().c_str());
}

