/**
 * \brief 迷宫的生成与管理
 * \author EiEddie
 */

#ifndef EMLIFE_INCLUDE_MAP_MAZE_H_
#define EMLIFE_INCLUDE_MAP_MAZE_H_

#include "struct.h"

#include <stack>

enum Block {
	UNDEFINED = -1,
	ROAD      =  0,
	WALL      =  1
};


/**
 * \brief 方向
 * 按坐标方式排列: 先横再纵, 先右再左, 先下再上
 */
enum Dir {
	RIGHT = 0,
	LEFT  = 1,
	DOWN  = 2,
	UP    = 3
};


typedef Grid<Block> Maze;


const static class MazeGenerator {
private:
	Dir dirs_list[24][4]{};
	
	/**
	 * \brief 用四个方向的全排列填充 dirs_list
	 */
	inline void set_dirs_list() {
		Dir dirs[4] = {RIGHT, LEFT, DOWN, UP};
		int i = 0;
		do {
			std::copy(dirs, dirs + 4, dirs_list[i++]);
		} while(std::next_permutation(dirs, dirs + 4));
	}
	
	static inline void move(Point& pnt, Dir dir, int step=1) {
		Point dirs[4] = {
			{ 1,  0}, // RIGHT
			{-1,  0}, // LEFT
			{ 0,  1}, // DOWN
			{ 0, -1}  // UP
		};
		
		pnt.x += dirs[dir].x * step;
		pnt.y += dirs[dir].y * step;
	}

public:
	explicit MazeGenerator() {
		set_dirs_list();
	}
	
	int generate_maze(Maze& maze) const;
} maze_generator;

#endif //EMLIFE_INCLUDE_MAP_MAZE_H_
