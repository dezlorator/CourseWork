#include "Manager.h"

Manager::Manager(int bitmap_width, int bitmap_height, bool collisionCheck)
{
	bitmap = gcnew Bitmap(bitmap_width, bitmap_height);
	g = Graphics::FromImage(bitmap);
	curr_figure_indx = -1;
	counter = 0;
	checkCollisions = collisionCheck;
}
Graphics^ Manager::GetGraphics()
{
	return g;
}
Bitmap^ Manager::GetBitmap()
{
	return bitmap;
}
int Manager::GetCurrIndx()
{
	return curr_figure_indx;
}
int Manager::GetCounter()
{
	return counter;
}
void Manager::ClearBitmap(Color c)
{
	g->Clear(c);
}
bool Manager::Collision()
{
	if (curr_figure_indx != -1)
	{
		for (int i = 0; i < counter; i++)
		{
			if (curr_figure_indx != i)
			{
				if ((*figures)[i]->MaxY() > (*figures)[curr_figure_indx]->MinY() &&
					(*figures)[i]->MinY() <(*figures)[curr_figure_indx]->MaxY() &&
					(*figures)[i]->MinX() < (*figures)[curr_figure_indx]->MaxX() &&
					(*figures)[i]->MaxX() >(*figures)[curr_figure_indx]->MinX()) return true;
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
	if (curr_figure_indx != -1)
	{
		if (Boundaries(dx, dy))
		{
			if (createTrace)
			{
				if (dy == -5)
				{
					(*figures)[curr_figure_indx]->trace.Add(1);
				}
				else if (dx == 5)
				{
					(*figures)[curr_figure_indx]->trace.Add(2);
				}
				else if (dy == 5)
				{
					(*figures)[curr_figure_indx]->trace.Add(3);
				}
				else
				{
					(*figures)[curr_figure_indx]->trace.Add(4);
				}
			}
			(*figures)[curr_figure_indx]->Move(dx, dy);
			if (Collision())
			{
				SetColor(System::Drawing::Color::Blue);
			}
		}
	}
}
void Manager::Restore()
{
	if (curr_figure_indx != -1)
	{
		(*figures)[curr_figure_indx]->Restore();
	}
}
void Manager::Deformation(float coefficient)
{
	if (curr_figure_indx!=-1)
	{
		(*figures)[curr_figure_indx]->Deformation(coefficient);
	}	
}
void Manager::SetColor(Color c)
{
	if (curr_figure_indx != -1)
	{
		(*figures)[curr_figure_indx]->SetColor(c);
	}
}
void Manager::SetVisible(bool flag)
{
	if (curr_figure_indx != -1)
	{
		(*figures)[curr_figure_indx]->Visible = flag;
	}
}

bool Manager::IsVisible()
{
	bool visible = false;
	if (curr_figure_indx != -1)
	{
		visible=(*figures)[curr_figure_indx]->Visible;
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
				aggregate->Add((*figures)[i]->GetCopy());
			}
		}
	}
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < num_selected; j++)
		{
			if ((*figures)[i]->GetName() == (*figure_names)[j])
			{
				curr_figure_indx = i;
				Delete();
			}
		}
	}
	return Draw(gcnew Aggregate(aggregate));
}
void Manager::Delete()
{
	if (curr_figure_indx != -1)
	{
		(*figures).RemoveAt(curr_figure_indx);
		curr_figure_indx = -1;
		counter--;
	}
}
void Manager::Paint()
{
	if (counter != 0){
		for (int i = 0; i < counter; i++)
		{
			if ((*figures)[i]->Visible) (*figures)[i]->Draw(g);
		}
	}
}
void Manager::Select(String^ figure_name)
{
	int indx = -1;
	for (int i = 0; i < this->counter; i++)
	{
		if ((*figures)[i]->GetName() == figure_name)
		{
			indx = i;
			(*figures)[i]->Selected = true;
		}
		else
		{
			(*figures)[i]->Selected = false;
		}
	}
	curr_figure_indx = indx;
}

bool Manager::Boundaries(int x, int y)
{
	if (curr_figure_indx != -1)
	{
		if ((*figures)[curr_figure_indx]->CurrentBasePoint.X + x > bitmap->Width)
		{
			this->SetColor(System::Drawing::Color::Blue);
			return false;
		}
		else if ((*figures)[curr_figure_indx]->CurrentBasePoint.X + x < 0)
		{
			this->SetColor(System::Drawing::Color::Blue);
			return false;
		}
		else if ((*figures)[curr_figure_indx]->CurrentBasePoint.Y + y > bitmap->Height)
		{
			this->SetColor(System::Drawing::Color::Blue);
			return false;
		}
		else if ((*figures)[curr_figure_indx]->CurrentBasePoint.Y + y < 0)
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
	for (int i = 0; i < (*figures)[curr_figure_indx]->trace.Count; i++)
	{
		switch ((*figures)[curr_figure_indx]->trace[i])
		{
		case 1:
			this->Move(0, -5, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->Paint();
			pictureBox->Image = this->GetBitmap();
			break;
		case 2:
			this->Move(5, 0, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->Paint();
			pictureBox->Image = this->GetBitmap();
			break;
		case 3:
			this->Move(0, 5, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->Paint();
			pictureBox->Image = this->GetBitmap();
			break;
		case 4:
			this->Move(-5, 0, false);
			this->ClearBitmap(System::Drawing::Color::White);
			this->Paint();
			pictureBox->Image = this->GetBitmap();
			break;
		}
	}
}
