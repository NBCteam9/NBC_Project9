#pragma once
#include "Character.h"
#include <Windows.h>

class StoryPrinter
{
public:
	void PrintIntro(Character* character) const;
	void PrintVictory(Character* character) const;
	void PrintLose() const;
};
