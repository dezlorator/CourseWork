#include "Rectangle.h"

MyRectangle::MyRectangle(int width, int height, Point p, Color color)
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
Figure^ MyRectangle::CopyFigure()
{
	MyRectangle^ f = gcnew MyRectangle(Width, Height, current_position, current_color);
	return f;
}

int MyRectangle::MaxX()
{
	return current_position.X + Width;
}
int MyRectangle::MaxY()
{
	return current_position.Y + Height;
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
	Size^ size = gcnew Size(Width, Height);
	g->FillRectangle(gcnew SolidBrush(current_color), current_position.X, current_position.Y, Width, Height);
	g->DrawRectangle(gcnew Pen(System::Drawing::Color::Black), current_position.X, current_position.Y, Width, Height);

}
void MyRectangle::Move(int dx, int dy)
{
	current_position.X += dx;
	current_position.Y += dy;
}
void MyRectangle::Restore()
{
	current_position = start_point;
	Width = InitialWidth;
	Height = InitialHeight;
	current_color = start_color;
}
void MyRectangle::ChangeSize(float coefficient)
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