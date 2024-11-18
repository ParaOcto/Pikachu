#include "inGame.h"
#include <string.h>

using namespace sf;

void GenInGameScreen(sf::RenderWindow& app){
    app.close();
    RenderWindow window(VideoMode(1800, 1100), "Text");
    Button tp[12][10];
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 10; ++j) {
            float u = i * 80;
            float v = j * 60;
            tp[i][j] = Button(u + 450, v + 200, {70, 50}, Color::White);
            tp[i][j].setPosition();
        }
    }
    while (window.isOpen()){
        Event event;

        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 10; j++)
                tp[i][j].drawto(window);
        window.display();
    }
}