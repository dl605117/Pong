#include "Ball.h"

Ball::Ball(Location loc)
{
	this->loc = loc;
}

void Ball::Draw(Graphics & gfx) const
{
	gfx.DrawRectDim(loc.x, loc.y, size, size, c);
}

void Ball::Respawn(Location in_loc)
{
	loc = in_loc;
}

int Ball::GetX() const
{
	return loc.x;
}

int Ball::GetY() const
{
	return loc.y;
}

int Ball::GetSize() const
{
	return size;
}

void Ball::Move(const Location & delta_loc)
{
	loc.x += delta_loc.x;
	loc.y += delta_loc.y;
}
