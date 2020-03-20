#include "MementoManager.h"
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;
using namespace System;
using namespace std;

MementoManager::MementoManager(Manager^ manager, String^ file_path)
{
	this->manager = manager;
	this->file_path = file_path;
}
void MementoManager::CreateMemento()
{
	memento = manager->CreateMemento();
	FileStream^ file_stream = gcnew FileStream(file_path, FileMode::Open);
	BinaryFormatter^ binary_formatter = gcnew BinaryFormatter();
	binary_formatter->Serialize(file_stream, memento);
	file_stream->Close();
}
void MementoManager::UndoChanges()
{
	FileStream^ file_stream = gcnew FileStream(file_path, FileMode::Open);
	BinaryFormatter^ binary_formatter = gcnew BinaryFormatter();
	manager->RestoreState(static_cast<Memento^>(binary_formatter->Deserialize(file_stream)));
	file_stream->Close();
}
