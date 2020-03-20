#pragma once  
#ifndef Aggregate_H
#define Aggregate_H
#include "Figure.h"
using namespace System;

[Serializable]
ref class Aggregate : public Figure
{
private:
	List<Figure^>^ figures_list = gcnew List<Figure^>();
public:

	Aggregate(List<Figure^>^ aggregate);

	Figure^ CopyFigure() override;
	void AddToAgregate(Figure^ f);
	void Draw(System::Drawing::Graphics^ g) override;
	void Move(int dx, int dy) override;
	void Restore() override;
	void ChangeSize(float coefficient) override;
	void SetColor(Color c) override;
	String^ GetShapeName() override;
	int MaxX() override;
	int MaxY() override;
	int MinX() override;
	int MinY() override;
	int GetWidth() override;
	int GetHeight() override;
};
#endif