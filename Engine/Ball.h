#pragma once
#include "Graphics.h"
#include "Location.h"

class Ball
{
	//Master Test
public:
	Ball(Location loc);
	void Draw(Graphics& gfx) const;
	void Respawn(Location loc);
	int GetX() const;
	int GetY() const;
	int GetSize() const;
	void Move(const Location& delta_loc);
	static constexpr int size = 30;

private:
	static constexpr Color c = Colors::Gray;
	Location loc;
};