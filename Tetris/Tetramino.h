#include <SFML/Graphics.hpp>
#include <vector>

enum TypeTetramino { I, J, L, O, S, T, Z };

using namespace std;

typedef vector<vector<sf::RectangleShape>> tetramino;

class Tetramino {

private:
	//Graphique
	tetramino							_tetramino;
	sf::Color							_color;
	//Logique
	int									tailleX;
	int									tailleY;
	TypeTetramino						type;

public:
	Tetramino(TypeTetramino &t);
	void tourneAGauche();
	void tourneADroite();
	void creerNouveauTetramino();
	void setNouveauType(TypeTetramino &t);
	tetramino getTetramino();
	int getTailleX();
	int getTailleY();
	void genere();
	void draw(sf::RenderTarget &renderer, int posX, int posY);
};