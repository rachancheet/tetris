#ifndef POSITION_H
#define POSITION_H
class position
{
public:
	int x, y;
	position(){};
	position(int x, int y) : x(x), y(y){};
	position operator+(const position &other) const
	{
		return position{x + other.x, y + other.y};
	}
};
#endif