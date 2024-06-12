#include <raylib.h>
#include <iostream>
#include <random>
#include <vector>
#include "box.h"
#include "shape.h"
using namespace std;
// class falling_shape
// {
// public:
// 	position pos;
// 	int shape_type;
// 	falling_shape() : position(pos{0, 0}), shape_type(0) {}
// 	falling_shape(box &canvas) : position(pos{rand() % canvas.n_x, canvas.n_y - 1}), shape_type(rand() % n_shapes) {}

// 	void change_pos(pos change)
// 	{
// 		position = position + change;
// 	}

// 	void draw(box &canvas)
// 	{
// 		shape_types[shape_type].draw(position, canvas);
// 	}

// 	void new_falling(box &canvas)
// 	{
// 		position = pos{rand() % canvas.n_x, canvas.n_y - 1};
// 		shape_type = rand() % n_shapes;
// 	}
// };

int main()
{
	// box canvas;
	// falling_shape current_falling;
	// bool is_falling;

	int screenheight = 800;
	int screenwidth = 600;
	InitWindow(screenwidth, screenheight, "My window");
	SetTargetFPS(10);
	box canvas(screenwidth, screenheight);

	// // is_falling = false;
	// // current_falling = falling_shape(canvas);
	// // canvas.draw();
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_RIGHT))
			canvas.move_right();

		if (IsKeyPressed(KEY_LEFT))
			canvas.move_left();

		if (IsKeyPressed(KEY_SPACE))
			canvas.rotate();

		// if (KEY_DOWN(_SPACE))
		// {
		// 	box.rotate();
		// }
		// if (is_falling)
		// {
		// 	current_falling.change_pos(pos{0, -1});
		// }
		// else
		// {
		// 	current_falling.new_falling(canvas);
		// 	is_falling = true;
		// }

		BeginDrawing();
		ClearBackground(BLACK);

		canvas.draw();
		// current_falling.draw(canvas);
		// std::cout << ("loop running");

		canvas.fall();
		canvas.draw_falling();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
