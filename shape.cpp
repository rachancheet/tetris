#include "shape.h"
#include "position.h"
#include "box.h"
#include "iostream"
#include "random"
using namespace std;

shape::shape() : rotation(1), pos(position{5, 15}){

								  //  cout << "running shape constructor";
							  };

void shape::fall()
{
	pos = pos + position{0, -1};
}

bool shape::check(box canvas)
{
	return true;
}
void shape::rotate()
{
	rotation = (rotation + 1) % n_states;
}

void shape::draw_block(box canvas, position pos, Color color)
{

	position origin = canvas.origin;
	// cout << "drawing :" << origin.x + canvas.block_w * pos.x + canvas.block_w * 1 / 2 << " ; " << origin.y + canvas.block_h * pos.y + canvas.block_h * 1 / 2 << " ; " << canvas.block_w << " ; " << canvas.block_h << " ; ";

	DrawRectangle(origin.x + canvas.block_w * pos.x, origin.y - canvas.block_h * (pos.y + 1) + 1, canvas.block_w - 1, canvas.block_h - 1, color);
}
void shape::draw(box canvas)
{
	for (position i : cells[rotation])
	{
		draw_block(canvas, i + pos, color);
	}
}

// void shape::draw(box canvas)
// {
// 	switch (shape_type)
// 	{
// 	case 1: // straight
// 		if (rotation)
// 		{

// 			draw_block(canvas, pos, color);
// 			draw_block(canvas, pos + position{0, 1}, color);
// 			draw_block(canvas, pos + position{0, 2}, color);
// 			draw_block(canvas, pos + position{0, 3}, color);
// 		}
// 		else
// 		{

// 			draw_block(canvas, pos, color);
// 			draw_block(canvas, pos + position{1, 0}, color);
// 			draw_block(canvas, pos + position{2, 0}, color);
// 			draw_block(canvas, pos + position{3, 0}, color);
// 		}
// 	}

// for (int i = 0; i < size; ++i)
// {
// 	if (arr[i])
// 	{
// 		// int x = position.x + i % 2; // Assuming a 2x2 shape for simplicity
// 		// int y = position.y + i / 2;
// 		// DrawRectangle(x * canvas.block_w, (canvas.n_y - y - 1) * canvas.block_h, canvas.block_w, canvas.block_h, RED);
// 	}
// }
// }