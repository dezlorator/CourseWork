#include "MementoManager.h"
MementoManager::MementoManager(Manager^ manager, String^ file_path)
{
	this->manager = manager;
	this->file_path = file_path;
}
void MementoManager::CreateMemento()
{
	memento = manager->CreateMemento();

}
void MementoManager::UndoChanges()
{
	
}
