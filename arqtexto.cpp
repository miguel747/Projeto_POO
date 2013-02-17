/* 
 * File:   arqtexto.cpp
 * Author: Laís
 * 
 * Created on 11 de Fevereiro de 2013, 19:57
 */

#include "arqtexto.h"
#include <fstream>

using namespace std;

arqtexto::arqtexto() {
}

bool arqtexto::CorPedra(int linha, int coluna, jogo Partida)
{   
    return Partida->getTab()->GetDadosCasa(linha,coluna)->GetPedra()->GetCor();
}

bool arqtexto::StatusPedra(int linha, int coluna, jogo Partida)
{   
    return Partida->getTab()->GetDadosCasa(linha,coluna)->GetPedra()->GetEhDama();
}

void arqtexto::AnalisaJogo (jogo Partida) throw (ErroSave){
    if(!Partida){
        throw ErroSave("Objeto Jogo nulo");
    }
}

void arqtexto::Salvar(jogo Partida) {
    int linha,coluna;
    
    try{
        this->AnalisaJogo(Partida);  
        
        this->EscreveArquivo(persistencia);
    
        for(linha=0;linha<8;linha++)
        {
            for(coluna=0;coluna<8;coluna++)
            {
                if(Partida->getTab()->GetDadosCasa(linha,coluna)->GetPedra())
                {
                    persistencia<<this->CorPedra(linha,coluna,Partida)<<" "<<this->StatusPedra(linha,coluna,Partida)<<" "<<linha<<" "<<coluna<<endl;
                }   
                else
                {
                    persistencia<<"2"<<" "<<"2"<<linha<<" "<<coluna<<endl;
                }
            }
        } 
        this->FechaArquivo();
    }
    catch(ErroSave e)
    {
        e.ShowErro();
    }
    
    
}

jogo* arqtexto::Carregar(void) {
    try{
        this->LeArquivo(persistencia);
        
        Tabuleiro *Partida = new Tabuleiro();
        Casa *casa = new Casa();
        Pecas *pedra = new Pecas();
        jogo *Salvo = jogo::getInstance();

        int cor,dama,linha,coluna;

        while(!persistencia.fail())
        {

            persistencia>>cor;
            persistencia>>linha;
            persistencia>>coluna;

            if(cor=='22' && Partida->GetDadosCasa(linha,coluna)->GetPedra()!=NULL){
                Partida->GetDadosCasa(linha,coluna)->SetPedras(NULL);
            }
            else if(cor!='22')
            {
                persistencia>>dama;

                if(this->CorPedra(linha,coluna,Partida)!=cor || this->StatusPedra(linha,coluna,Partida)!=dama){
                    pedra->cor = cor;
                    pedra->ehDama = dama;
                    Partida->GetDadosCasa(linha,coluna)->SetPedras(pedra);
                }
            } 
         }

        Salvo->tab=Partida;
        return Salvo;
    }
    catch(ErroSave e)
    {
        e.ShowErro();
        return NULL;
    }
    
}

void arqtexto::EscreveArquivo (fstream arquivo)
{
    if(!arquivo.open ("JogoSalvo.txt",ios_base::trunc|ios_base::out))
    {
        throw ErroSave("Arquivo não pode ser aberto para leitura");
    }
}

void arqtexto::LeArquivo(fstream arquivo) throw(ErroSave) {
    if(!arquivo.open ("JogoSalvo.txt",ios_base::in)){
        throw ErroSave("Arquivo não pode ser aberto para escrita");
    }
} 

void arqtexto::FechaArquivo (fstream arquivo)
{
    arquivo.close();
}

arqtexto::~arqtexto() {
}

