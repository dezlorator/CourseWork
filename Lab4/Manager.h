#pragma once
#include "Figure.h"
#include "Aggregate.h"
#include "Memento.h"
ref class Manager{
	int current_figure_index, counter;
	Bitmap^ bitmap;
	Graphics^ graphics;
	static Manager^ manager;
	Manager(int bitmap_width, int bitmap_height);
	List<Figure^>^ figures = gcnew List<Figure^>();
	bool IsFigureMoveToAnotherFigure();
	bool IsFigureMoveToTheBorder(int x, int y);
public:
	void MoveByTrace(PictureBox^ pictureBox);
	static Manager^ GetInstance(int bitmap_width, int bitmap_height);
	Bitmap^ GetBitmap();
	void ClearBitmap(Color c);
	String^ Draw(Figure^ f);
	void Move(int dx, int dy, bool createTrace);
	void RestoreStartState();
	void ChangeFigureSize(float coefficient);
	void SetColor(Color c);
	bool IsVisible();
	void SetVisible(bool flag);
	String^ MakeAggregate(List<String^>^ figure_names, int num_selected);
	void Delete();
	void DrawScene();
	void SelectFigure(String^ figure_name);
	Memento^ CreateMemento();
	void RestoreState(Memento^ memento);
};