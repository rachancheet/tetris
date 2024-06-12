#include "position.h"
#include "shape.h"
class Lshape : public shape
{
public:
	Lshape()
	{
		color_id = 1;
		color = ORANGE;
		n_states = 4;
		cells[0] = {position(0, 2), position(1, 0), position(1, 1), position(1, 2)};
		cells[1] = {position(0, 1), position(1, 1), position(2, 1), position(2, 2)};
		cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 0)};
		cells[3] = {position(0, 0), position(0, 1), position(1, 1), position(2, 1)};
		// Move(0, 3);
	}
};

class Jshape : public shape
{
public:
	Jshape()
	{
		color_id = 2;
		color = PINK;
		n_states = 4;
		cells[0] = {position(0, 0), position(1, 0), position(1, 1), position(1, 2)};
		cells[1] = {position(0, 1), position(0, 2), position(1, 1), position(2, 1)};
		cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 2)};
		cells[3] = {position(0, 1), position(1, 1), position(2, 0), position(2, 1)};
		// Move(0, 3);
	}
};

class Ishape : public shape
{
public:
	Ishape()
	{
		color_id = 3;
		color = BLUE;
		n_states = 4;
		cells[0] = {position(1, 0), position(1, 1), position(1, 2), position(1, 3)};
		cells[1] = {position(0, 2), position(1, 2), position(2, 2), position(3, 2)};
		cells[2] = {position(2, 0), position(2, 1), position(2, 2), position(2, 3)};
		cells[3] = {position(0, 1), position(1, 1), position(2, 1), position(3, 1)};
		// Move(-1, 3);
	}
};

class Oshape : public shape
{
public:
	Oshape()
	{
		color_id = 4;
		color = YELLOW;
		n_states = 1;
		cells[0] = {position(0, 0), position(0, 1), position(1, 0), position(1, 1)};
		// Move(0, 4);
	}
};

class Sshape : public shape
{
public:
	Sshape()
	{
		color_id = 5;
		color = RED;
		n_states = 4;
		cells[0] = {position(0, 1), position(0, 2), position(1, 0), position(1, 1)};
		cells[1] = {position(0, 1), position(1, 1), position(1, 2), position(2, 2)};
		cells[2] = {position(1, 1), position(1, 2), position(2, 0), position(2, 1)};
		cells[3] = {position(0, 0), position(1, 0), position(1, 1), position(2, 1)};
		// Move(0, 3);
	}
};

class Tshape : public shape
{
public:
	Tshape()
	{
		color_id = 6;
		color = PURPLE;
		n_states = 4;
		cells[0] = {position(0, 1), position(1, 0), position(1, 1), position(1, 2)};
		cells[1] = {position(0, 1), position(1, 1), position(1, 2), position(2, 1)};
		cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 1)};
		cells[3] = {position(0, 1), position(1, 0), position(1, 1), position(2, 1)};
		// Move(0, 3);
	}
};

class Zshape : public shape
{
public:
	Zshape()
	{
		color_id = 7;
		color = GREEN;
		n_states = 4;
		cells[0] = {position(0, 0), position(0, 1), position(1, 1), position(1, 2)};
		cells[1] = {position(0, 2), position(1, 1), position(1, 2), position(2, 1)};
		cells[2] = {position(1, 0), position(1, 1), position(2, 1), position(2, 2)};
		cells[3] = {position(0, 1), position(1, 0), position(1, 1), position(2, 0)};
		// Move(0, 3);
	}
};
// std::vector<shape> GetAllShapes()
// {
// 	return {Ishape(), Jshape(), Lshape(), Oshape(), Sshape(), Tshape(), Zshape()};
// }