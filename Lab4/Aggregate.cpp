#include "Aggregate.h"

Aggregate::Aggregate(List<Figure^>^ aggregate)
{
	AggregateList = aggregate;
	start_point = System::Drawing::Point(MinX(), MinY());
	current_position = start_point;
}

void Aggregate::AddToAgregate(Figure^ f)
{
	AggregateList->Add(f);
}

void Aggregate::Draw(System::Drawing::Graphics^ g)
{
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		this->AggregateList[i]->Draw(g);
	}
}
void Aggregate::Move(int dx, int dy)
{
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		this->AggregateList[i]->Move(dx, dy);
	}
	current_position.X = current_position.X + dx;
	current_position.Y = current_position.Y + dy;

}
void Aggregate::Restore()
{
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		this->AggregateList[i]->Restore();
	}
}
void Aggregate::ChangeSize(float delta)
{
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		this->AggregateList[i]->ChangeSize(delta);
	}
}
void Aggregate::SetColor(Color c)
{
	current_color = c;
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		this->AggregateList[i]->SetColor(c);
	}
}

int Aggregate::MaxX()
{
	int max_x = AggregateList[0]->MaxX();
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		if (this->AggregateList[i]->MaxX() > max_x)
		{
			max_x = AggregateList[i]->MaxX();
		}
	}
	return max_x;
}
int Aggregate::MaxY()
{
	int max_y = AggregateList[0]->MaxY();
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		if (this->AggregateList[i]->MaxY() > max_y)
		{
			max_y = AggregateList[i]->MaxY();
		}
	}
	return max_y;
}
int Aggregate::MinX()
{
	int min_x = AggregateList[0]->MinX();
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		if (this->AggregateList[i]->MinX() < min_x)
		{
			min_x = AggregateList[i]->MinX();
		}
	}
	return min_x;
}
int Aggregate::MinY()
{
	int min_y = AggregateList[0]->MinY();
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		if (this->AggregateList[i]->MinY() < min_y)
		{
			min_y = AggregateList[i]->MinY();
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
	for (int i = 0; i < this->AggregateList->Count; i++)
	{
		agreg_copy->Add(AggregateList[i]->CopyFigure());
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