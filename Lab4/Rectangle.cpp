#include "Rectangle.h"

MyRectangle::MyRectangle(int width, int height, Point p, Color color)
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
Figure^ MyRectangle::CopyFigure()
{
	MyRectangle^ f = gcnew MyRectangle(width, height, current_position, current_color);
	return f;
}

int MyRectangle::MaxX()
{
	return current_position.X + width;
}
int MyRectangle::MaxY()
{
	return current_position.Y + height;
}
int MyRectangle::MinX()
{
	return current_position.X;
}
int MyRectangle::MinY()
{
	return current_position.Y;
}

void MyRectangle::Draw(System::Drawing::Graphics^ g)
{
	Size^ size = gcnew Size(width, height);
	g->FillRectangle(gcnew SolidBrush(current_color), current_position.X, current_position.Y, width, height);
	g->DrawRectangle(gcnew Pen(System::Drawing::Color::Black), current_position.X, current_position.Y, width, height);

}
void MyRectangle::Move(int dx, int dy)
{
	current_position.X += dx;
	current_position.Y += dy;
}
void MyRectangle::Restore()
{
	current_position = start_point;
	width = start_width;
	height = start_height;
	current_color = start_color;
}
void MyRectangle::ChangeSize(float coefficient)
{
	width = width * coefficient;
	height = height * coefficient;
}

int MyRectangle::GetWidth()
{
	return width;
}
int MyRectangle::GetHeight()
{
	return height;
}

void MyRectangle::setWidth(int W)
{
	width = W;
}
void MyRectangle::setHeight(int H)
{
	height = H;
}

String^ MyRectangle::GetShapeName()
{
	return "Rectangle";
}