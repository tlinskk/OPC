// MyForm.h
#pragma once

namespace Lab8_Graphics {

	enum class ShapeType { None, Point, Line, Rectangle, Ellipse };

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		ShapeType currentShape;
		MenuStrip^ menuStrip;
		ToolStripMenuItem^ fileMenu;
		ToolStripMenuItem^ helpMenu;
		ToolStripMenuItem^ objectsMenu;
		ToolStripMenuItem^ pointItem;
		ToolStripMenuItem^ lineItem;
		ToolStripMenuItem^ rectangleItem;
		ToolStripMenuItem^ ellipseItem;

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->Text = "��������� �������� - ������: ͳ����";
			currentShape = ShapeType::None;
			this->DoubleBuffered = true;
		}

	protected:
		~MyForm()
		{
			if (components)
				delete components;
		}

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->menuStrip = gcnew MenuStrip();
			this->fileMenu = gcnew ToolStripMenuItem("����");
			this->helpMenu = gcnew ToolStripMenuItem("������");
			this->objectsMenu = gcnew ToolStripMenuItem("�ᒺ���");

			this->pointItem = gcnew ToolStripMenuItem("������");
			this->lineItem = gcnew ToolStripMenuItem("˳��");
			this->rectangleItem = gcnew ToolStripMenuItem("�����������");
			this->ellipseItem = gcnew ToolStripMenuItem("����");

			this->objectsMenu->DropDownItems->AddRange(gcnew array<ToolStripItem^>{
				pointItem, lineItem, rectangleItem, ellipseItem });

			this->menuStrip->Items->AddRange(gcnew array<ToolStripItem^>{
				fileMenu, objectsMenu, helpMenu });

			this->MainMenuStrip = this->menuStrip;
			this->Controls->Add(this->menuStrip);
			this->menuStrip->Location = Drawing::Point(0, 0);
			this->menuStrip->Name = "menuStrip";
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = "menuStrip";

			this->pointItem->Click += gcnew EventHandler(this, &MyForm::SelectPoint);
			this->lineItem->Click += gcnew EventHandler(this, &MyForm::SelectLine);
			this->rectangleItem->Click += gcnew EventHandler(this, &MyForm::SelectRectangle);
			this->ellipseItem->Click += gcnew EventHandler(this, &MyForm::SelectEllipse);

			this->ClientSize = Drawing::Size(600, 400);
			this->Name = L"MyForm";
			this->Text = L"Lab 8";
		}
#pragma endregion

	private: void SelectPoint(Object^ sender, EventArgs^ e) {
			currentShape = ShapeType::Point;
			this->Text = "��������� �������� - ������: ������";
			this->Invalidate();
		}

	private: void SelectLine(Object^ sender, EventArgs^ e) {
			currentShape = ShapeType::Line;
			this->Text = "��������� �������� - ������: ˳��";
			this->Invalidate();
		}

	private: void SelectRectangle(Object^ sender, EventArgs^ e) {
			currentShape = ShapeType::Rectangle;
			this->Text = "��������� �������� - ������: �����������";
			this->Invalidate();
		}

	private: void SelectEllipse(Object^ sender, EventArgs^ e) {
			currentShape = ShapeType::Ellipse;
			this->Text = "��������� �������� - ������: ����";
			this->Invalidate();
		}

	protected:
		virtual void OnPaint(PaintEventArgs^ e) override {
			Graphics^ g = e->Graphics;
			Pen^ pen = gcnew Pen(Color::Black, 2);
			SolidBrush^ fillBrush = gcnew SolidBrush(Color::White);

			switch (currentShape) {
			case ShapeType::Point: {
				g->FillEllipse(Brushes::Black, 100, 100, 2, 2);
				break;
			case ShapeType::Line:
				g->DrawLine(pen, 50, 150, 200, 150);
				break;
			}
			case ShapeType::Rectangle: {
				// �� ������ �� ������ � ���� ��� ������� (� mod 2 = 1)
				int cx = 200, cy = 100, w = 100, h = 60;
				fillBrush = gcnew SolidBrush(Color::White); // � mod 5 = 0
				g->FillRectangle(fillBrush, cx - w / 2, cy - h / 2, w, h);
				g->DrawRectangle(pen, cx - w / 2, cy - h / 2, w, h);
				break;
			}
			case ShapeType::Ellipse: {
				// �� ���� ����������� ����� ����������� ������������ ��� ������� (� mod 2 = 1)
				/*fillBrush = gcnew SolidBrush(Color::Orange);
				g->FillEllipse(fillBrush, 100, 200, 120, 80);*/
				g->DrawEllipse(pen, 100, 200, 120, 80); // ��� ���������� (� mod 5 = 0 or 2)
				break;
			}
			}
		}
	};
}
