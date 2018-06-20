#include "Paddle.h"
#include "Graphics.h"

Paddle::Paddle(Location loc, char KeyUp, char KeyDown)
{
	this->loc = loc;
	this->KeyUp = KeyUp;
	this->KeyDown = KeyDown;
}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRectDim(loc.x, loc.y, width, height, c);
}

bool Paddle::IsColliding(const Ball & ball) const
{
	return loc.x <= ball.GetX() + ball.size &&
		loc.x + width >= ball.GetX() &&
		loc.y <= ball.GetY() + ball.size &&
		loc.y + height >= ball.GetY();
}

void Paddle::Move(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(KeyUp) && loc.y > 20 + move_Speed)
		loc.y -= move_Speed;
	if (kbd.KeyIsPressed(KeyDown) && loc.y < Graphics::ScreenHeight - height - move_Speed - 20)
		loc.y += move_Speed;
}

int Paddle::GetWidth() const
{
	return width;
}