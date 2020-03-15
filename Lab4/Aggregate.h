#pragma once  
#ifndef Aggregate_H
#define Aggregate_H
#include "Figure.h"

ref class Aggregate : public Figure
{
private:
	List<Figure^>^ AggregateList = gcnew List<Figure^>();
public:

	Aggregate(List<Figure^>^ aggregate);

	Figure^ GetCopy() override;
	void AddToAgregate(Figure^ f);
	void Draw(System::Drawing::Graphics^ g) override;
	void Move(int dx, int dy) override;
	void Restore() override;
	void Deformation(float coefficient) override;
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