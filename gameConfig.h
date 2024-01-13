#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H

class GameConfig
{
public:
	enum class eKeys { LEFT = 'a', RIGHT = 's', UP = 'w', DOWN = 'z', ESC = 27 };
	static constexpr int GAME_WIDTH = 12;
	static constexpr int GAME_HEIGHT = 18;

	static constexpr int MIN_X = 30;
	static constexpr int MIN_Y = 6;

	static const int COLORS[];
	static const int NUM_OF_COLORS;
};
#endif