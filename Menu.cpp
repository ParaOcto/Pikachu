#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>	
#include"Button.h"
#include<string.h>
#include <vector>
#include <math.h>
#include <time.h>
#include "Random.h"
#include "Finishlogin.h"
#include "highscore.h"
#include "Linkedlist.h"

using namespace sf;

void GenInGameScreen(sf::RenderWindow& app)
{
    app.close();

    int count = 100;
    int score = 0;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Test");
    sf::Font font;

    font.loadFromFile("Font/IMMORTAL.ttf");
    Button tp[10][10];
    char **a = getRandom(10, 10);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            string temp = "";
            temp += a[i][j];
            tp[i][j].text.setString(temp);
            tp[i][j].text.setCharacterSize(30);
            tp[i][j].text.setFillColor(sf::Color::Black);
            tp[i][j].button.setFillColor(sf::Color::Green);
            tp[i][j].button.setSize({ 50,50 });
            tp[i][j].setFont(font);
            float u = i * 60;
            float v = j * 60;
            tp[i][j].setPosition({ u + 500,v + 200 });
        }
    }

    tp[0][0].setBackgroundColor(sf::Color::White);
    int x = 0;
    int y = 0;
    std::vector<std::pair<int, int>> couple;
    bool check_[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) check_[i][j] = false;
    }

    list L[10];
    for (int i = 0; i < 10; i++)    L[i].head = L[i].tail = NULL;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)    addHead(L[i], tp[i][j]);
    
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Sound/ClickButton.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    //Timer
    sf::Font timerFont;
    sf::Text timerText;
    timerFont.loadFromFile("Font/IMMORTAL.ttf");
    timerText.setFont(timerFont);
    timerText.setString("00:000");
    timerText.setCharacterSize(100);
    timerText.setFillColor(sf::Color::White);

    // Text Position //
    sf::FloatRect timerTextRect = timerText.getLocalBounds();
    timerText.setOrigin(timerTextRect.left + timerTextRect.width / 2.0f, timerTextRect.top + timerTextRect.height / 2.0f);
    timerText.setPosition(1600 / 2.0f + 600, 100);

    // Timer Variables //
    sf::Clock clock;
    float duration = 180.0f;
    float fMilliseconds, fSeconds;
    int intMilliseconds, intSeconds;
    sf::String stringMilliseconds;
    sf::String stringSeconds;
    sf::String timerString;
    //End of timer variables //

    sf::Text TimerString;
    TimerString.setFont(font);
    TimerString.setString("Timer");
    TimerString.setCharacterSize(100);
    TimerString.setFillColor(sf::Color::White);

    TimerString.setPosition(900, 30);

    while (window.isOpen())
    {
        
        sf::Event event;
        
        // Update clock
        sf::Time time = clock.restart();
        int n, temp;
        std::ifstream ifs("txtFile/score.txt", ios::in);
        
        while(!ifs.eof()) ifs >> n >> temp;
        ifs.close();

        if (duration > 0){
            if (count == 0){
                std::ofstream fout("txtFile/score.txt", ios::in | ios::out | ios::app);
                    fout << ++n << '\n';
                    fout << score << '\n';
                fout.close();
                GameOver(true, score, duration);
                window.close();
            }
        }
        else{
            std::ofstream fout("txtFile/score.txt", ios::in | ios::out | ios::app);
                fout << ++n << '\n';
                fout << score << '\n';
            fout.close();
            GameOver(false, score, 0);
            window.close();
        }

        if (duration > 0) {
            // Calculate countdown
            duration -= time.asSeconds();
            fMilliseconds = std::modf(duration, &fSeconds);
            // Change float to int
            intSeconds = static_cast<int>(fSeconds);
            intMilliseconds = static_cast<int>(fMilliseconds * 1000);
            // Change int to string 
            stringMilliseconds = std::to_string(intMilliseconds);
            stringSeconds = std::to_string(intSeconds);

            if (intMilliseconds <= 0) {
                stringMilliseconds = "000";
            }

            if (intSeconds <= 0) {
                stringSeconds = "00";
            }
            else if (intSeconds < 10) {
                stringSeconds = "0" + stringSeconds;
            }

            timerString = stringSeconds + ":" + stringMilliseconds;
            timerText.setString(timerString);
        }

        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)    window.close();
            if (event.type == sf::Event::KeyPressed) {
                sound.play();
                if (event.key.code == sf::Keyboard::Up){
                    if (x > 0){
                        node* p = L[x].head;
                        for (int i = 0; i < y; i++) p = p->next;
                        p->key.setBackgroundColor(sf::Color::Green);
                        x--;
                        p = L[x].head;
                        for (int i = 0; i < y; i++) p = p->next;
                        p->key.setBackgroundColor(sf::Color::White);
                    }
                }
                else if (event.key.code == sf::Keyboard::Down){
                        if (x < 9){
                            node* p = L[x].head;
                            for (int i = 0; i < y; i++) p = p->next;
                            p->key.setBackgroundColor(sf::Color::Green);
                            x++;
                            p = L[x].head;
                            for (int i = 0; i < y; i++) p = p->next;
                            p->key.setBackgroundColor(sf::Color::White);
                        }
                    }
                        else if (event.key.code == sf::Keyboard::Left){
                                node* p = L[x].head;
                                for (int i = 0; i < y; i++) p = p->next;
                                p->key.setBackgroundColor(sf::Color::Green);
                                y--;
                                p = L[x].head;
                                for (int i = 0; i < y; i++) p = p->next;
                                p->key.setBackgroundColor(sf::Color::White);                              
                            }
                            else if (event.key.code == sf::Keyboard::Right){
                                    node* p = L[x].head;
                                    for (int i = 0; i < y; i++) p = p->next;
                                    p->key.setBackgroundColor(sf::Color::Green);
                                    removePos(L[x], y);
                                    addPos(L[x], y, p->key);
                                    y++;
                                    p = L[x].head;
                                    for (int i = 0; i < y; i++) p = p->next;
                                    p->key.setBackgroundColor(sf::Color::White);
                                    // removePos(L[x], y);
                                    // addPos(L[x], y, p->key);                                           
                                }
                // else if (event.key.code == sf::Keyboard::Space)
                // {
                //     k[x][y].setBackgroundColor(sf::Color::Red);
                //     couple.push_back(std::make_pair(x, y));
                //     if (couple.size() >= 2)
                //     {
                //         int x0 = couple[0].first;
                //         int y0 = couple[0].second;
                //         int x1 = couple[1].first;
                //         int y1 = couple[1].second;
                //         if (x1 == x0 && y1 == y0)
                //         {
                //             k[x1][y1].setBackgroundColor(sf::Color::White);
                //             couple.clear();
                //         }
                //         else if (check_couple(k[x0][y0], k[x1][y1]) == true && checkAll(check_, x0, y0, x1, y1, 10, 10))
                //         {
                            
                //             k[x0][y0].setBackgroundColor(sf::Color::Transparent);
                //             k[x1][y1].setBackgroundColor(sf::Color::Transparent);

                //             check_[x0][y0] = true;
                //             check_[x1][y1] = true;
                //             count -= 2;
                //             score += (duration/18)*10;
                //             couple.clear();
                //         }
                //         else
                //         {
                //             k[x0][y0].setBackgroundColor(sf::Color::Green);
                //             k[x1][y1].setBackgroundColor(sf::Color::White);

                //             couple.clear();
                //         }
                //     }

                 //}
            }
        }

        window.clear();
        for (int i = 0; i < 10; i++) {
            for (node* p = L[i].head; p != NULL; p = p->next)
                p->key.drawto(window);
        }
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                tp[i][j].drawto(window);
        window.draw(TimerString);
        window.draw(timerText);
        window.display();
    }
}

