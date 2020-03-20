#pragma once
#include "Figure.h"
#include "Aggregate.h"
#include "Memento.h"
ref class Manager{
	int current_figure_index, counter;
	Bitmap^ bitmap;
	Graphics^ g;
	static Manager^ manager;
	Manager(int bitmap_width, int bitmap_height, bool collisionCheck);
	List<Figure^>^ figures = gcnew List<Figure^>();
public:
	bool checkCollisions;
	void MoveByTrace(PictureBox^ pictureBox);
	static Manager^ GetInstance(int bitmap_width, int bitmap_height, bool collisionCheck);
	Graphics^ GetGraphics();
	Bitmap^ GetBitmap();
	int GetCurrIndx();
	int GetCounter();
	void ClearBitmap(Color c);
	bool Collision();
	String^ Draw(Figure^ f);
	void Move(int dx, int dy, bool createTrace);
	void Restore();
	void Deformation(float coefficient);
	void SetColor(Color c);
	bool Boundaries(int x, int y);
	bool IsVisible();
	void SetVisible(bool flag);
	String^ MakeAggregate(List<String^>^ figure_names, int num_selected);
	void Delete();
	void Paint();
	void Select(String^ figure_name);
	Memento^ CreateMemento();
	void RestoreState(Memento^ memento);
};