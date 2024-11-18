#include "inGame.h"

using namespace std;
using namespace sf;
int main(){
	sf::RenderWindow app(sf::VideoMode(1800, 1100), "Pikachu Game");

    GenInGameScreen(app);
}