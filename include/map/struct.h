/**
 * \brief 一些用到的结构
 * \author EiEddie
 */

#ifndef EMLIFE_INCLUDE_MAP_STRUCT_H_
#define EMLIFE_INCLUDE_MAP_STRUCT_H_

#include <algorithm>

struct Point {
	int x = 0;
	int y = 0;
	
	Point(int x=0, int y=0): //NOLINT
	x(x), y(y) {}
	
	bool operator==(const Point& pnt) const {
		if(x == pnt.x && y == pnt.y)
			return true;
		else
			return false;
	}
	
	bool operator!=(const Point& pnt) const {
		return !(*this == pnt);
	}
};


template<typename PointType>
struct Grid {
protected:
	int width, height;
	
	PointType* grid = new PointType[width * height];
	
public:
	explicit Grid(int w, int h, PointType default_pnt):
	width(w), height(h) {
		std::fill(grid, grid + width*height, default_pnt);
	}
	
	~Grid() {
		delete[] grid;
	}
	
	/**
	 * \brief 点是否在网格区域内
	 */
	inline bool in(const Point& pnt) const {
		return (pnt.x >= 0 && pnt.x < width)
		&& (pnt.y >= 0 && pnt.y < height);
	}
	
	/**
	 * \param kind 点的种类
	 * \return 是否成功设置
	 * \retval -1 失败: 点不在网格内
	 */
	inline int set_point_kind(const Point& pnt, PointType kind) {
		if(in(pnt)) {
			grid[pnt.y*width + pnt.x] = kind;
			return 0;
		} else {
			return -1;
		}
	}
	
	/**
	 * \brief 获取点的种类
	 *
	 * !! WARNING: 传入不在网格范围内的点将导致不可预料的行为
	 */
	inline PointType get_point_kind(const Point& pnt) const {
		if(in(pnt))
			return grid[pnt.y*width + pnt.x];
		else
			return grid[0];
	}
	
	inline int get_width() const {
		return width;
	}
	
	inline int get_height() const {
		return height;
	}
};

#endif //EMLIFE_INCLUDE_MAP_STRUCT_H_
