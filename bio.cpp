#include <iostream>
#include <random>

class Gaviao
{
   public:
	 int qnt_gaviao = 5000;
	 int energia_gaviao = 100;
	 int attack_gaviao = 50;
};

class Pombo
{
   public:
   int qnt_pombo = 5000;
   int energia_pombo = 100;
   int run_pombo = 10;
};

int randomico()
{
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution <unsigned long long> dis;
  return (dis(gen)%10);
}


void fight(Gaviao a, Pombo b)
{
  srand(time(NULL));
  
  while(b.energia_pombo >= 0 or a.energia_gaviao >= 0)
  {
    int rodada = 0;
    auto resultado = randomico();
    
    //caso o rand seja par ocorre do ataque do gavião
    if(resultado % 2 == 0)
    {
      //Existe a possibilidade de ataque critico
      //float res = randomico();
   
      //Caso res seja maior ou igual a 4 o ataque é critico
      //if(res >= 4)
      //{
       //a.energia_gaviao -= 50;
       //b.energia_pombo -= 100;
      //}
      
      //Caso não satisfaça a condição acima o ataque é normal
      //else
      //{
        a.energia_gaviao -= 50;
        b.energia_pombo -= 100;
      //}
    }
      
    //Caso o gavião não conecte o ataque o pombo foge
    else
    {
      a.energia_gaviao -= 50;
      b.energia_pombo -= 10;
    }
    
    //Ao fim de cada ataque/ataque ocorre a perca de energia pelo tempo no ar
    a.energia_gaviao -= 10;
    b.energia_pombo -= 10;

    if(a.energia_gaviao <= 0)
    {
      a.qnt_gaviao -= 1;
      a.energia_gaviao = 100;
      b.energia_pombo = 100;
    }

    if(b.energia_pombo <= 0)
    {
      b.qnt_pombo -= 1;
      a.energia_gaviao = 100;
      b.energia_pombo = 100;
    }

    if (a.qnt_gaviao < 1000)
    {
     std::cout << "QUANTIDADE DE GAVIAO " << a.qnt_gaviao << " QUANTIDADE DE POMBO " << b.qnt_pombo << std::endl;
     std::cout << "Gaviao perdeu a geração\n";
     break;
    }

    if(b.qnt_pombo < 1000)
    {
      std::cout << "QUANTIDADE DE GAVIAO " << a.qnt_gaviao << " QUANTIDADE DE POMBO " << b.qnt_pombo << std::endl;
      std::cout << "Pombo perdeu a geração\n";
      break;
    }
  }
}


int main()
{
	Gaviao a;
	Pombo b;

	fight(a, b);

	return 0;
}
