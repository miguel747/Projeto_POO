#include "Tabuleiro.h"

Tabuleiro::Tabuleiro(){
	int i=0,j=0;
	Pecas* auxPecaB = new Pecas(true);
	Pecas* auxPecaP = new Pecas(false);
	numPecasBrancas = 12;
    numPecasPretas = 12;
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			if( ( (i%2)==0 && (j%2)  ==0 ) || ( (i%2) == 1 && (j%2) == 1) ){//brancos linhas pares
				Casa *NewMatriz = new Casa(i,j,true,NULL);
				this->matriz[i][j] = NewMatriz;
			}
			if( ( (i%2) ==0 && (j%2) ==1 ) || ( (i%2)==1 && (j%2) ==0 )  ){//pretas linhas pares
				if(i<3){//peca clara
					Casa *NewMatriz = new Casa(i,j,false,auxPecaB);
					this->matriz[i][j] = NewMatriz;
				}
				if(i>4){//pecas escuras
					Casa *NewMatriz = new Casa(i,j,false,auxPecaP);
					this->matriz[i][j] = NewMatriz;
				}
				if(i==3 || i==4){//para i=3 e i=4 que nao possui pecas
					Casa *NewMatriz = new Casa(i,j,false,NULL);
					this->matriz[i][j] = NewMatriz;
				}
			}
		}
	}
    this->numPecasBrancas = 12;
    this->numPecasPretas = 12;
}

Casa* Tabuleiro::GetDadosCasa(int x, int y){
	Casa* auxCasa = this->matriz[x][y];
	if( x>7 || y>7 ){
		return NULL;
	}
	return auxCasa;
}

void Tabuleiro::AtualizaCasasMS(Casa origem, Casa destino){

this->matriz[destino.GetX()][destino.GetY()]->                                  // Destino recebe peça
     SetPedras(this->matriz[origem.GetX()][origem.GetY()]->GetPedra());
this->matriz[origem.GetX()][origem.GetY()]->SetPedras(NULL);                    // Origem perde peça
}

void Tabuleiro::AtualizaCasasCap(Casa origem, Casa destino, Casa intermediaria){

	this->matriz[destino.GetX()][destino.GetY()]->                              // Destino recebe peça
          SetPedras(this->matriz[origem.GetX()][origem.GetY()]->GetPedra());
    this->matriz[origem.GetX()][origem.GetY()]->SetPedras(NULL);                // Origem perde peça
    this->matriz[intermediaria.GetX()][intermediaria.GetY()]->SetPedras(NULL);  // Itermediaria perde peça
}
