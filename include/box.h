
#ifndef BOX_H
#define BOX_H
#include "position.h"
#include "shape.h"
#include "vector"
using namespace std;
class box
{
public:
	position origin;
	int block_w, block_h, n_x, n_y, l_x, l_y;
	int screenwidth, screenheight, padding = 50;
	shape falling_shape;
	int arr[10][20];
	// vector<shape> arr;
	Color colors[15];
	shape shapes[7];
	box();
	~box();
	box(int screenwidth, int screenheight);

	void move_left();
	void move_right();

	void spawn_falling();

	void draw_block(position origin, position pos, Color color);
	void draw();
	void draw_falling();
	void add_to_arr();
	bool collision_vertical();
	void collision_horizontal();
	void fall();
	void rotate();
};
#endif