#include <iostream>
#include <random>

//Classe Sobre o Gavião
class Gaviao
{
   public:
	 int qnt_gaviao = 5000;    	  //Quantidade de gaviões
	 int energia_gaviao = 100;	 //Energia dos Gaviões
	 int attack_gaviao = 50; 	//Força de Ataque dos Gaviões
};

//Classe Sobre o Pombo
class Pombo
{
   public:
   int qnt_pombo = 5000;      //Quantidade de Pombo
   int energia_pombo = 100;  //Energia dos Pombos
   int run_pombo = 10;      //Corrida dos Pombos
};

//Função que retorna um inteiro random
int randomico()
{
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution <unsigned long long> dis;
  return (dis(gen)%10);
}


//Função da luta entre Gavião e Pombo
int fight(Gaviao a, Pombo b)
{
  srand(time(NULL));
  
  //Enquanto eles tiverem energia eles Lutam entre si
  
  while(b.energia_pombo >= 0 or a.energia_gaviao >= 0)
  {
    int rodada = 0;
    auto resultado = randomico();
    
    //caso o rand seja par ocorre do ataque do gavião
    if(resultado % 2 == 0)
    {
      //ANALISAR
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
      
      //FIM ANALISE

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
    

    //Se o Gavião Ficar Sem Energia ele perde a rodada
    if(a.energia_gaviao <= 0)
    {
      a.qnt_gaviao -= 1;
      a.energia_gaviao = 100;
      b.energia_pombo = 100;
    }
    
    //Se o Pombo Ficar Sem Energia ele perde a rodada
    if(b.energia_pombo <= 0)
    {
      b.qnt_pombo -= 1;
      a.energia_gaviao = 100;
      b.energia_pombo = 100;
    }
    
    //Condição do Fim da Luta
    if (a.qnt_gaviao < 1000)
    {
     //std::cout << "QUANTIDADE DE GAVIAO " << a.qnt_gaviao << " QUANTIDADE DE POMBO " << b.qnt_pombo << std::endl;
     //std::cout << "Gaviao perdeu a geração\n";
     return 1;
    }
    
    //Condição do Fim da Luta
    if(b.qnt_pombo < 1000)
    {
      //td::cout << "QUANTIDADE DE GAVIAO " << a.qnt_gaviao << " QUANTIDADE DE POMBO " << b.qnt_pombo << std::endl;
      //std::cout << "Pombo perdeu a geração\n";
      return 2;
    }
  }
}


int main()
{
	Gaviao a;
	Pombo b;
    
    int vit_pombo = 0;
    int vit_gaviao = 0;
    
    for (int i = 0; i < 500; ++i)
    {
     	if(fight(a, b) == 1);
     	vit_gaviao++;

     	if(fight(a,b) == 2)
     	vit_pombo++;

        std::cout << "Round "<<  i << std::endl;
    }

    std::cout << "Vitorias: Pombo " << vit_pombo << " Vitorias: GAVIAO " << 500 - vit_pombo;
    std::cout << std::endl; 

	return 0;
}
