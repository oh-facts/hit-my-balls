
#include <BSE.hpp>
#include <Player.hpp>
#include <Football.hpp>
#include <Spawner.hpp>

int main()
{

	BSE::innit(800, 600, "Hit my balls");

	Scene scene1;

	Player player1(sf::Color::Red);
	Player player2(sf::Color::White);

	Football football;

	Spawner sp(&player1, &player2, &football);

	scene1.addGameObject(&player1);
	scene1.addGameObject(&player2);
	scene1.addGameObject(&football);

	scene1.addSystem(&sp);

	BSE::setScene(&scene1);


	BSE::run();

	return 0;
}

// have problems? Fix it! This is open source :D
