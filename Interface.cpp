/*
 * File:   Interface.cpp
 * Author: Laís Mendes Goncalves
 *
 * Created on 15 de Dezembro de 2012, 02:34
 */

#include "Interface.h"
#include <iostream>
#include <string>
#include "Casa.h"
#include "Tabuleiro.h"
#include <stdlib.h>

using namespace std;

Interface::Interface() {
}

Interface::~Interface() {
}

void Interface::OpcoesIniciais()
{
    int opcao;

    cout<<"\t\tBem-Vindo ao JOGO DE DAMAS\n\n\n"<<endl;
    cout<<"Opcoes: \n\n"<<endl;
    cout<<"(1) Novo Jogo\n"<<endl;
    cout<<"(2) Carregar Jogo Salvo\n"<<endl;
    cout<<"(3) Instrucoes\n"<<endl;
    cout<<"(4) Sair\n\n"<<endl;

    cout<<"Digite sua opcao: "<<endl;
    cin>>opcao;
    string Player1;
    string Player2;

    switch(opcao)
    {
        case 1:
            //system("cls");


            cout<<"Digite Player 1: "<<endl;
            cin>>Player1;
            cout<<"\nDigite Player 2: "<<endl;
            cin>>Player2;

            TelaJogo(Player1, Player2);

            break;

        case 2:
            //Definir quem vai chamar o que?
            cout<<"Ainda não temos essa função, volte outro dia!!"<<endl;

            break;
        case 3:
            //Chamar função do Manual
            cout<<"Ainda não temos essa função, volte outro dia!!"<<endl;

            break;
        default:
            cout<<"\n\n\nBye!!\n\n"<<endl;
    }
}

int Interface::Pontuacao (Tabuleiro Mesa)
{

    if(Mesa.GetPecasPretas()==0)
    {
        return 1;
    }
    else if(Mesa.GetPecasBrancas()==1)
    {
        return 2;
    }

    cout<<"\t\t\tPontuacao \n"<<endl;
    cout<<"Player 1: "<<(12-Mesa.GetPecasPretas())<< endl;
    cout<<"\t\tPlayer 2: "<<(12-Mesa.GetPecasBrancas())<<"\n\n"<< endl;

    return 0;
}

char Interface::Jogada(Tabuleiro Mesa, string Nome)
{
    int XAnt, XPos, YAnt, YPos;

    Casa CasaAnt= Casa();
    Casa CasaPos= Casa();


    cout<<"Player "<<Nome<<" digite sua jogada (sair = 0):\n\n"<< endl;
    cout<<"Digite X da peca: "<< endl;
    cin>>XAnt;

    if(XAnt==0)
    {
        return 's';
    }

    cout<<"\nDigite y da peca: "<< endl;
    cin>>YAnt;
    cout<<"\nDigite X da casa: "<< endl;
    cin>>XPos;
    cout<<"\nDigite Y da casa: "<< endl;
    cin>>YPos;

    //Mesa=Jogo.move((&(Mesa.GetDadosCasa(XAnt, YAnt))),((&Mesa.GetDadosCasa(XPos, YPos))));
    CasaAnt.SetX(XAnt);
    CasaAnt.SetY(YAnt);
    CasaPos.SetX(XPos);
    CasaPos.SetY(YPos);

    try{
    this->Mesa = Jogo.move(XAnt,YAnt,XPos,YPos);
    system("pause");
    }
    catch(exception e)
    {
        cout<<"aqui ou nao aqui"<<endl;
    }

    //system("cls");
    //se move lançar uma exceção, como fica?
    return 'c';

}

void Interface::TelaJogo(string Player1, string Player2)
{
    char sair,opcao;
    int continuar=1,ganhador;
    string jogador=Player1;

    Mesa=Tabuleiro();
    Jogo=jogo();

    Mesa=Jogo.newGame();

    while(sair!='s')
    {
        ganhador=Pontuacao (Mesa);

        if(ganhador==1)
        {
            cout<<"Parabens "<<Player1<<"voce VENCEU!!"<<endl;
//            system("PAUSE");
//            exit(1);
        }
        else if(ganhador==2)
        {
            cout<<"Parabens "<<Player1<<"voce VENCEU!!"<<endl;
//            system("PAUSE");
//            exit(1);
        }



        while((continuar)&&(sair!='s'))
        {
           try
           {
                MostraTabuleiro(Mesa);
                sair=Jogada(Mesa,jogador);
                continuar=1;
                sair = 'n';
           }
           catch(...)
           {
                cout<<"Jogada inválida!! Tente outra vez!!"<<endl;
           }
        }

        if(jogador.compare(Player1)==0)
        {
            jogador=Player2;
        }
        else
        {
            jogador=Player1;
        }
        //sair = 's';
    }

    cout<<"deseja salvar o jogo? (s/n) "<<endl;
    cin>>opcao;

    if(opcao=='s')
    {
        //Chamar Função que salva o Jogo
        cout<<"Jogo salvo!!"<<endl;
    }
}

void Interface::MostraTabuleiro(Tabuleiro Mesa)
{
    int linha,coluna;

    cout<<"| A  | B  | C  | D  | E  | F  | G  | H  |"<<endl;

    for(linha=0;linha<=7;linha++)
    {
        cout<<linha+1<<"\t"<<endl;

        for(coluna=0;coluna<=7;coluna++)
        {
            if(Mesa.GetDadosCasa(linha,coluna)->GetPedra()==NULL)
            {
               cout<<"|____"/*<<endl*/;
            }
            else
            {
                if(Mesa.GetDadosCasa(linha,coluna)->GetPedra()->GetCor())
                {
                        if(Mesa.GetDadosCasa(linha,coluna)->GetPedra()->GetEhDama())
                        {
                                cout<<"|_DB_"/*<<endl*/;
                        }
                        else
                        {
                                cout<<"|__B_"/*<<endl*/;
                        }
                }
                else
                {
                        if(Mesa.GetDadosCasa(linha,coluna)->GetPedra()->GetEhDama())
                        {
                                cout<<"|_DP_"/*<<endl*/;
                        }
                        else
                        {
                               cout<<"|__P_"/*<<endl*/;
                        }
                }

            }

        }
        cout<<"|\n"<<endl;
    }
}








