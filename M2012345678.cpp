#include "Common.h"
#include "Point.h"
#include "M2012345678.h"

int visit[BOARD_SIZE][BOARD_SIZE];

M2012345678::M2012345678()
{

}

Point M2012345678::input()
{
	//랜덤위치를 확인하기 위해
	//p를 설정하여 반환
	int temp = -1;
	int tempx = -1;
	int tempy = -1;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (temp < visit[i][j]) {
				temp = visit[i][j];
				tempx = i;
				tempy = j;
			}
		}
	}
	visit[tempx][tempy] = -1;
	return Point(tempx, tempy);
}

void M2012345678::checkMineInfo(Point p)
{
	visit[p.getX()][p.getY()] = -1;
}
void M2012345678::checkBoardInfo(Point p, int value)
{

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int x = p.getX() + i;
			int y = p.getY() + j;
			if (check(p, x, y)) continue;
			visit[x][y] += value;
		}
	}
}

bool M2012345678::check(Point p, int x, int y) {
	if (p.getX() == x && p.getY() == y) return true;
	if (visit[x][y] == -1) return true;
	if (x<0 || x>BOARD_SIZE - 1) return true;
	if (y<0 || y>BOARD_SIZE - 1) return true;
	return false;
}