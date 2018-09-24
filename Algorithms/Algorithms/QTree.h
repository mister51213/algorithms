#pragma once

struct Point {
	int x, y;

	Point(int x, int y) {
		x = x;
		y = y;
	}
};

class QNode {
public:
	QNode() :
		pChildTL(nullptr),
		pChildTR(nullptr),
		pChildBL(nullptr),
		pChildBR(nullptr)
	{}

	int Search() {

	}

	Point topLeft;
	Point bottomRight;
	Point center;
	QNode* pChildTL;
	QNode* pChildTR;
	QNode* pChildBL;
	QNode* pChildBR;
};

