#ifndef FOOD_H
#define FOOD_H

class Food
{
	public:
		static Food* getInstance();
		void dispFood()const;
		int getXPos()const;
		int getYPos()const;
		void setXPos(int)const;
		void setYPos(int)const;

	protected:
		Food(int, int);

	private:
		static Food* _instance;
		mutable int fx_pos;
		mutable int fy_pos;
};



#endif
