#include"Graphic.h"

void Star::Init() {
	if (_x == 0) {
		_x = rand() % WIDTH;
	}
	else
		_x = 0;

	_y = rand() % HEIGHT;
	_step = (rand() % 5000) / 1000.0 + 1;
	_color = (int)(_step * 255 / 6.0 + 0.5);
}

void Star::Init(StarType* pStarType) {
	this->Init();
	_pStarType = pStarType;
}

void Star::Move() {
	_pStarType->Remove(_x, _y);
	NewPos();
	_pStarType->Draw(_x, _y, _color);
}

void Star::NewPos() {
	_x += _step;
	if (_x > WIDTH) Init();
}

//
//void main() {
//	srand(time(NULL));
//	initgraph(WIDTH, HEIGHT);
//	Star star[MAXSTAR];
//
//	PointSatr pointStar;
//	RectStar rectStar;
//	XStar xStar;
//
//	for (int i = MAXSTAR - 1; i >= 0; i--) {
//		int c = rand() % 3;
//		switch (c)
//		{
//		case 0:
//			star[i].Init(&pointStar);
//			break;
//		case 1:
//			star[i].Init(&xStar);
//			break;
//		case 2:
//			star[i].Init(&rectStar);
//			break;
//		default:
//			break;
//		}
//	}
//	while (1) {
//		for (int i = MAXSTAR - 1; i >= 0; i--) {
//			star[i].Move();
//			Sleep(1);
//		}
//	}
//	closegraph();
//}
