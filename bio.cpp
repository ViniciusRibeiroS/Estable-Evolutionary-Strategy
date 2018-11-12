#include <iostream>
#include <ctime>
#include <random>

class Gaviao
{
   public:
	// int qnt_gaviao = 5000;
	 int energia_gaviao = 100;
	 int attack_gaviao = 50;
};

class Pombo
{
   public:
   	// int qnt_pombo = 5000;
	 int energia_pombo = 100;
	 int run_pombo = 10;
};

void cacete(Gaviao a, Pombo b)
{
   srand(time(NULL));
   while(b.energia_pombo > 0 && a.energia_gaviao > 0)
   {
      int resultado = rand()%2;
      std::cout << "Energia inicial pombo " << b.energia_pombo << " energia gaviao " << a.energia_gaviao << std::endl;
      std::cout << "Resultado " << resultado << std::endl;

      if(resultado == 0)
      {
        std::cout << "Gavião atacou\n";
      	a.energia_gaviao -= 50;
        b.energia_pombo -= 100;
      }

      else
      {
      	b.energia_pombo -= 10;
        a.energia_gaviao -= 50;
        std::cout << "Pombo fugiu\n";
      }

      b.energia_pombo -= 10;
      a.energia_gaviao -= 10;
      std::cout << "Energia da rodada pombo " << b.energia_pombo << " energia gaviao " << a.energia_gaviao << std::endl;
   }

}	

int main()
{
	Gaviao a;
	Pombo b;

	cacete(a, b);

	return 0;
}
