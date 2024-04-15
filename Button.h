#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

class Button {
public:
	sf::RectangleShape button;
	sf::Text text;

	Button(){  }

	Button(std::string t, sf::Vector2f size,int charSize, sf::Color backgroundColor, sf::Color textColor) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		button.setSize(size);
		button.setFillColor(backgroundColor);
	}

	void setFont(sf::Font &font) {
		text.setFont(font);
	}

	void setBackgroundColor(sf::Color color) {
		button.setFillColor(color);
	}

	void setTextColor(sf::Color color) {
		text.setFillColor(color);
	}

	void setPosition(sf::Vector2f pos) {
		button.setPosition(pos);

		float xPos = (pos.x + button.getLocalBounds().width / 3 - (text.getLocalBounds().width / 2));
		float yPos = (pos.y + button.getLocalBounds().height / 3 - (text.getLocalBounds().height / 2));
		text.setPosition({xPos,yPos});		
	}

	void drawto(sf::RenderWindow &window) {
		window.draw(button);
		window.draw(text);
	}

	bool isMouseOver(sf::RenderWindow &window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnposX = button.getPosition().x;
		float btnposY = button.getPosition().y;

		float btnposwidth = button.getPosition().x + button.getLocalBounds().width;
		float btnposheight = button.getPosition().y + button.getLocalBounds().height;
		if (mouseX >= btnposX && mouseX <= btnposwidth && mouseY >= btnposY && mouseY <= btnposheight) {
			return true;
		}
		return false;
	}

};

void GenMainMenu();
void GenInGameScreen(sf::RenderWindow& app);
void GenWinScreen();
bool check_couple(Button A, Button B);
bool CheckIMatching(bool IsExist[][10], int x0, int y0, int x1, int y1);
bool CheckZMatching(bool Isexist[][10], int x0, int y0, int x1, int y1);
bool checkLMatching(bool IsExist[][10], int x0, int y0, int x1, int y1);
bool checkUMatching(bool IsExist[][10], int x0, int y0, int x1, int y1, int ROWS, int COLS);
bool checkAll(bool IsExist[][10], int x0, int y0, int x1, int y1, int Rows, int Cols);