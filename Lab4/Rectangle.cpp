#include "Rectangle.h"

MyRectangle::MyRectangle(int width, int height, Point p, Color color)
{
	InitialColor = color;
	CurrentColor = color;
	InitialHeight = height;
	InitialWidth = width;
	Height = height;
	Width = width;
	CurrentBasePoint = p;
	InitialBasePoint = p;
}
Figure^ MyRectangle::GetCopy()
{
	MyRectangle^ f = gcnew MyRectangle(Width, Height, CurrentBasePoint, CurrentColor);
	return f;
}

int MyRectangle::MaxX()
{
	return CurrentBasePoint.X + Width;
}
int MyRectangle::MaxY()
{
	return CurrentBasePoint.Y + Height;
}
int MyRectangle::MinX()
{
	return CurrentBasePoint.X;
}
int MyRectangle::MinY()
{
	return CurrentBasePoint.Y;
}

void MyRectangle::Draw(System::Drawing::Graphics^ g)
{
	Size^ size = gcnew Size(Width, Height);
	g->FillRectangle(gcnew SolidBrush(CurrentColor), CurrentBasePoint.X, CurrentBasePoint.Y, Width, Height);
	g->DrawRectangle(gcnew Pen(System::Drawing::Color::Black), CurrentBasePoint.X, CurrentBasePoint.Y, Width, Height);

}
void MyRectangle::Move(int dx, int dy)
{
	CurrentBasePoint.X += dx;
	CurrentBasePoint.Y += dy;
}
void MyRectangle::Restore()
{
	CurrentBasePoint = InitialBasePoint;
	Width = InitialWidth;
	Height = InitialHeight;
	CurrentColor = InitialColor;
}
void MyRectangle::Deformation(float coefficient)
{
	Width = Width * coefficient;
	Height = Height * coefficient;
}

int MyRectangle::GetWidth()
{
	return Width;
}
int MyRectangle::GetHeight()
{
	return Height;
}

void MyRectangle::setWidth(int W)
{
	Width = W;
}
void MyRectangle::setHeight(int H)
{
	Height = H;
}

String^ MyRectangle::GetShapeName()
{
	return "Rectangle";
}