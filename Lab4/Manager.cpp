#include "Manager.h"

Manager::Manager(int bitmap_width, int bitmap_height)
{
	bitmap = gcnew Bitmap(bitmap_width, bitmap_height);
	graphics = Graphics::FromImage(bitmap);
	current_figure_index = -1;
	counter = 0;
}
Bitmap^ Manager::GetBitmap()
{
	return bitmap;
}
void Manager::ClearBitmap(Color c)
{
	graphics->Clear(c);
}
bool Manager::IsFigureMoveToAnotherFigure()
{
	if (current_figure_index != -1)
	{
		for (int i = 0; i < counter; i++)
		{
			if (current_figure_index != i)
			{
				if ((*figures)[i]->MaxY() > (*figures)[current_figure_index]->MinY() &&
					(*figures)[i]->MinY() <(*figures)[current_figure_index]->MaxY() &&
					(*figures)[i]->MinX() < (*figures)[current_figure_index]->MaxX() &&
					(*figures)[i]->MaxX() >(*figures)[current_figure_index]->MinX()) 
				{
					return true;
				}
			}
		}
	}

	return false;
}
String^ Manager::Draw(Figure^ f)
{
	counter++;
	figures->Add(f);
	String ^ name = (*figures)[counter - 1]->GetShapeName() + " ¹" + counter;
	(*figures)[counter - 1]->SetName(name);
	return name;
}
void Manager::Move(int dx, int dy, bool createTrace)
{
	if (current_figure_index != -1)
	{
		if (IsFigureMoveToTheBorder(dx, dy))
		{
			if (createTrace)
			{
				if (dy == -5)
				{
					(*figures)[current_figure_index]->trace.Add(1);
				}
				else if (dx == 5)
				{
					(*figures)[current_figure_index]->trace.Add(2);
				}
				else if (dy == 5)
				{
					(*figures)[current_figure_index]->trace.Add(3);
				}
				else
				{
					(*figures)[current_figure_index]->trace.Add(4);
				}
			}
			(*figures)[current_figure_index]->Move(dx, dy);
			if (IsFigureMoveToAnotherFigure())
			{
				SetColor(System::Drawing::Color::Blue);
			}
		}
	}
}
void Manager::RestoreStartState()
{
	if (current_figure_index != -1)
	{
		(*figures)[current_figure_index]->Restore();
	}
}
void Manager::ChangeFigureSize(float coefficient)
{
	if (current_figure_index!=-1)
	{
		(*figures)[current_figure_index]->ChangeSize(coefficient);
	}	
}
void Manager::SetColor(Color c)
{
	if (current_figure_index != -1)
	{
		(*figures)[current_figure_index]->SetColor(c);
	}
}
void Manager::SetVisible(bool flag)
{
	if (current_figure_index != -1)
	{
		(*figures)[current_figure_index]->is_visible = flag;
	}
}

bool Manager::IsVisible()
{
	bool visible = false;
	if (current_figure_index != -1)
	{
		visible=(*figures)[current_figure_index]->is_visible;
	}
	return visible;
}

String^ Manager::MakeAggregate(List<String^>^ figure_names, int num_selected)
{
	List<Figure^>^ aggregate = gcnew List<Figure^>();
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < num_selected; j++)
		{
			if ((*figures)[i]->GetName() == (*figure_names)[j])
			{
				aggregate->Add((*figures)[i]->CopyFigure());
			}
		}
	}
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < num_selected; j++)
		{
			if ((*figures)[i]->GetName() == (*figure_names)[j])
			{
				current_figure_index = i;
				Delete();
			}
		}
	}
	return Draw(gcnew Aggregate(aggregate));
}
void Manager::Delete()
{
	if (current_figure_index != -1)
	{
		(*figures).RemoveAt(current_figure_index);
		current_figure_index = -1;
		counter--;
	}
}
void Manager::DrawScene()
{
	if (counter != 0){
		for (int i = 0; i < counter; i++)
		{
			if ((*figures)[i]->is_visible) (*figures)[i]->Draw(graphics);
		}
	}
}
void Manager::SelectFigure(String^ figure_name)
{
	int indx = -1;
	for (int i = 0; i < this->counter; i++)
	{
		if ((*figures)[i]->GetName() == figure_name)
		{
			indx = i;
			(*figures)[i]->is_selected = true;
		}
		else
		{
			(*figures)[i]->is_selected = false;
		}
	}
	current_figure_index = indx;
}

bool Manager::IsFigureMoveToTheBorder(int x, int y)
{
	if (current_figure_index != -1)
	{
		if ((*figures)[current_figure_index]->current_position.X + x > bitmap->Width)
		{
			this->SetColor(System::Drawing::Color::Blue);
			return false;
		}
		else if ((*figures)[current_figure_index]->current_position.X + x < 0)
		{
			this->SetColor(System::Drawing::Color::Blue);
			return false;
		}
		else if ((*figures)[current_figure_index]->current_position.Y + y > bitmap->Height)
		{
			this->SetColor(System::Drawing::Color::Blue);
			return false;
		}
		else if ((*figures)[current_figure_index]->current_position.Y + y < 0)
		{
			this->SetColor(System::Drawing::Color::Blue);
			return false;
		}
		this->SetColor(System::Drawing::Color::Black);
		return true;
	}
}
void Manager::MoveByTrace(PictureBox^ pictureBox)
{
	for (int i = 0; i < (*figures)[current_figure_index]->trace.Count; i++)
	{
		switch ((*figures)[current_figure_index]->trace[i])
		{
		case 1:
			this->Move(0, -5, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->DrawScene();
			pictureBox->Image = this->GetBitmap();
			break;
		case 2:
			this->Move(5, 0, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->DrawScene();
			pictureBox->Image = this->GetBitmap();
			break;
		case 3:
			this->Move(0, 5, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->DrawScene();
			pictureBox->Image = this->GetBitmap();
			break;
		case 4:
			this->Move(-5, 0, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->DrawScene();
			pictureBox->Image = this->GetBitmap();
			break;
		}
	}
}
Manager^ Manager::GetInstance(int bitmap_width, int bitmap_height)
{
	if (manager == nullptr)
	{
		manager = gcnew Manager(bitmap_width, bitmap_height);
	}

	return manager;
}
Memento^ Manager::CreateMemento()
{
	return gcnew Memento(figures, current_figure_index, counter);
}
void Manager::RestoreState(Memento^ memento)
{
	current_figure_index = memento->GetCurrentIndex();
	counter = memento->GetCounter();
	figures->Clear();
	for (int i = 0; i < memento->GetCounter(); i++)
	{
		figures->Add(memento->GetFigures()[i]);
	}
}
