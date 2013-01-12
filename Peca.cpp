#include "Pecas.h"

Pecas::Pecas(){
	//this->ehDama = false;
}

Pecas::Pecas(bool x){
	this->cor = x;
	this->ehDama = false;
}

bool Pecas::GetCor(){
	return this->cor==true;
}

bool Pecas::GetEhDama(){
	return this->ehDama==true;
}
