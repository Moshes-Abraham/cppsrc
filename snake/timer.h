#ifndef TIMER_H
#define TIMER_H

class Timer
{
	public:
		static void wrapUp();
		static int set_ticker(int n_msecs);
		static Timer* getInstance();
		Timer();
	private:
		static Timer* _instance;
};
#endif
