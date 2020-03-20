#include "Figure.h"
using namespace System;

[Serializable]
ref class MyRectangle : public Figure
{
private:
	int width, start_width;
	int height, start_height;
public:
	MyRectangle(int width, int height, Point p, Color c);
	Figure^ CopyFigure() override;

	int MaxX() override;
	int MaxY() override;
	int MinX() override;
	int MinY() override;
	int GetWidth() override;
	int GetHeight() override;
	void Draw(System::Drawing::Graphics^ g) override;
	void Move(int dx, int dy) override;
	void Restore() override;
	void ChangeSize(float value) override;
	String^ GetShapeName() override;

	void setWidth(int W);
	void setHeight(int H);
};