void GenMainMenu()
{
			sf::RenderWindow app(sf::VideoMode(1600, 900), "Pikachu Game");

			sf::Mouse::setPosition(sf::Vector2i(700, 200), app);

			sf::Texture t;
			t.loadFromFile("Picture/pikachu.jpg");
			sf::Sprite s(t);

			sf::Font font;
			font.loadFromFile("Font/IMMORTAL.ttf");

			sf::Text text;
			text.setFont(font);
			text.setString("The Matching Game");
			text.setCharacterSize(60);
			text.setFillColor(sf::Color::Magenta);
			text.setPosition(500, 0);

			sf::SoundBuffer buffer;
			buffer.loadFromFile("Sound/ClickButton.wav");
			sf::Sound sound;
			sound.setBuffer(buffer);

			sf::Music music;
			music.openFromFile("Sound/INTRO.mp3");

			Button Play{ "PLAY",{200,100},35,sf::Color::White,sf::Color::Black };
			Play.setPosition({ 700 , 200 });
			Play.setFont(font);

			Button Option{ "OPTION",{250,100},35,sf::Color::Green,sf::Color::Black };
			Option.setPosition({ 675 , 350 });
			Option.setFont(font);

			Button Exit{ "EXIT",{200,100},35,sf::Color::Green,sf::Color::Black };
			Exit.setPosition({ 700 , 500 });
			Exit.setFont(font);
            
            int n = 0;
            
            std::ifstream ifs("txtFile/Data.txt", std::ios::in);
            ifs.seekg(0, ios::beg);
            string temp;
            while (ifs >> temp) n++;
            ifs.close();
            n /= 3;
            n--;
			while (app.isOpen()) {
				sf::Event event;
				while (app.pollEvent(event)) {

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						sound.play();
						if (Play.button.getFillColor() == sf::Color::White) {
							music.stop();
							GenInGameScreen(app);
						}
						if (Option.button.getFillColor() == sf::Color::White) {
                            highscore();
						}
						if (Exit.button.getFillColor() == sf::Color::White) {
                            std::ofstream ofs("txtFile/score.txt", std::ios::out | std::ios::app);
                            ofs << n << '\n' << 0 << '\n';
                            ofs.close();
							app.close();
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
						sound.play();
						if (Play.button.getFillColor() == sf::Color::White) {
							Play.setBackgroundColor(sf::Color::Green);
							Option.setBackgroundColor(sf::Color::White);
							//break;
						}
						if (Option.button.getFillColor() == sf::Color::White) {
							Option.setBackgroundColor(sf::Color::Green);
							Exit.setBackgroundColor(sf::Color::White);
							//break;
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						sound.play();
						if (Option.button.getFillColor() == sf::Color::White) {
							Option.setBackgroundColor(sf::Color::Green);
							Play.setBackgroundColor(sf::Color::White);
							sf::sleep(sf::seconds(1));
							break;
						}
						if (Exit.button.getFillColor() == sf::Color::White) {
							Exit.setBackgroundColor(sf::Color::Green);
							Option.setBackgroundColor(sf::Color::White);
							sf::sleep(sf::seconds(1));
							break;
						}
					}

					app.clear();
					app.draw(s);
					app.draw(text);
					Play.drawto(app);
					Option.drawto(app);
					Exit.drawto(app);
					music.play();
					app.display();
				}
			}
			return;
}

void GenWinScreen()
{
	sf::RenderWindow winscreen(sf::VideoMode(1024, 576), "WinScreen");
	sf::Font font;
	font.loadFromFile("sound/IMMORTAL.ttf");

	sf::Text text;
	text.setFont(font);
	text.setString("YOU WIN");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(70);
	text.setPosition({ 300,200 });

	sf::Text text1;
	text1.setFont(font);
	text1.setString("Press any button to exit");
	text1.setFillColor(sf::Color::White);
	text1.setCharacterSize(30);
	text1.setPosition({ 320,400 });
	while (winscreen.isOpen())
	{
		sf::Event event;
		while (winscreen.pollEvent(event)) 
		{
			if (event.type == sf::Event::KeyPressed)
			{
				winscreen.close();
				GenMainMenu();
			}
			winscreen.clear();
			winscreen.draw(text);
			winscreen.draw(text1);
			winscreen.display();
		}
	}
}
