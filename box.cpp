
#include "box.h"
#include "iostream"
#include "position.h"
#include "shapes.cpp"
using namespace std;
box::box(){};
box::box(int screenwidth, int screenheight) : colors{BLACK, ORANGE, PINK, BLUE, YELLOW, RED, PURPLE, GREEN, PINK, LIME, BROWN, DARKGRAY, LIGHTGRAY, MAGENTA, MAROON}, shapes{Ishape(), Jshape(), Lshape(), Oshape(), Sshape(), Tshape(), Zshape()}
{
	screenheight = screenheight;
	screenwidth = screenwidth;
	l_x = screenwidth - 2 * padding;
	l_y = screenheight - 2 * padding;
	n_x = 10;
	n_y = 20;
	block_w = l_x / n_x;
	block_h = l_y / n_y;
	origin = position{padding, screenheight - padding};

	for (int i = 0; i < n_x; i++)
		for (int j = 0; j < n_y; j++)
			arr[i][j] = 0;
	spawn_falling();
}

box::~box()
{
}
void box::spawn_falling()
{

	// std::cout << "spawning falling_shape ";
	falling_shape = shapes[rand() % 7];

	// std::cout << "spawning falling_shape ";
	// falling_shape = shape{
	// 	1,
	// 	// rand() % n_shapes,
	// 	position{rand() % n_x, n_y},
	// 	0,
	// 	colors[rand() % 13]};
}
void box::draw_block(position origin, position pos, Color color)
{
	DrawRectangle(origin.x + block_w * pos.x, origin.y - block_h * (pos.y + 1) + 1, block_w - 1, block_h - 1, color);
}

void box::draw()
{
	Color linecolor = RED;
	Color gridcolor = RED;
	Color boxcolor = BLACK;
	DrawRectangle(origin.x, origin.y - l_y, l_x, l_y, linecolor);
	DrawLine(origin.x, origin.y, origin.x + l_x, origin.y, linecolor);
	DrawLine(origin.x, origin.y, origin.x, origin.y - l_y, linecolor);
	DrawLine(origin.x + l_x, origin.y, origin.x + l_x, origin.y - l_y, linecolor);
	DrawLine(origin.x, origin.y - l_y, origin.x + l_x, origin.y - l_y, linecolor);
	// cout << origin.x << "; " << origin.y << "; " << origin.x + l_x << "; " << origin.y + l_y;
	// cout << "drawing grids";
	for (int i = 0; i < n_x; i++)
		for (int j = 0; j < n_y; j++)
			// cout << arr[i][j];
			draw_block(origin, position{i, j}, colors[arr[i][j]]);
	// cout << "drawing grids";
	// DrawRectangle(origin.x + block_w * i	, origin.y - block_h * (j + 1) + 1, block_w - 1, block_h - 1, boxcolor);

	// for (auto i : arr)
	// {
	// 	// draw_block()
	// 	i.draw(*this);
	// }
}
void box ::draw_falling()
{

	// cout << "trying to draw fall";
	falling_shape.draw(*this);
};

void box::collision_horizontal()
{

	for (position i : falling_shape.cells[falling_shape.rotation])
	{
		int x = falling_shape.pos.x + i.x;
		int y = falling_shape.pos.y + i.y;
		if (0 > x)
		{
			falling_shape.pos.x = falling_shape.pos.x + 1;
		}
		else if (x > n_x)
		{
			falling_shape.pos.x = falling_shape.pos.x - 1;
		}
	}
}
bool box::collision_vertical()
{
	for (position i : falling_shape.cells[falling_shape.rotation])
	{
		int x = falling_shape.pos.x + i.x;
		int y = falling_shape.pos.y + i.y;
		if (arr[x][y] || 0 > y || y > n_y)
		{
			return true;
		}
	}
	return false;
}
void box::fall()
{
	falling_shape.fall();
	if (collision_vertical())
	{

		falling_shape.pos = falling_shape.pos + position{0, 1};
		add_to_arr();
		spawn_falling();
	}
};
void box::add_to_arr()
{
	for (position i : falling_shape.cells[falling_shape.rotation])
	{

		arr[i.x + falling_shape.pos.x][i.y + falling_shape.pos.y] = falling_shape.color_id;
	}
}
void box::rotate()
{
	falling_shape.rotate();
}
void box::move_left()
{
	falling_shape.pos = falling_shape.pos + position{-1, 0};
	collision_horizontal();
}
void box::move_right()
{
	falling_shape.pos = falling_shape.pos + position{1, 0};
	collision_horizontal();
}