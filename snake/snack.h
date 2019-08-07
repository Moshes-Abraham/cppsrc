#ifndef SNAKE_H
#define SNAKE_H

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <list>
#include <utility>
#include <signal.h>
#include "main.h"
#include "timer.h"
#include "food.h"
using namespace std;

class Snake :public Game, boost::noncopyable
{
	public:
		Snake(int, int);
		~Snake();
		void insertSnake(int, int);
		void shrinkSnake();
		void moveSnake();
		void gameOver(int);
		void gameStart();
		void initGame();
		void keyControl();
	private:
		void initSnake();
		int x_pos;
		int y_pos;
		int length; //pairList's size
		int x_dir;
		int y_dir;
		int ttm;
		int ttg;
		bool moved;
		bool ate;
		typedef list<pair<int,int> > pairList;
		pairList* snakeNode;
		Timer* timer;
		Food* food;
};
#endif
