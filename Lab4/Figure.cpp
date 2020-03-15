#include "Figure.h"

void Figure::SetColor(Color c)
{
	CurrentColor = c;
}
Color Figure::GetColor()
{
	return CurrentColor;
}

String^ Figure::GetName()
{
	return Name;
}
void Figure::SetName(String^ name)
{
	Name = name;
}
String^ Figure::GetShapeName()
{
	return "Figure";
}