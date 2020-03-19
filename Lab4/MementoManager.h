#pragma once
#include "Figure.h";
#include "Aggregate.h"
#include "Memento.h"
#include "Manager.h"

ref class MementoManager
{
	Memento^ memento;
	Manager^ manager;
	String^ file_path;
public:
	MementoManager(Manager^ manager, String^ file_path);
	void CreateMemento();
	void UndoChanges();
};

