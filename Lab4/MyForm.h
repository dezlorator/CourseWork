#pragma once
#include "Aggregate.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Manager.h"
#include <math.h>
#include "MementoManager.h"

namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		String^ path_to_memento_folder = Directory::GetCurrentDirectory() + "\\" + "Memento";
		String^ file_name = "\\Memento.txt";
		Manager^ manager;
		MementoManager^ memento_manager;
		int timer_counter = 0;
		System::Drawing::Point start_point, end_point;
	private: System::Windows::Forms::Button^ EndWorkWithObjectbtn;
	private: System::Windows::Forms::Button^ MoveLeftbtn;
	private: System::Windows::Forms::Button^ MoveRigthbtn;
	private: System::Windows::Forms::Button^ MoveDownbtn;
	private: System::Windows::Forms::Button^ MoveUpbtn;
	private: System::Windows::Forms::Button^ IncreaseSizebtn;
	private: System::Windows::Forms::Button^ ReduceSize;
	private: System::Windows::Forms::Button^ CombineFiguresbtn;
	private: System::Windows::Forms::Button^ Restorebtn;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ HideShowbtn;
	private: System::Windows::Forms::RadioButton^ WithoutTraceCheckBox;
	private: System::Windows::Forms::Button^ MoveByTracebtn;
	private: System::Windows::Forms::Button^ SerializeObject;
	private: System::Windows::Forms::Button^ Deserialize;


	private: System::Windows::Forms::CheckedListBox^ ExistedItemsCheckedListBox;
	public:
		MyForm(void)
		{
			InitializeComponent();

			if (!Directory::Exists(path_to_memento_folder))
			{
				Directory::CreateDirectory(path_to_memento_folder);
			}
			if (!File::Exists(path_to_memento_folder + file_name))
			{
				File::Create(path_to_memento_folder + file_name);
			}
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ XRectangleTextBox;
	private: System::Windows::Forms::TextBox^ YRectangleTextBox;
	private: System::Windows::Forms::TextBox^ HeightRectangleTextBox;
	private: System::Windows::Forms::TextBox^ WidthRectangleTextBox;
	private: System::Windows::Forms::Button^ AddRectanglebtn;
	private: System::Windows::Forms::Button^ AddElipsebtn;
	private: System::Windows::Forms::TextBox^ HeightElipseTextBox;
	private: System::Windows::Forms::TextBox^ WidthElipseTextBox;
	private: System::Windows::Forms::TextBox^ YElipseTextBox;
	private: System::Windows::Forms::TextBox^ XElipseTextBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->XRectangleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->YRectangleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightRectangleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WidthRectangleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddRectanglebtn = (gcnew System::Windows::Forms::Button());
			this->AddElipsebtn = (gcnew System::Windows::Forms::Button());
			this->HeightElipseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WidthElipseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->YElipseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->XElipseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ExistedItemsCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->EndWorkWithObjectbtn = (gcnew System::Windows::Forms::Button());
			this->MoveLeftbtn = (gcnew System::Windows::Forms::Button());
			this->MoveRigthbtn = (gcnew System::Windows::Forms::Button());
			this->MoveDownbtn = (gcnew System::Windows::Forms::Button());
			this->MoveUpbtn = (gcnew System::Windows::Forms::Button());
			this->IncreaseSizebtn = (gcnew System::Windows::Forms::Button());
			this->ReduceSize = (gcnew System::Windows::Forms::Button());
			this->CombineFiguresbtn = (gcnew System::Windows::Forms::Button());
			this->Restorebtn = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->HideShowbtn = (gcnew System::Windows::Forms::Button());
			this->WithoutTraceCheckBox = (gcnew System::Windows::Forms::RadioButton());
			this->MoveByTracebtn = (gcnew System::Windows::Forms::Button());
			this->SerializeObject = (gcnew System::Windows::Forms::Button());
			this->Deserialize = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(891, 274);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 298);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(136, 301);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(269, 301);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 17);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Width";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(425, 298);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Height";
			// 
			// XRectangleTextBox
			// 
			this->XRectangleTextBox->Location = System::Drawing::Point(30, 298);
			this->XRectangleTextBox->Name = L"XRectangleTextBox";
			this->XRectangleTextBox->Size = System::Drawing::Size(100, 22);
			this->XRectangleTextBox->TabIndex = 5;
			// 
			// YRectangleTextBox
			// 
			this->YRectangleTextBox->Location = System::Drawing::Point(159, 298);
			this->YRectangleTextBox->Name = L"YRectangleTextBox";
			this->YRectangleTextBox->Size = System::Drawing::Size(100, 22);
			this->YRectangleTextBox->TabIndex = 6;
			// 
			// HeightRectangleTextBox
			// 
			this->HeightRectangleTextBox->Location = System::Drawing::Point(319, 298);
			this->HeightRectangleTextBox->Name = L"HeightRectangleTextBox";
			this->HeightRectangleTextBox->Size = System::Drawing::Size(100, 22);
			this->HeightRectangleTextBox->TabIndex = 7;
			// 
			// WidthRectangleTextBox
			// 
			this->WidthRectangleTextBox->Location = System::Drawing::Point(480, 298);
			this->WidthRectangleTextBox->Name = L"WidthRectangleTextBox";
			this->WidthRectangleTextBox->Size = System::Drawing::Size(100, 22);
			this->WidthRectangleTextBox->TabIndex = 8;
			// 
			// AddRectanglebtn
			// 
			this->AddRectanglebtn->Location = System::Drawing::Point(586, 292);
			this->AddRectanglebtn->Name = L"AddRectanglebtn";
			this->AddRectanglebtn->Size = System::Drawing::Size(120, 35);
			this->AddRectanglebtn->TabIndex = 9;
			this->AddRectanglebtn->Text = L"Add rectangle";
			this->AddRectanglebtn->UseVisualStyleBackColor = true;
			this->AddRectanglebtn->Click += gcnew System::EventHandler(this, &MyForm::AddRectanglebtn_Click);
			// 
			// AddElipsebtn
			// 
			this->AddElipsebtn->Location = System::Drawing::Point(586, 336);
			this->AddElipsebtn->Name = L"AddElipsebtn";
			this->AddElipsebtn->Size = System::Drawing::Size(120, 35);
			this->AddElipsebtn->TabIndex = 18;
			this->AddElipsebtn->Text = L"Add elipse";
			this->AddElipsebtn->UseVisualStyleBackColor = true;
			this->AddElipsebtn->Click += gcnew System::EventHandler(this, &MyForm::AddElipsebtn_Click);
			// 
			// HeightElipseTextBox
			// 
			this->HeightElipseTextBox->Location = System::Drawing::Point(480, 342);
			this->HeightElipseTextBox->Name = L"HeightElipseTextBox";
			this->HeightElipseTextBox->Size = System::Drawing::Size(100, 22);
			this->HeightElipseTextBox->TabIndex = 17;
			// 
			// WidthElipseTextBox
			// 
			this->WidthElipseTextBox->Location = System::Drawing::Point(319, 342);
			this->WidthElipseTextBox->Name = L"WidthElipseTextBox";
			this->WidthElipseTextBox->Size = System::Drawing::Size(100, 22);
			this->WidthElipseTextBox->TabIndex = 16;
			// 
			// YElipseTextBox
			// 
			this->YElipseTextBox->Location = System::Drawing::Point(159, 342);
			this->YElipseTextBox->Name = L"YElipseTextBox";
			this->YElipseTextBox->Size = System::Drawing::Size(100, 22);
			this->YElipseTextBox->TabIndex = 15;
			// 
			// XElipseTextBox
			// 
			this->XElipseTextBox->Location = System::Drawing::Point(30, 342);
			this->XElipseTextBox->Name = L"XElipseTextBox";
			this->XElipseTextBox->Size = System::Drawing::Size(100, 22);
			this->XElipseTextBox->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(425, 342);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 17);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Height";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(269, 345);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 17);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Width";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(136, 345);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 17);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Y";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(7, 342);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 17);
			this->label8->TabIndex = 10;
			this->label8->Text = L"X";
			// 
			// ExistedItemsCheckedListBox
			// 
			this->ExistedItemsCheckedListBox->FormattingEnabled = true;
			this->ExistedItemsCheckedListBox->Location = System::Drawing::Point(909, 13);
			this->ExistedItemsCheckedListBox->Name = L"ExistedItemsCheckedListBox";
			this->ExistedItemsCheckedListBox->Size = System::Drawing::Size(209, 174);
			this->ExistedItemsCheckedListBox->TabIndex = 19;
			this->ExistedItemsCheckedListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ExistedItemsCheckedListBox_SelectedIndexChanged);
			// 
			// EndWorkWithObjectbtn
			// 
			this->EndWorkWithObjectbtn->Location = System::Drawing::Point(909, 194);
			this->EndWorkWithObjectbtn->Name = L"EndWorkWithObjectbtn";
			this->EndWorkWithObjectbtn->Size = System::Drawing::Size(209, 36);
			this->EndWorkWithObjectbtn->TabIndex = 20;
			this->EndWorkWithObjectbtn->Text = L"End work with object";
			this->EndWorkWithObjectbtn->UseVisualStyleBackColor = true;
			this->EndWorkWithObjectbtn->Click += gcnew System::EventHandler(this, &MyForm::EndWorkWithObjectbtn_Click);
			// 
			// MoveLeftbtn
			// 
			this->MoveLeftbtn->Location = System::Drawing::Point(12, 374);
			this->MoveLeftbtn->Name = L"MoveLeftbtn";
			this->MoveLeftbtn->Size = System::Drawing::Size(98, 36);
			this->MoveLeftbtn->TabIndex = 21;
			this->MoveLeftbtn->Text = L"Move left";
			this->MoveLeftbtn->UseVisualStyleBackColor = true;
			this->MoveLeftbtn->Click += gcnew System::EventHandler(this, &MyForm::MoveLeftbtn_Click);
			// 
			// MoveRigthbtn
			// 
			this->MoveRigthbtn->Location = System::Drawing::Point(116, 374);
			this->MoveRigthbtn->Name = L"MoveRigthbtn";
			this->MoveRigthbtn->Size = System::Drawing::Size(120, 36);
			this->MoveRigthbtn->TabIndex = 22;
			this->MoveRigthbtn->Text = L"Move rigth";
			this->MoveRigthbtn->UseVisualStyleBackColor = true;
			this->MoveRigthbtn->Click += gcnew System::EventHandler(this, &MyForm::MoveRigthbtn_Click);
			// 
			// MoveDownbtn
			// 
			this->MoveDownbtn->Location = System::Drawing::Point(116, 416);
			this->MoveDownbtn->Name = L"MoveDownbtn";
			this->MoveDownbtn->Size = System::Drawing::Size(120, 36);
			this->MoveDownbtn->TabIndex = 24;
			this->MoveDownbtn->Text = L"Move down";
			this->MoveDownbtn->UseVisualStyleBackColor = true;
			this->MoveDownbtn->Click += gcnew System::EventHandler(this, &MyForm::MoveDownbtn_Click);
			// 
			// MoveUpbtn
			// 
			this->MoveUpbtn->Location = System::Drawing::Point(12, 416);
			this->MoveUpbtn->Name = L"MoveUpbtn";
			this->MoveUpbtn->Size = System::Drawing::Size(98, 36);
			this->MoveUpbtn->TabIndex = 23;
			this->MoveUpbtn->Text = L"Move up";
			this->MoveUpbtn->UseVisualStyleBackColor = true;
			this->MoveUpbtn->Click += gcnew System::EventHandler(this, &MyForm::MoveUpbtn_Click);
			// 
			// IncreaseSizebtn
			// 
			this->IncreaseSizebtn->Location = System::Drawing::Point(910, 237);
			this->IncreaseSizebtn->Name = L"IncreaseSizebtn";
			this->IncreaseSizebtn->Size = System::Drawing::Size(208, 38);
			this->IncreaseSizebtn->TabIndex = 25;
			this->IncreaseSizebtn->Text = L"Increase size";
			this->IncreaseSizebtn->UseVisualStyleBackColor = true;
			this->IncreaseSizebtn->Click += gcnew System::EventHandler(this, &MyForm::IncreaseSizebtn_Click);
			// 
			// ReduceSize
			// 
			this->ReduceSize->Location = System::Drawing::Point(910, 280);
			this->ReduceSize->Name = L"ReduceSize";
			this->ReduceSize->Size = System::Drawing::Size(208, 38);
			this->ReduceSize->TabIndex = 26;
			this->ReduceSize->Text = L"Reduce size";
			this->ReduceSize->UseVisualStyleBackColor = true;
			this->ReduceSize->Click += gcnew System::EventHandler(this, &MyForm::ReduceSize_Click);
			// 
			// CombineFiguresbtn
			// 
			this->CombineFiguresbtn->Location = System::Drawing::Point(910, 458);
			this->CombineFiguresbtn->Name = L"CombineFiguresbtn";
			this->CombineFiguresbtn->Size = System::Drawing::Size(208, 38);
			this->CombineFiguresbtn->TabIndex = 27;
			this->CombineFiguresbtn->Text = L"Combine figures";
			this->CombineFiguresbtn->UseVisualStyleBackColor = true;
			this->CombineFiguresbtn->Click += gcnew System::EventHandler(this, &MyForm::CombineFiguresbtn_Click);
			// 
			// Restorebtn
			// 
			this->Restorebtn->Location = System::Drawing::Point(910, 325);
			this->Restorebtn->Name = L"Restorebtn";
			this->Restorebtn->Size = System::Drawing::Size(208, 39);
			this->Restorebtn->TabIndex = 28;
			this->Restorebtn->Text = L"Restore";
			this->Restorebtn->UseVisualStyleBackColor = true;
			this->Restorebtn->Click += gcnew System::EventHandler(this, &MyForm::Restorebtn_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 470);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(98, 21);
			this->checkBox1->TabIndex = 29;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Visible = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// HideShowbtn
			// 
			this->HideShowbtn->Location = System::Drawing::Point(909, 370);
			this->HideShowbtn->Name = L"HideShowbtn";
			this->HideShowbtn->Size = System::Drawing::Size(208, 39);
			this->HideShowbtn->TabIndex = 30;
			this->HideShowbtn->Text = L"Hide/Show";
			this->HideShowbtn->UseVisualStyleBackColor = true;
			this->HideShowbtn->Click += gcnew System::EventHandler(this, &MyForm::HideShowbtn_Click);
			// 
			// WithoutTraceCheckBox
			// 
			this->WithoutTraceCheckBox->AutoSize = true;
			this->WithoutTraceCheckBox->Location = System::Drawing::Point(272, 379);
			this->WithoutTraceCheckBox->Name = L"WithoutTraceCheckBox";
			this->WithoutTraceCheckBox->Size = System::Drawing::Size(113, 21);
			this->WithoutTraceCheckBox->TabIndex = 31;
			this->WithoutTraceCheckBox->Text = L"Without trace";
			this->WithoutTraceCheckBox->UseVisualStyleBackColor = true;
			// 
			// MoveByTracebtn
			// 
			this->MoveByTracebtn->Location = System::Drawing::Point(909, 413);
			this->MoveByTracebtn->Name = L"MoveByTracebtn";
			this->MoveByTracebtn->Size = System::Drawing::Size(208, 39);
			this->MoveByTracebtn->TabIndex = 32;
			this->MoveByTracebtn->Text = L"Move by trace";
			this->MoveByTracebtn->UseVisualStyleBackColor = true;
			this->MoveByTracebtn->Click += gcnew System::EventHandler(this, &MyForm::MoveByTracebtn_Click);
			// 
			// SerializeObject
			// 
			this->SerializeObject->Location = System::Drawing::Point(695, 413);
			this->SerializeObject->Name = L"SerializeObject";
			this->SerializeObject->Size = System::Drawing::Size(208, 39);
			this->SerializeObject->TabIndex = 33;
			this->SerializeObject->Text = L"Serialize";
			this->SerializeObject->UseVisualStyleBackColor = true;
			this->SerializeObject->Click += gcnew System::EventHandler(this, &MyForm::SerializeObject_Click);
			// 
			// Deserialize
			// 
			this->Deserialize->Location = System::Drawing::Point(695, 457);
			this->Deserialize->Name = L"Deserialize";
			this->Deserialize->Size = System::Drawing::Size(208, 39);
			this->Deserialize->TabIndex = 34;
			this->Deserialize->Text = L"Deserialize";
			this->Deserialize->UseVisualStyleBackColor = true;
			this->Deserialize->Click += gcnew System::EventHandler(this, &MyForm::Deserialize_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1130, 503);
			this->Controls->Add(this->Deserialize);
			this->Controls->Add(this->SerializeObject);
			this->Controls->Add(this->MoveByTracebtn);
			this->Controls->Add(this->WithoutTraceCheckBox);
			this->Controls->Add(this->HideShowbtn);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->Restorebtn);
			this->Controls->Add(this->CombineFiguresbtn);
			this->Controls->Add(this->ReduceSize);
			this->Controls->Add(this->IncreaseSizebtn);
			this->Controls->Add(this->MoveDownbtn);
			this->Controls->Add(this->MoveUpbtn);
			this->Controls->Add(this->MoveRigthbtn);
			this->Controls->Add(this->MoveLeftbtn);
			this->Controls->Add(this->EndWorkWithObjectbtn);
			this->Controls->Add(this->ExistedItemsCheckedListBox);
			this->Controls->Add(this->AddElipsebtn);
			this->Controls->Add(this->HeightElipseTextBox);
			this->Controls->Add(this->WidthElipseTextBox);
			this->Controls->Add(this->YElipseTextBox);
			this->Controls->Add(this->XElipseTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->AddRectanglebtn);
			this->Controls->Add(this->WidthRectangleTextBox);
			this->Controls->Add(this->HeightRectangleTextBox);
			this->Controls->Add(this->YRectangleTextBox);
			this->Controls->Add(this->XRectangleTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddRectanglebtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ a = System::IO::Directory::GetCurrentDirectory();
		start_point = System::Drawing::Point(Convert::ToInt32(XRectangleTextBox->Text),
			Convert::ToInt32(YRectangleTextBox->Text));
		ExistedItemsCheckedListBox->Items->Add(manager->Draw(gcnew MyRectangle
		(System::Convert::ToInt32(WidthRectangleTextBox->Text), System::Convert::ToInt32(HeightRectangleTextBox->Text),
			start_point, System::Drawing::Color::Black)));
		Redraw();
	}
	private: System::Void AddElipsebtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		start_point = System::Drawing::Point(Convert::ToInt32(XElipseTextBox->Text),
			Convert::ToInt32(YElipseTextBox->Text));
		ExistedItemsCheckedListBox->Items->Add(manager->Draw(gcnew MyEllipse
		(System::Convert::ToInt32(WidthElipseTextBox->Text), System::Convert::ToInt32(HeightElipseTextBox->Text),
			start_point, System::Drawing::Color::Black)));
		Redraw();
	}
	private: void Redraw()
	{
		if (WithoutTraceCheckBox->Checked) manager->ClearBitmap(System::Drawing::Color::White);
		manager->DrawScene();
		pictureBox1->Image = manager->GetBitmap();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		manager = Manager::GetInstance(this->pictureBox1->Size.Width, this->pictureBox1->Size.Height);
		memento_manager = gcnew MementoManager(manager, path_to_memento_folder + file_name);
	}
	private: System::Void ExistedItemsCheckedListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (ExistedItemsCheckedListBox->SelectedIndex != -1)
		{
			manager->SelectFigure(ExistedItemsCheckedListBox->Items[ExistedItemsCheckedListBox->SelectedIndex]->ToString());
		}
	}

	private: System::Void EndWorkWithObjectbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (ExistedItemsCheckedListBox->SelectedIndex != -1)
		{
			ExistedItemsCheckedListBox->Items->RemoveAt(ExistedItemsCheckedListBox->SelectedIndex);
			manager->Delete();
			Redraw();
		}
	}
	private: System::Void MoveLeftbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->Move(-5, 0, true);
		Redraw();
	}
	private: System::Void MoveUpbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->Move(0, -5, true);
		Redraw();
	}
	private: System::Void MoveRigthbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->Move(5, 0, true);
		Redraw();
	}
	private: System::Void MoveDownbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->Move(0, 5, true);
		Redraw();
	}
	private: System::Void IncreaseSizebtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->ChangeFigureSize(1.5);
		Redraw();
	}
	private: System::Void ReduceSize_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->ChangeFigureSize(0.5);
		Redraw();
	}

	private: System::Void CombineFiguresbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		List<String^>^ figure_names = gcnew List<String^>();
		List<int> indexes_to_delete;
		int counter = 0;
		for (int i = 0; i < ExistedItemsCheckedListBox->Items->Count; i++)
		{
			if (ExistedItemsCheckedListBox->GetItemChecked(i))
			{
				figure_names->Add(ExistedItemsCheckedListBox->Items[i]->ToString());
				indexes_to_delete.Add(i);
				counter++;
			}
		}
		if (counter > 0)
		{
			for (int i = indexes_to_delete.Count - 1; i >= 0; i--)
			{
				ExistedItemsCheckedListBox->Items->RemoveAt(indexes_to_delete[i]);
			}
			ExistedItemsCheckedListBox->Items->Add(manager->MakeAggregate(figure_names, counter));
			Redraw();
		}
	}
	private: System::Void Restorebtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->RestoreStartState();
		Redraw();
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void HideShowbtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (manager->IsVisible())
		{
			manager->SetVisible(false);
		}
		else
		{
			manager->SetVisible(true);
		}
		Redraw();
	}
	private: System::Void MoveByTracebtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		manager->MoveByTrace(pictureBox1);
	}
	private: System::Void SerializeObject_Click(System::Object^ sender, System::EventArgs^ e)
	{
		memento_manager->CreateMemento();
	}
	private: System::Void Deserialize_Click(System::Object^ sender, System::EventArgs^ e)
	{
		memento_manager->UndoChanges();
		Redraw();
	}
	};
}
