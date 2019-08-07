#ifndef GAME_H
#define GAME_H

class Game
{
	public:
		virtual void gameStart() = 0;
		virtual void gameOver(int) = 0;
		virtual void initGame() = 0;
		virtual void keyControl() = 0;
};
#endif
