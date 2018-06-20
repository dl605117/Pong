#pragma once
#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(Location loc, char KeyUp, char KeyDown);
	void Draw(Graphics& gfx) const;
	bool IsColliding(const Ball& ball) const;
	void Move(const Keyboard& kbd);
	int GetWidth() const;

private:
	static constexpr Color c = Colors::Gray;
	static constexpr int move_Speed = 3;
	static constexpr int width = 30;
	static constexpr int height = 200;
	char KeyUp;
	char KeyDown;
	Location loc;
};