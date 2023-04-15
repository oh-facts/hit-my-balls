#ifndef BSE_HPP
#define BSE_HPP

#include <SFML/Graphics.hpp>
#include <Window.hpp>
#include <Scene.hpp>
#include <Input.hpp>

class BSE
{
private:
    static Scene *currentScene;
    static Window window;

public:
    static void innit()
    {
        window.create(800, 600, "Ball Square Engine");
    }
    static void innit(int x, int y, const char *title)
    {
        window.create(x, y, title);
    }
    static void run()
    {
        sf::Clock clock;

        while (window.isOpen())
        {
            window.poll();

            sf::Time elapsed = clock.restart();

            // logic
            currentScene->update(elapsed.asSeconds());
        
            // render
            currentScene->render(window);

        }
    }
    
    static void setScene(Scene *sc)
    {
        currentScene = sc;
    }

    static void setTitle()
    {
    }

    BSE(/* args */){};
    ~BSE()
    {

    };
};
Scene *BSE::currentScene = nullptr;
Window BSE::window;
#endif
