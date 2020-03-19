#include "Memento.h"
Memento::Memento(List<Figure^>^ figures, int current_figure_index, int counter)
{
	this->figures = figures;
	this->counter = counter;
	this->current_figure_index = current_figure_index;
}
int Memento::GetCounter()
{
	return this->counter;
}
List<Figure^>^ Memento::GetFigures()
{
	return this->figures;
}
int Memento::GetCurrentIndex()
{
	return this->current_figure_index;
}
