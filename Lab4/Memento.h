#pragma once
#include "Figure.h";
#include "Aggregate.h"

using namespace System;

[Serializable]
ref class Memento
{
	List<Figure^>^ figures = gcnew List<Figure^>();
	int current_figure_index, counter;
public:
	Memento(List<Figure^>^ figures, int current_figure_index, int counter);
	List<Figure^>^ GetFigures();
	int GetCurrentIndex();
	int GetCounter();
};

