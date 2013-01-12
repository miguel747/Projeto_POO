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
				Casa NewMatriz(i,j,true,NULL);
				this->matriz[i][j] = NewMatriz;
			}
			if( ( (i%2) ==0 && (j%2) ==1 ) || ( (i%2)==1 && (j%2) ==0 )  ){//pretas linhas pares
				if(i<3){//peca clara
					Casa NewMatriz(i,j,false,auxPecaB);
					this->matriz[i][j] = NewMatriz;
				}
				if(i>4){//pecas escuras
					Casa NewMatriz(i,j,false,auxPecaP);
					this->matriz[i][j] = NewMatriz;
				}
				if(i==3 || i==4){//para i=3 e i=4 que nao possui pecas
					Casa NewMatriz(i,j,false,NULL);
					this->matriz[i][j] = NewMatriz;
				}
			}
		}
	}
    this->numPecasBrancas = 12;
    this->numPecasPretas = 12;
}

Casa* Tabuleiro::GetDadosCasa(int x, int y){
	Casa* auxCasa = &this->matriz[x][y];
	if( x>7 || y>7 ){
		return NULL;
	}
	return auxCasa;
}

void Tabuleiro::AtualizaCasasMS(Casa origem, Casa destino){
	Pecas auxPeca(true);
	for (int i = 0; i < 8; ++i){
		for (int j = 0; i < 8; ++j){
			if(origem.GetX() == i && origem.GetY() == j){
				auxPeca = origem.GetPedra();
				this->matriz[i][j].SetPedras(NULL);
			}
			if(destino.GetY() == i && destino.GetY() == j)
				this->matriz[i][j].SetPedras(&auxPeca);
		}
	}
}

void Tabuleiro::AtualizaCasasCap(Casa origem, Casa destino, Casa intermediaria){
	Pecas auxPeca(true);
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++i){
			if(intermediaria.GetX() == i && intermediaria.GetY() ==j){
				auxPeca = intermediaria.GetPedra();
				this->matriz[i][j].SetPedras(NULL);
				if(auxPeca.GetCor() == true)
					this->numPecasBrancas--;
				else
					this->numPecasPretas--;
			}
			if (origem.GetX() == i && origem.GetY() == j)
			{
				auxPeca = origem.GetPedra();
				this->matriz[i][j].SetPedras(NULL);
			}
			if (destino.GetX() == i && destino.GetY() == j)
				this->matriz[i][j].SetPedras(&auxPeca);
		}
	}
}
