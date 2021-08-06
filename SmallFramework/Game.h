#pragma once
#include "GameState.h"
class Game : public GameState
{
	virtual void Init() override;
	virtual void Draw() override;
	virtual bool Input(std::map<int, bool> keys) override;
	virtual bool MouseInput(int x, int y, bool leftbutton) override;
	virtual void Update(unsigned int delta) override;
	virtual void Close() override;
};

