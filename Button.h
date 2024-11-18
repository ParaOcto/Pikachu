#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Button{
public:
    float x, y;
    RectangleShape button;
    
    Button(){}
    Button(float xx, float yy, Vector2f size, Color backgroundColor) : x(xx), y(yy) {

        button.setSize(size);
        button.setFillColor(backgroundColor);

    }
    void drawto(RenderWindow& window){
        window.draw(button);    
    }
    void setPosition(){
        button.setPosition(x, y);
    }
};