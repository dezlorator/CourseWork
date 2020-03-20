#include "Ellipse.h"

MyEllipse::MyEllipse(int width, int height, Point p, Color color)
{
	start_color = color;
	current_color = color;
	start_height = height;
	start_width = width;
	height = height;
	width = width;
	current_position = p;
	start_point = p;
}
Figure^ MyEllipse::CopyFigure()
{
	MyEllipse^ f = gcnew MyEllipse(width, height, current_position, current_color);
	return f;
}

int MyEllipse::MaxX()
{
	return current_position.X + width;
}
int MyEllipse::MaxY()
{
	return current_position.Y + height;
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
	g->FillEllipse(gcnew SolidBrush(current_color), current_position.X, current_position.Y, width, height);
	g->DrawEllipse(gcnew Pen(System::Drawing::Color::Black), current_position.X, current_position.Y, width, height);
}
void MyEllipse::Move(int dx, int dy)
{
	current_position.X += dx;
	current_position.Y += dy;
}
void MyEllipse::Restore()
{
	current_position = start_point;
	width = start_width;
	height = start_height;
	current_color = start_color;
}
void MyEllipse::ChangeSize(float coefficient)
{
	width = width * coefficient;
	height = height * coefficient;
}

int MyEllipse::GetWidth()
{
	return width;
}
int MyEllipse::GetHeight()
{
	return height;
}

void MyEllipse::setWidth(int W)
{
	width = W;
}
void MyEllipse::setHeight(int H)
{
	height = H;
}

String^ MyEllipse::GetShapeName()
{
	return "Ellipse";
}