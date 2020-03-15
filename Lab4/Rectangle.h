#include "Figure.h"

ref class MyRectangle : public Figure
{
private:
	int Width, InitialWidth;
	int Height, InitialHeight;
public:
	MyRectangle(int width, int height, Point p, Color c);
	Figure^ GetCopy() override;

	int MaxX() override;
	int MaxY() override;
	int MinX() override;
	int MinY() override;
	int GetWidth() override;
	int GetHeight() override;
	void Draw(System::Drawing::Graphics^ g) override;
	void Move(int dx, int dy) override;
	void Restore() override;
	void Deformation(float coefficient) override;
	String^ GetShapeName() override;

	void setWidth(int W);
	void setHeight(int H);
};

