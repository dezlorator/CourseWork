#include "Aggregate.h"

Aggregate::Aggregate(List<Figure^>^ aggregate)
{
	figures_list = aggregate;
	start_point = System::Drawing::Point(MinX(), MinY());
	current_position = start_point;
}

void Aggregate::AddToAgregate(Figure^ f)
{
	figures_list->Add(f);
}

void Aggregate::Draw(System::Drawing::Graphics^ g)
{
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		this->figures_list[i]->Draw(g);
	}
}
void Aggregate::Move(int dx, int dy)
{
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		this->figures_list[i]->Move(dx, dy);
	}
	current_position.X = current_position.X + dx;
	current_position.Y = current_position.Y + dy;

}
void Aggregate::Restore()
{
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		this->figures_list[i]->Restore();
	}
}
void Aggregate::ChangeSize(float delta)
{
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		this->figures_list[i]->ChangeSize(delta);
	}
}
void Aggregate::SetColor(Color c)
{
	current_color = c;
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		this->figures_list[i]->SetColor(c);
	}
}

int Aggregate::MaxX()
{
	int max_x = figures_list[0]->MaxX();
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		if (this->figures_list[i]->MaxX() > max_x)
		{
			max_x = figures_list[i]->MaxX();
		}
	}
	return max_x;
}
int Aggregate::MaxY()
{
	int max_y = figures_list[0]->MaxY();
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		if (this->figures_list[i]->MaxY() > max_y)
		{
			max_y = figures_list[i]->MaxY();
		}
	}
	return max_y;
}
int Aggregate::MinX()
{
	int min_x = figures_list[0]->MinX();
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		if (this->figures_list[i]->MinX() < min_x)
		{
			min_x = figures_list[i]->MinX();
		}
	}
	return min_x;
}
int Aggregate::MinY()
{
	int min_y = figures_list[0]->MinY();
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		if (this->figures_list[i]->MinY() < min_y)
		{
			min_y = figures_list[i]->MinY();
		}
	}
	return min_y;
}

String^ Aggregate::GetShapeName()
{
	return "Aggregate";
}
Figure^ Aggregate::CopyFigure()
{
	List<Figure^>^ agreg_copy = gcnew List<Figure^>();
	for (int i = 0; i < this->figures_list->Count; i++)
	{
		agreg_copy->Add(figures_list[i]->CopyFigure());
	}
	return gcnew Aggregate(agreg_copy);
}

int Aggregate::GetWidth()
{
	return MaxX() - MinX();
}
int Aggregate::GetHeight()
{
	return MaxY() - MinY();
}