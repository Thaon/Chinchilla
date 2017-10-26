#include "Game.h"

int main(int argc, char** argv)
{
	Game game("Game Test", 800, 600);
	game.Init();

	game.Run();

	return 0;
}