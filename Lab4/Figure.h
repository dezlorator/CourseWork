#pragma once  
#ifndef Figure_H
#define Figure_H

#include <string>
#include <vcclr.h>  
#include <vector>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

ref class Figure abstract{
protected:
	Color CurrentColor, InitialColor;
	String^ Name;
	Point InitialBasePoint;
public:
	bool Selected = true;
	bool Visible = true;
	Point CurrentBasePoint;

	virtual Figure^ GetCopy() = 0;
	List<int> trace;
	virtual int MaxX() = 0;
	virtual int MaxY() = 0;
	virtual int MinX() = 0;
	virtual int MinY() = 0;
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual void Draw(System::Drawing::Graphics^ g) = 0;
	virtual void Move(int dx, int dy) = 0;
	virtual void Restore() = 0;
	virtual void Deformation(float coefficient) = 0;
	virtual void SetColor(Color c);
	virtual String^ GetShapeName();
	Color GetColor();
	String^ GetName();
	void SetName(String^ name);
};

#endif