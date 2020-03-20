#include "Ellipse.h"

MyEllipse::MyEllipse(int width, int height, Point p, Color color)
{
	start_color = color;
	current_color = color;
	InitialHeight = height;
	InitialWidth = width;
	Height = height;
	Width = width;
	current_position = p;
	start_point = p;
}
Figure^ MyEllipse::CopyFigure()
{
	MyEllipse^ f = gcnew MyEllipse(Width, Height, current_position, current_color);
	return f;
}

int MyEllipse::MaxX()
{
	return current_position.X + Width;
}
int MyEllipse::MaxY()
{
	return current_position.Y + Height;
}
int MyEllipse::MinX()
{
	return current_position.X;
}
int MyEllipse::MinY()
{
	return current_position.Y;
}

void MyEllipse::Draw(System::Drawing::Graphics^ g)
{
	g->FillEllipse(gcnew SolidBrush(current_color), current_position.X, current_position.Y, Width, Height);
	g->DrawEllipse(gcnew Pen(System::Drawing::Color::Black), current_position.X, current_position.Y, Width, Height);
}
void MyEllipse::Move(int dx, int dy)
{
	current_position.X += dx;
	current_position.Y += dy;
}
void MyEllipse::Restore()
{
	current_position = start_point;
	Width = InitialWidth;
	Height = InitialHeight;
	current_color = start_color;
}
void MyEllipse::ChangeSize(float coefficient)
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