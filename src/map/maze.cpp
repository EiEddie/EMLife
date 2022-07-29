#include <map/maze.h>

int MazeGenerator::generate_maze(Maze &maze) const {
	// 初始化迷宫, 将迷宫每个点设置为0且加入起点, 起点恒为(1, 1)
	Maze* maze_temp = new Maze(maze.get_width(), maze.get_height(), UNDEFINED);
	
	std::stack<Point> walls;
	walls.push({1, 1});
	
	while(!walls.empty()) {
		// 在 walls 中选取一点并删除
		Point road_pnt = walls.top();
		walls.pop();
		maze.set_point_kind(road_pnt, ROAD);
		
		// 将 road_point 与其四周随机一个路点打通
		const Dir* dirs = dirs_list[rand()%24]; //NOLINT
		for(int i=0; i<4; i++) {
			Point road_pnt_temp = road_pnt;
			move(road_pnt_temp, dirs[i], 2);
			
			if(maze_temp->get_point_kind(road_pnt_temp) == ROAD) {
				maze.set_point_kind(
					{(road_pnt.x + road_pnt_temp.x)/2,
						(road_pnt.y + road_pnt_temp.y)/2},
					ROAD
				);
				maze_temp->set_point_kind(
					{(road_pnt.x + road_pnt_temp.x)/2,
					(road_pnt.y + road_pnt_temp.y)/2},
					ROAD
				);
				break;
			}
		}
		
		// 将 road_point 设置为路
		maze_temp->set_point_kind(road_pnt, ROAD);
		
		// 加入 road_point 周围不在 walls 中的墙点
		for(int i=0; i<4; i++) {
			Point road_coord_temp = road_pnt;
			move(road_coord_temp, dirs[i], 2);
			
			if(maze_temp->in(road_coord_temp)
			&& maze_temp->get_point_kind(road_coord_temp) == UNDEFINED) {
				maze_temp->set_point_kind(road_coord_temp, WALL);
				walls.push(road_coord_temp);
			}
		}
	}
	
	delete maze_temp;
	return 0;
}