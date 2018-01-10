#include<iostream>
#include<string>
#include<random>
#include<ctime>
using namespace std;
void favour(float &dogAttack, float &catAttack);
void gameloop(float &res, bool &dogsWin, float &dogHealth, float &catHealth, int &dogs, int &cats, float &dogAttack, float &catAttack);
void result(bool dogsWin, float res, float dogHealth, int dogs, int cats, float catHealth);
int  main()
{
	cout << "******DOGS vs CATS*******\n";
	int dogs, cats,total,dog,cat;
	float dogHealth, catHealth;
	cout << "enter the number of dogs\n";
	cin >> dogs;                               //number of dogs
	cout << "enter the health per dog\n";
	cin >> dogHealth;                         //health per dog
	cout << "enter the number of cats\n";
	cin >> cats;							//nummber of cats
	cout << "enter the health per cat\n";
	cin >> catHealth;						//health per cat
	cout << "<BATTLE STARTS!!!!!!>\n" << "*BATTLE NOISES*\n";
	float dogAttack, catAttack;
	favour(dogAttack,catAttack);
	bool dogsWin;
	float  res;
	gameloop(res, dogsWin, dogHealth, catHealth, dogs, cats, dogAttack, catAttack);
	result(dogsWin,res,dogHealth,dogs,cats,catHealth);
	system("PAUSE");
	return 0;
}

void favour(float &dogAttack,float &catAttack) {
	static default_random_engine attVal(time(0));			//generating random value
	uniform_real_distribution<float> dogAttk(0.0f, 1.0f); //random attack value for dog
	uniform_real_distribution<float> catAttk(0.0f, 1.0f); //random attack value for cat
	dogAttack = dogAttk(attVal);
	catAttack = catAttk(attVal);
	if (dogAttack > catAttack)
	{
		cout << "AAAH Dogs have better attack this time\n";
	}
	else
	{
		cout << "AAAH Cats have better attack this time\n";
	}
}

void gameloop(float &res,bool &dogsWin,float &dogHealth,float &catHealth,int &dogs,int &cats,float &dogAttack,float &catAttack)
{
	float dogForce, catForce,dogMulti,catMulti;

	dogMulti = dogs * dogHealth;
	catMulti = cats * catHealth;
	
	dogForce = dogAttack*dogMulti;
	catForce = catAttack*catMulti;

	if (dogForce > catForce)
	{

		res = dogForce - catForce;
		dogsWin = 1;
	}
	else {
		res = catForce - dogForce;
		dogsWin = 0;
	}
}

void result( bool dogsWin,float res,float dogHealth,int dogs,int cats,float catHealth)
{
	int total, cat, dog;
	if (dogsWin)
	{
		cout << "dogs win\n";
		total = res / dogHealth;
		dog = total;
		cat = 0;
		cout << dog << " dogs remaining\n" << dogs - dog << " dogs & " << cats << " cats died\n";
	}
	else
	{
		cout << "cats win\n";
		total = res / catHealth;
		cat = total;
		dog = 0;
		cout << cat << " cats remaining\n" << cats - cat << " cats & " << dogs << " dogs died\n";
	}

}