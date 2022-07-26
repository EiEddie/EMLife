/**
 * \brief 迷宫的生成与管理
 * \author EiEddie
 */

#ifndef EMLIFE_INCLUDE_CORE_MAP_MAZE_H_
#define EMLIFE_INCLUDE_CORE_MAP_MAZE_H_

#include "struct.h"

enum Block {
	UNDEFINED = -1,
	ROAD      =  0,
	WALL      =  1
};


typedef Grid<Block> Maze;

#endif //EMLIFE_INCLUDE_CORE_MAP_MAZE_H_
