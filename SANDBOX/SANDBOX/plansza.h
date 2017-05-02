#include <iostream>
#include <vector>

#define HEIGTH 20
#define WIDTH 61

using namespace std;

class plansza
{
public:
	plansza();
	~plansza();
	void render();
	void move(char ch);
	int getkierunek();
private:
	vector<vector<char>> pola;
	int playerx;
	int playery1;
	int splayerx;
	int splayery1;
	int ballx;
	int bally;
	int kierunek;
	int player;
	int splayer;


	int getx();
	int gety();
	int sgetx();
	int sgety();
	int getbally();
	int getballx();
	void ball();
};