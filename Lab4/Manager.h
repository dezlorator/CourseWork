#include "Figure.h"
#include "Aggregate.h"
ref class Manager{
	int curr_figure_indx, counter;
	Bitmap^ bitmap;
	Graphics^ g;
public:
	List<Figure^>^ figures = gcnew List<Figure^>();
	bool checkCollisions;
	Manager(int bitmap_width, int bitmap_height, bool collisionCheck);
	void MoveByTrace(PictureBox^ pictureBox);
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

};