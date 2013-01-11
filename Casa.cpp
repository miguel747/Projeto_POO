#include "Casa.h"
#include <math.h>

Casa::Casa(){}

Casa::Casa(int x, int y, bool cor, Pecas* pedra){
	this->x = x;
	this->y = y;
	this->cor = cor;
	this->pedra = pedra;
}

float Casa::Distancia(Casa outra){
	float dist;
	int x1 = this->GetX(); int x2 = outra.GetX();
	int y1 = this->GetY(); int y2 = outra.GetY();
	dist = sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
	return dist;
}

void Casa::SetPedras(Pecas* outra) throw(string){
	if(this->pedra != NULL)
		throw "ErroSP";
	else
		this->pedra = outra;
}

void Casa::SetX(int x){
    this->x=x;
    this->y=y;
}

void Casa::SetY(int y){/
    this->y=y;
}

