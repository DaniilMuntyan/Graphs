#pragma once
#include "Dot.h"
#include "ListGraph.h"
#include "SetGraph.h"
#include "MatrixGraph.h"
#include "Graph.h"
#include "ListGraphAlgs.h"
#include "SetGraphAlgs.h"
#include "MatrixGraphAlgs.h"
#include "GraphConvert.h"
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
namespace Graphs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	vector<pair<Dot, int>> points;
	map<int, Dot> my_map;

	map<pair<int, int>, int> listbox_map;

	queue<pair<int, int>> dfs_queue;

	queue<pair<int, int>> bfs_queue;
	vector<int> *price;

	vector<pair<pair<int, int>, bool>> bridges;

	vector<int> euler;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;




	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::RadioButton^  radioBFS;
	private: System::Windows::Forms::RadioButton^  radioDFS;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  radioEuler;

	private: System::Windows::Forms::RadioButton^  radioBridges;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel3;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button4;


	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioBridges = (gcnew System::Windows::Forms::RadioButton());
			this->radioEuler = (gcnew System::Windows::Forms::RadioButton());
			this->radioBFS = (gcnew System::Windows::Forms::RadioButton());
			this->radioDFS = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(341, 14);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(637, 572);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(12, 14);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(322, 617);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Панель управління";
			// 
			// button4
			// 
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Location = System::Drawing::Point(6, 572);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(307, 33);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Вигляд графу";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 208);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(177, 19);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Спосіб представлення:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"\"Ліст\" граф", L"\"Сет\" граф", L"Матриця" });
			this->comboBox1->Location = System::Drawing::Point(192, 205);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 27);
			this->comboBox1->TabIndex = 9;
			this->comboBox1->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 248);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 19);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Швидкість показу:";
			// 
			// trackBar1
			// 
			this->trackBar1->AutoSize = false;
			this->trackBar1->Location = System::Drawing::Point(183, 248);
			this->trackBar1->Maximum = 5;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(133, 31);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Value = 4;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar1_ValueChanged);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 19;
			this->listBox1->Location = System::Drawing::Point(6, 285);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(307, 270);
			this->listBox1->TabIndex = 7;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioBridges);
			this->groupBox2->Controls->Add(this->radioEuler);
			this->groupBox2->Controls->Add(this->radioBFS);
			this->groupBox2->Controls->Add(this->radioDFS);
			this->groupBox2->Location = System::Drawing::Point(6, 108);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(310, 86);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Алгоритми";
			// 
			// radioBridges
			// 
			this->radioBridges->Location = System::Drawing::Point(165, 55);
			this->radioBridges->Name = L"radioBridges";
			this->radioBridges->Size = System::Drawing::Size(73, 23);
			this->radioBridges->TabIndex = 6;
			this->radioBridges->Text = L"Мости";
			this->radioBridges->UseVisualStyleBackColor = true;
			this->radioBridges->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioBridges_CheckedChanged);
			// 
			// radioEuler
			// 
			this->radioEuler->AutoSize = true;
			this->radioEuler->Location = System::Drawing::Point(165, 26);
			this->radioEuler->Name = L"radioEuler";
			this->radioEuler->Size = System::Drawing::Size(142, 23);
			this->radioEuler->TabIndex = 5;
			this->radioEuler->Text = L"Ейлерів ланцюг";
			this->radioEuler->UseVisualStyleBackColor = true;
			this->radioEuler->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioEuler_CheckedChanged);
			// 
			// radioBFS
			// 
			this->radioBFS->Location = System::Drawing::Point(6, 55);
			this->radioBFS->Name = L"radioBFS";
			this->radioBFS->Size = System::Drawing::Size(153, 23);
			this->radioBFS->TabIndex = 4;
			this->radioBFS->Text = L"Пошук у ширину";
			this->radioBFS->UseVisualStyleBackColor = true;
			this->radioBFS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioBFS_CheckedChanged);
			// 
			// radioDFS
			// 
			this->radioDFS->AutoSize = true;
			this->radioDFS->Checked = true;
			this->radioDFS->Location = System::Drawing::Point(6, 26);
			this->radioDFS->Name = L"radioDFS";
			this->radioDFS->Size = System::Drawing::Size(153, 23);
			this->radioDFS->TabIndex = 3;
			this->radioDFS->TabStop = true;
			this->radioDFS->Text = L"Пошук у глибину";
			this->radioDFS->UseVisualStyleBackColor = true;
			this->radioDFS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioDFS_CheckedChanged);
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Location = System::Drawing::Point(17, 26);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(135, 35);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Відмінити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(17, 67);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(289, 35);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Виконати";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(171, 26);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Очистити";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1200;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Blue;
			this->panel1->Location = System::Drawing::Point(559, 614);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(60, 5);
			this->panel1->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(625, 606);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 19);
			this->label3->TabIndex = 6;
			this->label3->Text = L"- обхід графу";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(385, 602);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(130, 19);
			this->label2->TabIndex = 8;
			this->label2->Text = L"- вершина входу";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox2->Location = System::Drawing::Point(341, 593);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(38, 38);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(843, 596);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 19);
			this->label4->TabIndex = 11;
			this->label4->Text = L"- мости графу";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::GreenYellow;
			this->panel2->Location = System::Drawing::Point(777, 604);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(60, 5);
			this->panel2->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(843, 615);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 19);
			this->label5->TabIndex = 13;
			this->label5->Text = L"- Ейлерів ланцюг";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::OrangeRed;
			this->panel3->Location = System::Drawing::Point(777, 623);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(60, 5);
			this->panel3->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(991, 643);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Графи";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	Dot *p1, *p2;  //начало и конец линии
	Pen ^pen1; //перо
	Pen ^penWhite, ^penSearch, ^penBegin, ^penBridges, ^penEuler;
	SolidBrush ^brush, ^brushWhite, ^brushSearch, ^brushEuler;
	Graphics ^gr;
	Bitmap ^Img1; //основная картинка, на которой рисуем
	ListGraph *graph;
	ListGraphAlgs *listAlgs;
	SetGraph *setGraph;
	MatrixGraph *matrixGraph;
	Bitmap ^Img2; 
	Graphics ^gr2;
	GraphConvert *convert = new GraphConvert();
	bool isPressed; //флажок "кнопка мыши зажата"
	bool out; // За пределами pictureBox
	bool flag; // Для окраски первой вершины в DFS
	bool edit = true;
	int width = 20, height = 20, radius = 30;
	int firstEuler;
	int tick = 0;
	int view = 0;

	int checkInAll(Dot p)
	{
		for (pair<int, Dot> temp : my_map) {
			if (temp.second.inRegion(p.getPoint(), width, height, radius))
				return temp.first;
		}
		return -1;
	}
	int findInAll(Dot p)
	{
		for (pair<int, Dot> temp : my_map) {
			if (temp.second == p)
				return temp.first;
		}
		return -1;
	}

	System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Img1 = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		gr = Graphics::FromImage(Img1);
		Img2 = gcnew Bitmap(Img1);
		gr2 = Graphics::FromImage(Img2);
		button2->Enabled = false;
		pictureBox1->Image = Img1;
		pictureBox1->BackColor = Color::White;
		pen1 = gcnew Pen(Color::Black);
		penWhite = gcnew Pen(Color::White);
		penSearch = gcnew Pen(Color::Blue);
		penBegin = gcnew Pen(Color::DarkSeaGreen);
		penBridges = gcnew Pen(Color::GreenYellow);
		penEuler = gcnew Pen(Color::OrangeRed);
		pen1->Width = 2.4f;
		penWhite->Width = 2.4f;
		penSearch->Width = 2.4f;
		penBridges->Width = 2.4f;
		penEuler->Width = 2.4f;
		brush = gcnew SolidBrush(pen1->Color);
		brushWhite = gcnew SolidBrush(penWhite->Color);
		brushSearch = gcnew SolidBrush(penSearch->Color);
		brushEuler = gcnew SolidBrush(penEuler->Color);
		isPressed = false;
		out = false;
		flag = false;
		edit = false;
		graph = new ListGraphAlgs();
		setGraph = new SetGraphAlgs();
		matrixGraph = new MatrixGraphAlgs();
		view = 0;
		listBox1->Items->Add("Список побудованих ребер:");
		comboBox1->SelectedIndex = 0;
		view = 0;
		Bitmap ^Img2 = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
		Graphics ^gr2 = Graphics::FromImage(Img2);
		gr2->DrawEllipse(penBegin, (pictureBox2->Width - radius) / 2, (pictureBox2->Height - radius) / 2, radius, radius);
		pictureBox2->Image = Img2;
		pictureBox2->Invalidate();

		//label6->Text = matrixGraph->getGraph();
	}

	System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (edit == false)
		{
			switch (view) {
			case 0:
				graph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				break;
			case 1:
				setGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				break;
			case 2:
				matrixGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				break;
			}
			edit = true;
			timer1->Stop();
			pictureBox1->BackColor = Color::White;
			button2->Enabled = true;
		}
		out = false;
		edit = true;
		delete p1;
		p1 = new Dot(e->Location);
		int k = checkInAll(*p1);
		isPressed = true;
		if (k != -1)
		{
			*p1 = my_map[k];
			return;
		}
		else {
			switch (view) {
			case 0:
				graph->AddV(points.size());
				break;
			case 1:
				setGraph->AddV(points.size());
				break;
			case 2:
				matrixGraph->AddV(points.size());
				break;
			}
			my_map.insert(pair<int, Dot>(points.size(), *p1));
			points.push_back(pair<Dot, int>(*p1, points.size()));
		}
		p1->drawPoint(gr, brush, width, height, findInAll(*p1) + 1);
		pictureBox1->Invalidate();
	}
	System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		isPressed = false;
		delete p2;
		p2 = new Dot(e->Location);
		if (p2->getPoint().X > pictureBox1->Width || p2->getPoint().Y > pictureBox1->Height || p2->getPoint().X < 0 || p2->getPoint().Y < 0)
			return;
		out = false;
		int k = checkInAll(*p2);

		if (k != -1) {
			*p2 = my_map[k];
		}
		else
		{
			switch (view) {
			case 0:
				graph->AddV(points.size());
				break;
			case 1:
				setGraph->AddV(points.size());
				break;
			case 2:
				matrixGraph->AddV(points.size());
				break;
			}
			my_map.insert(pair<int, Dot>(points.size(), *p2)); 
			points.push_back(pair<Dot, int>(*p2, points.size()));
		}

		int from = findInAll(*p1), to = findInAll(*p2);
		if (from.ToString() != to.ToString()) {
			pair<int, int> from_to = std::make_pair(from, to);
			listbox_map.insert(std::make_pair(from_to, listBox1->Items->Count));
			listBox1->Items->Add((from + 1).ToString() + " - " + (to + 1).ToString());
			switch (view) {
			case 0:
				graph->AddArc(from, to);
				graph->AddArc(to, from);
				break;
			case 1:
				setGraph->AddArc(from, to);
				setGraph->AddArc(to, from);
				break;
			case 2:
				matrixGraph->AddArc(from, to);
				matrixGraph->AddArc(to, from);
				//label6->Text = matrixGraph->getGraph();
				break;
			}
		}
		pictureBox1->Image = Img1;
		gr->DrawLine(pen1, p1->getPoint(), p2->getPoint());
		if (k == -1)
			p2->drawPoint(gr, brush, width, height, points.size());
		else
			p2->drawPoint(gr, brush, width, height, k + 1);
		p1->drawPoint(gr, brush, width, height, from + 1);
		pictureBox1->Invalidate();
	}
	System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (!isPressed) return; // Кнопка не зажата - выйти
		/*System::Diagnostics::Stopwatch ^sw1 = gcnew System::Diagnostics::Stopwatch();
		sw1->Start();*/
		delete p2;
		p2 = new Dot(e->Location);
		Bitmap ^Img2 = gcnew Bitmap(Img1);
		Graphics ^gr2 = Graphics::FromImage(Img2);
		if (p2->getPoint().X > pictureBox1->Width || p2->getPoint().Y > pictureBox1->Height || p2->getPoint().X < 0 || p2->getPoint().Y < 0)
		{
			if (out == false) {
				gr2->DrawLine(penWhite, Point(p1->getPoint().X - width, p1->getPoint().Y - height), p2->getPoint());
				p1->drawPoint(gr2, brush, width, height, findInAll(*p1) + 1);
				pictureBox1->CreateGraphics()->DrawImage(Img2, 0, 0);
				out = true;
			}
			return;
		}
		out = false;
		int k = checkInAll(*p2);
		if (k != -1) 
			*p2 = my_map[k];
		gr2->DrawLine(pen1, p1->getPoint(), p2->getPoint());
		p1->drawPoint(gr2, brush, width, height, findInAll(*p1) + 1);
		if (k == -1) 
			p2->drawPoint(gr2, brush, width, height, points.size() + 1);
		else
			p2->drawPoint(gr2, brush, width, height, findInAll(*p2) + 1);
		pictureBox1->CreateGraphics()->DrawImage(Img2, 0, 0);
		/*sw1->Stop()
		this->Text = sw1->ElapsedMilliseconds.ToString();*/
	}
	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		edit = false;
		listBox1->Items->Clear();
		listBox1->Items->Add("Список побудованих ребер:");
		button2->Enabled = false;
		pictureBox1->Enabled = true;
		gr->Clear(Color::White);
		gr->Save();
		pictureBox1->Invalidate();
		switch (view) {
		case 0:
			graph->Clear();
			break;
		case 1:
			setGraph->Clear();
			break;
		case 2:
			matrixGraph->Clear();
			break;
		}
		timer1->Stop();
		points.clear();
		my_map.clear();
		listbox_map.clear();
		queue<pair<int, int>> empty;
		std::swap(dfs_queue, empty);
		std::swap(bfs_queue, empty);
		bridges.clear();
		euler.clear();
	}
	System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		view = comboBox1->SelectedIndex;
		int k = trackBar1->Value;
		map<int, int> temp = { {5, 600}, {4, 900}, {3, 1200}, {2, 1800}, {1, 2000} };
		timer1->Interval = temp[k];
		panel1->BackColor = penSearch->Color;
		if (radioDFS->Checked) {
			button2->Enabled = false;
			switch (view) {
			case 0:
				dfs_queue = graph->DFS(0);
				break;
			case 1:
				dfs_queue = setGraph->DFS(0);
				break;
			case 2:
				dfs_queue = matrixGraph->DFS(0);
				break;
			}
			edit = false;
			timer1->Start();
		}
		if (radioBFS->Checked)
		{
			button2->Enabled = false;
			edit = false;
			switch (view) {
			case 0:
				price = new vector<int>(graph->CountVertex(), -1);
				bfs_queue = graph->BFS(0, *price);
				break;
			case 1:
				price = new vector<int>(setGraph->CountVertex(), -1);
				bfs_queue = setGraph->BFS(0, *price);
				break;
			case 2:
				price = new vector<int>(matrixGraph->CountVertex(), -1);
				bfs_queue = matrixGraph->BFS(0, *price);
				break;
			}
			timer1->Start();
		}
		if (radioEuler->Checked) {
			button2->Enabled = false;
			edit = false;
			switch (view) {
			case 0:
				euler = graph->Euler();
				break;
			case 1:
				euler = setGraph->Euler();
				break;
			case 2:
				euler = matrixGraph->Euler();
				break;
			}
			if (euler.size() == 0) {
				MessageBox::Show("Неможливо побудувати ланцюг Ейлера");
				return;
			}
			std::reverse(euler.begin(), euler.end());
			firstEuler = euler[0];
			tick = 0;
			timer1->Start();
		}
		if (radioBridges->Checked) {
			button2->Enabled = false; 
			edit = false;
			switch (view) {
			case 0:
				bridges = graph->find_bridges();
				break;
			case 1:
				bridges = setGraph->find_bridges();
				break;
			case 2:
				bridges = matrixGraph->find_bridges();
				break;
			}
			tick = 0;
			timer1->Start();
		}
	}

	
	void tickSearch(queue<pair<int, int>> &fs_queue) {
		if (fs_queue.empty() || edit) {
			timer1->Stop();
			listBox1->ClearSelected();
			return;
		}
		pair<int, int> current = fs_queue.front();
		if (current.first == current.second) {
			my_map[current.first].drawEllipse(gr, penBegin, radius);
			my_map[current.first].drawPoint(gr, brushWhite, width, height, current.first + 1);
			my_map[current.first].drawPoint(gr, brushSearch, width, height, current.first + 1);
		}
		else {
			if (listbox_map[current])
				listBox1->SelectedIndex = listbox_map[current];
			else
				listBox1->SelectedIndex = listbox_map[std::make_pair(current.second, current.first)];
			my_map[current.first].drawTo(gr, penWhite, my_map[current.second]);
			my_map[current.first].drawTo(gr, penSearch, my_map[current.second]);
			my_map[current.first].drawPoint(gr, brushWhite, width, height, current.first + 1);
			my_map[current.first].drawPoint(gr, brushSearch, width, height, current.first + 1);
			my_map[current.second].drawPoint(gr, brushWhite, width, height, current.second + 1);
			my_map[current.second].drawPoint(gr, brushSearch, width, height, current.second + 1);
		}
		fs_queue.pop();
	}

	System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (radioDFS->Checked) 
			tickSearch(dfs_queue);
		
		if (radioBFS->Checked)
			tickSearch(bfs_queue);
		
		if (radioEuler->Checked) {
			tick++;
			if (euler.empty() || edit) {
				timer1->Stop();
				listBox1->ClearSelected();
				return;
			}
			if (tick == 1) // Обвел точку входа
			{
				my_map[euler[0]].drawEllipse(gr, penBegin, radius);
				my_map[euler[0]].drawPoint(gr, brushWhite, width, height, euler[0] + 1);
				my_map[euler[0]].drawPoint(gr, brushEuler, width, height, euler[0] + 1);
			}
			else if (euler.size() >= 2) {
				pair<int, int> current = pair<int, int>(euler[0], euler[1]);
				if (listbox_map[current])
					listBox1->SelectedIndex = listbox_map[current];
				else
					listBox1->SelectedIndex = listbox_map[std::make_pair(current.second, current.first)];
				my_map[current.first].drawTo(gr, penWhite, my_map[current.second]);
				my_map[current.first].drawTo(gr, penEuler, my_map[current.second]);
				my_map[current.first].drawPoint(gr, brushWhite, width, height, current.first + 1);
				my_map[current.first].drawPoint(gr, brushEuler, width, height, current.first + 1);
				my_map[current.second].drawPoint(gr, brushWhite, width, height, current.second + 1);
				my_map[current.second].drawPoint(gr, brushEuler, width, height, current.second + 1);

				euler.erase(euler.begin());
			} else {
				my_map[euler[0]].drawPoint(gr, brushWhite, width, height, euler[0] + 1);
				my_map[euler[0]].drawPoint(gr, brushEuler, width, height, euler[0] + 1);
				if (euler[0] == firstEuler) {
					timer1->Stop();
					MessageBox::Show("Цикл Ейлера!");
					euler.clear();
				}
			}
		}
		if (radioBridges->Checked) {
			tick++;
			if (bridges.empty() || edit) {
				timer1->Stop();
				listBox1->ClearSelected();
				return;
			}
			pair<pair<int, int>, bool> current = bridges[0];
			if (tick == 1) // Обвел точку входа
			{
				my_map[current.first.first].drawEllipse(gr, penBegin, radius);
				my_map[current.first.first].drawPoint(gr, brushWhite, width, height, current.first.first + 1);
				my_map[current.first.first].drawPoint(gr, brushSearch, width, height, current.first.first + 1);
			}
			else {
				if (listbox_map[current.first])
					listBox1->SelectedIndex = listbox_map[current.first];
				else
					listBox1->SelectedIndex = listbox_map[std::make_pair(current.first.second, current.first.first)];
				
				my_map[current.first.first].drawTo(gr, penWhite, my_map[current.first.second]);
				if (current.second) {
					my_map[current.first.first].drawTo(gr, penBridges, my_map[current.first.second]);
				}
				else 
					my_map[current.first.first].drawTo(gr, penSearch, my_map[current.first.second]);

				my_map[current.first.first].drawPoint(gr, brushWhite, width, height, current.first.first + 1);
				my_map[current.first.first].drawPoint(gr, brushSearch, width, height, current.first.first + 1);
				my_map[current.first.second].drawPoint(gr, brushWhite, width, height, current.first.second + 1);
				my_map[current.first.second].drawPoint(gr, brushSearch, width, height, current.first.second + 1);

				bridges.erase(bridges.begin());
			}
		}
		pictureBox1->Invalidate();
	}

	System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (points.size() <= 1) return;
		int v = points[points.size() - 1].second;
		timer1->Stop();
		queue<pair<int, int>> empty;
		std::swap(dfs_queue, empty);
		std::swap(bfs_queue, empty);
		euler.clear();
		my_map.erase(v);
		map<pair<int, int>, int> new_listbox_map;
		for (pair<pair<int, int>, int> temp : listbox_map) {
			pair<int, int> edge = temp.first;
			if (edge.first != v && edge.second != v)
				new_listbox_map[edge] = temp.second;
		}
		listbox_map.clear();
		listbox_map = new_listbox_map;
		gr->Clear(Color::White);
		switch (view) {
		case 0:
			graph->DeleteVertex(v);
			graph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
			graph->ToListbox(listBox1);
			break;
		case 1:
			setGraph->DeleteVertex(v);
			setGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
			setGraph->ToListbox(listBox1);
			break;
		case 2:
			matrixGraph->DeleteVertex(v);
			matrixGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
			matrixGraph->ToListbox(listBox1);
			break;
		}
		points.erase(points.begin() + points.size() - 1);
		pictureBox1->Invalidate();
	}
	System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		int k = trackBar1->Value;
		map<int, int> temp = { {5, 600}, {4, 800}, {3, 1000}, {2, 1200}, {1, 1600} };
		timer1->Interval = temp[k];
	}
	System::Void comboBox1_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
		// button1_Click(gcnew Object(), gcnew EventArgs());
		//button2->Enabled = true;
		gr->Clear(Color::White);
		timer1->Stop();
		pictureBox1->Invalidate();
		int k = comboBox1->SelectedIndex;
		switch (view) {
		case 0:
			if (k == 0) {
				graph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//graph->ToListbox(listBox1);
			}
			if (k == 1) {
				setGraph = convert->ConvertToSet(*graph);
				setGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//setGraph->ToListbox(listBox1);
			}
			if (k == 2) {
				matrixGraph = convert->ConvertToMatrix(*graph);
				matrixGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//matrixGraph->ToListbox(listBox1);
			}
			break;
		case 1:
			if (k == 0) {
				graph = convert->ConvertToList(*setGraph);
				graph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//graph->ToListbox(listBox1);
			}
			if (k == 1) {
				setGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//setGraph->ToListbox(listBox1);
			}
			if (k == 2) {
				matrixGraph = convert->ConvertToMatrix(*setGraph);
				matrixGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//matrixGraph->ToListbox(listBox1);
			}
			break;
		case 2:
			if (k == 0) { 
				graph = convert->ConvertToList(*matrixGraph);
				graph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//graph->ToListbox(listBox1);
			}
			if (k == 1) {
				setGraph = convert->ConvertToSet(*matrixGraph);
				setGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//setGraph->ToListbox(listBox1);
			}
			if (k == 2) {
				matrixGraph->printOriginalGraph(gr, brush, pen1, penWhite, my_map, width, height, radius);
				//matrixGraph->ToListbox(listBox1);
			}
			break;
		}
		view = k;
		
	}
	System::Void radioDFS_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (timer1->Enabled) {
			timer1->Stop();
		}
	}
	System::Void radioEuler_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (timer1->Enabled) {
			timer1->Stop();
		}
	}
	System::Void radioBFS_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (timer1->Enabled) {
			timer1->Stop();
		}
	}
	System::Void radioBridges_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (timer1->Enabled) {
			timer1->Stop();
		}
	}
	System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		switch (view) {
		case 0:
			MessageBox::Show(graph->getView(), "Вигляд графу");
			break;
		case 1:
			MessageBox::Show(setGraph->getView(), "Вигляд графу");
			break;
		case 2:
			MessageBox::Show(matrixGraph->getView(), "Вигляд графу");
			break;
		}

	}
};
}
