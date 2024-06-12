// #include "box.h"

#ifndef SHAPE_H
#define SHAPE_H
#include "raylib.h"
#include "position.h"
#include "vector"
#include "map"

class box;

class shape
{
public:
	int color_id, rotation, n_states;
	position pos;
	Color color;
	std::map<int, std::vector<position>> cells;

	shape();
	void rotate(box canvas, position pos);
	bool check(box canvas);
	void draw_block(box canvas, position pos, Color color);
	void fall();
	// void collision();
	// bool collision(box canvas);
	void draw(box canvas);
	void rotate();
};

#endif