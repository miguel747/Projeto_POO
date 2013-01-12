#ifndef PECAS_H
#define PECAS_H

#include <iostream>

using namespace std;

class Pecas
{
    private:
        bool cor;
        bool ehDama;
    public:
		Pecas();
        Pecas(bool cor);
        bool GetCor();//se 1 eh branca se 0 eh preta
        bool GetEhDama();//se 1 eh dama se 0 nao eh
};

#endif // PECA_H
