#include "Ellipse.h"

MyEllipse::MyEllipse(int width, int height, Point p, Color color)
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
Figure^ MyEllipse::GetCopy()
{
	MyEllipse^ f = gcnew MyEllipse(Width, Height, CurrentBasePoint, CurrentColor);
	return f;
}

int MyEllipse::MaxX()
{
	return CurrentBasePoint.X + Width;
}
int MyEllipse::MaxY()
{
	return CurrentBasePoint.Y + Height;
}
int MyEllipse::MinX()
{
	return CurrentBasePoint.X;
}
int MyEllipse::MinY()
{
	return CurrentBasePoint.Y;
}

void MyEllipse::Draw(System::Drawing::Graphics^ g)
{
	g->FillEllipse(gcnew SolidBrush(CurrentColor), CurrentBasePoint.X, CurrentBasePoint.Y, Width, Height);
	g->DrawEllipse(gcnew Pen(System::Drawing::Color::Black), CurrentBasePoint.X, CurrentBasePoint.Y, Width, Height);

}
void MyEllipse::Move(int dx, int dy)
{
	CurrentBasePoint.X += dx;
	CurrentBasePoint.Y += dy;
}
void MyEllipse::Restore()
{
	CurrentBasePoint = InitialBasePoint;
	Width = InitialWidth;
	Height = InitialHeight;
	CurrentColor = InitialColor;
}
void MyEllipse::Deformation(float coefficient)
{
	Width = Width * coefficient;
	Height = Height * coefficient;
}

int MyEllipse::GetWidth()
{
	return Width;
}
int MyEllipse::GetHeight()
{
	return Height;
}

void MyEllipse::setWidth(int W)
{
	Width = W;
}
void MyEllipse::setHeight(int H)
{
	Height = H;
}

String^ MyEllipse::GetShapeName()
{
	return "Ellipse";
}