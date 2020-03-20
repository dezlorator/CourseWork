#include "Figure.h"

void Figure::SetColor(Color c)
{
	current_color = c;
}
Color Figure::GetColor()
{
	return current_color;
}

String^ Figure::GetName()
{
	return name;
}
void Figure::SetName(String^ name)
{
	name = name;
}
String^ Figure::GetShapeName()
{
	return "Figure";
}