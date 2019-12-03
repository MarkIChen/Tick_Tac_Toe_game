#pragma once
#define PLAYER_1 0
#define PLAYER_2 1
#define CIRCLE 0
#define CROSS 1
#define GAME_SIZE 4

namespace Tick_TacTow4x4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Diagnostics;
	using namespace System::Threading;

	/// <summary>
	/// GameWindow 的摘要
	/// </summary>
	public ref class GameWindow : public System::Windows::Forms::Form
	{
	public:
		Image ^circle_img = Image::FromFile("circle.png");
		Image ^cross_img = Image::FromFile("cross.png");

		array<int>^ circle_table;
		array<int>^ cross_table;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  radioButton_player2;

	private: System::Windows::Forms::RadioButton^  radioButton_player1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  start_btn;
	private: System::Windows::Forms::Label^  time_label;


	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  status_label_player;
	private: System::Windows::Forms::ToolStripStatusLabel^  status_label_position;
	private: System::Windows::Forms::Panel^  draw_area1;
	private: System::Windows::Forms::Panel^  draw_area2;
	private: System::Windows::Forms::Panel^  draw_area3;
	private: System::Windows::Forms::Panel^  draw_area5;

	private: System::Windows::Forms::Panel^  draw_area6;

	private: System::Windows::Forms::Panel^  draw_area7;

	private: System::Windows::Forms::Panel^  draw_area9;

	private: System::Windows::Forms::Panel^  draw_area10;

	private: System::Windows::Forms::Panel^  draw_area11;
	private: System::Windows::Forms::Panel^  draw_area12;
	private: System::Windows::Forms::Panel^  draw_area8;
	private: System::Windows::Forms::Panel^  draw_area4;


	private: System::Windows::Forms::Panel^  draw_area16;
	private: System::Windows::Forms::Panel^  draw_area15;
	private: System::Windows::Forms::Panel^  draw_area14;
	private: System::Windows::Forms::Panel^  draw_area13;


			 //private: Button* buttonList = new Button[GAME_SIZE];

	public:
		char player;
		char first_player;
		GameWindow(void)
		{
			/*	for (int i = 0;i < GAME_SIZE;i++) {
			this->buttonList[i] = gcnew array<Button^>(GAME_SIZE);
			}*/
			InitializeComponent();
			this->status_label_player->Text = "";
			this->status_label_position->Text = "Mouse Current position: ";
			circle_table = gcnew array<int>(GAME_SIZE*GAME_SIZE);
			cross_table = gcnew array<int>(GAME_SIZE*GAME_SIZE);
			myTimer = gcnew System::Windows::Forms::Timer();
			myTimer->Interval = 1;
			myTimer->Tick += gcnew EventHandler(this, &GameWindow::Timer_Tick);
			myTimer->Start();
			watch = gcnew Stopwatch();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~GameWindow()
		{
			if (components)
			{
				delete components;
			}
		}
		void initArray(array<int> ^, int);
		void checkWinner();
		bool isWin(const array<int>^);
		void changePlayer();
		bool setTable(int);
		void stopGame();
		void startGame(char);
		void Timer_Tick(System::Object^, System::EventArgs^);

	protected:

	private:
		//array<System::Windows::Forms::Button^> btnList =
		//	Enumerable.Range(1, 9)
		//	.Select(i = > (Button)this.Controls["button" + i.ToString()])
		//	.ToList();
		// create 2d array of buttons

		int round;
		char turn;
		bool gameStarted = false;
		System::Windows::Forms::Timer ^myTimer;
		Stopwatch ^watch;

		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton_player2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_player1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->start_btn = (gcnew System::Windows::Forms::Button());
			this->time_label = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->status_label_player = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->status_label_position = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->draw_area1 = (gcnew System::Windows::Forms::Panel());
			this->draw_area2 = (gcnew System::Windows::Forms::Panel());
			this->draw_area3 = (gcnew System::Windows::Forms::Panel());
			this->draw_area5 = (gcnew System::Windows::Forms::Panel());
			this->draw_area6 = (gcnew System::Windows::Forms::Panel());
			this->draw_area7 = (gcnew System::Windows::Forms::Panel());
			this->draw_area9 = (gcnew System::Windows::Forms::Panel());
			this->draw_area10 = (gcnew System::Windows::Forms::Panel());
			this->draw_area11 = (gcnew System::Windows::Forms::Panel());
			this->draw_area12 = (gcnew System::Windows::Forms::Panel());
			this->draw_area8 = (gcnew System::Windows::Forms::Panel());
			this->draw_area4 = (gcnew System::Windows::Forms::Panel());
			this->draw_area16 = (gcnew System::Windows::Forms::Panel());
			this->draw_area15 = (gcnew System::Windows::Forms::Panel());
			this->draw_area14 = (gcnew System::Windows::Forms::Panel());
			this->draw_area13 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->radioButton_player2);
			this->panel1->Controls->Add(this->radioButton_player1);
			this->panel1->Location = System::Drawing::Point(1140, 186);
			this->panel1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(427, 160);
			this->panel1->TabIndex = 11;
			// 
			// radioButton_player2
			// 
			this->radioButton_player2->AutoSize = true;
			this->radioButton_player2->Location = System::Drawing::Point(9, 78);
			this->radioButton_player2->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->radioButton_player2->Name = L"radioButton_player2";
			this->radioButton_player2->Size = System::Drawing::Size(100, 28);
			this->radioButton_player2->TabIndex = 1;
			this->radioButton_player2->Text = L"玩家2";
			this->radioButton_player2->UseVisualStyleBackColor = true;
			// 
			// radioButton_player1
			// 
			this->radioButton_player1->AutoSize = true;
			this->radioButton_player1->Checked = true;
			this->radioButton_player1->Location = System::Drawing::Point(9, 34);
			this->radioButton_player1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->radioButton_player1->Name = L"radioButton_player1";
			this->radioButton_player1->Size = System::Drawing::Size(100, 28);
			this->radioButton_player1->TabIndex = 0;
			this->radioButton_player1->TabStop = true;
			this->radioButton_player1->Text = L"玩家1";
			this->radioButton_player1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1140, 150);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 24);
			this->label1->TabIndex = 12;
			this->label1->Text = L"先手 (o)";
			// 
			// start_btn
			// 
			this->start_btn->Location = System::Drawing::Point(1140, 478);
			this->start_btn->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->start_btn->Name = L"start_btn";
			this->start_btn->Size = System::Drawing::Size(429, 62);
			this->start_btn->TabIndex = 13;
			this->start_btn->Text = L"START";
			this->start_btn->UseVisualStyleBackColor = true;
			this->start_btn->Click += gcnew System::EventHandler(this, &GameWindow::start_btn_Click);
			// 
			// time_label
			// 
			this->time_label->AutoSize = true;
			this->time_label->BackColor = System::Drawing::SystemColors::Info;
			this->time_label->Font = (gcnew System::Drawing::Font(L"新細明體", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->time_label->Location = System::Drawing::Point(1140, 572);
			this->time_label->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->time_label->MinimumSize = System::Drawing::Size(433, 0);
			this->time_label->Name = L"time_label";
			this->time_label->Size = System::Drawing::Size(433, 54);
			this->time_label->TabIndex = 14;
			this->time_label->Text = L"Time";
			this->time_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->status_label_player,
					this->status_label_position
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 1143);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(2, 0, 30, 0);
			this->statusStrip1->Size = System::Drawing::Size(1937, 35);
			this->statusStrip1->TabIndex = 15;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// status_label_player
			// 
			this->status_label_player->Name = L"status_label_player";
			this->status_label_player->Size = System::Drawing::Size(256, 30);
			this->status_label_player->Text = L"toolStripStatusLabel1";
			// 
			// status_label_position
			// 
			this->status_label_position->Name = L"status_label_position";
			this->status_label_position->Size = System::Drawing::Size(256, 30);
			this->status_label_position->Text = L"toolStripStatusLabel2";
			// 
			// draw_area1
			// 
			this->draw_area1->BackColor = System::Drawing::Color::White;
			this->draw_area1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area1->Location = System::Drawing::Point(165, 146);
			this->draw_area1->Margin = System::Windows::Forms::Padding(0);
			this->draw_area1->Name = L"draw_area1";
			this->draw_area1->Size = System::Drawing::Size(217, 200);
			this->draw_area1->TabIndex = 0;
			this->draw_area1->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area1->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area2
			// 
			this->draw_area2->BackColor = System::Drawing::Color::White;
			this->draw_area2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area2->Location = System::Drawing::Point(381, 146);
			this->draw_area2->Margin = System::Windows::Forms::Padding(0);
			this->draw_area2->Name = L"draw_area2";
			this->draw_area2->Size = System::Drawing::Size(217, 200);
			this->draw_area2->TabIndex = 1;
			this->draw_area2->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area2->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area3
			// 
			this->draw_area3->BackColor = System::Drawing::Color::White;
			this->draw_area3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area3->Location = System::Drawing::Point(598, 146);
			this->draw_area3->Margin = System::Windows::Forms::Padding(0);
			this->draw_area3->Name = L"draw_area3";
			this->draw_area3->Size = System::Drawing::Size(217, 200);
			this->draw_area3->TabIndex = 2;
			this->draw_area3->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area3->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area5
			// 
			this->draw_area5->BackColor = System::Drawing::Color::White;
			this->draw_area5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area5->Location = System::Drawing::Point(165, 346);
			this->draw_area5->Margin = System::Windows::Forms::Padding(0);
			this->draw_area5->Name = L"draw_area5";
			this->draw_area5->Size = System::Drawing::Size(217, 200);
			this->draw_area5->TabIndex = 4;
			this->draw_area5->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area5->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area6
			// 
			this->draw_area6->BackColor = System::Drawing::Color::White;
			this->draw_area6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area6->Location = System::Drawing::Point(381, 346);
			this->draw_area6->Margin = System::Windows::Forms::Padding(0);
			this->draw_area6->Name = L"draw_area6";
			this->draw_area6->Size = System::Drawing::Size(217, 200);
			this->draw_area6->TabIndex = 5;
			this->draw_area6->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area6->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area6->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area7
			// 
			this->draw_area7->BackColor = System::Drawing::Color::White;
			this->draw_area7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area7->Location = System::Drawing::Point(598, 346);
			this->draw_area7->Margin = System::Windows::Forms::Padding(0);
			this->draw_area7->Name = L"draw_area7";
			this->draw_area7->Size = System::Drawing::Size(217, 200);
			this->draw_area7->TabIndex = 6;
			this->draw_area7->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area7->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area7->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area9
			// 
			this->draw_area9->BackColor = System::Drawing::Color::White;
			this->draw_area9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area9->Location = System::Drawing::Point(165, 546);
			this->draw_area9->Margin = System::Windows::Forms::Padding(0);
			this->draw_area9->Name = L"draw_area9";
			this->draw_area9->Size = System::Drawing::Size(217, 200);
			this->draw_area9->TabIndex = 8;
			this->draw_area9->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area9->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area9->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area10
			// 
			this->draw_area10->BackColor = System::Drawing::Color::White;
			this->draw_area10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area10->Location = System::Drawing::Point(381, 546);
			this->draw_area10->Margin = System::Windows::Forms::Padding(0);
			this->draw_area10->Name = L"draw_area10";
			this->draw_area10->Size = System::Drawing::Size(217, 200);
			this->draw_area10->TabIndex = 9;
			this->draw_area10->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area10->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area10->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area11
			// 
			this->draw_area11->BackColor = System::Drawing::Color::White;
			this->draw_area11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area11->Location = System::Drawing::Point(598, 546);
			this->draw_area11->Margin = System::Windows::Forms::Padding(0);
			this->draw_area11->Name = L"draw_area11";
			this->draw_area11->Size = System::Drawing::Size(217, 200);
			this->draw_area11->TabIndex = 10;
			this->draw_area11->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area11->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area11->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area12
			// 
			this->draw_area12->BackColor = System::Drawing::Color::White;
			this->draw_area12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area12->Location = System::Drawing::Point(815, 546);
			this->draw_area12->Margin = System::Windows::Forms::Padding(0);
			this->draw_area12->Name = L"draw_area12";
			this->draw_area12->Size = System::Drawing::Size(217, 200);
			this->draw_area12->TabIndex = 11;
			this->draw_area12->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area12->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area12->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area8
			// 
			this->draw_area8->BackColor = System::Drawing::Color::White;
			this->draw_area8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area8->Location = System::Drawing::Point(815, 346);
			this->draw_area8->Margin = System::Windows::Forms::Padding(0);
			this->draw_area8->Name = L"draw_area8";
			this->draw_area8->Size = System::Drawing::Size(217, 200);
			this->draw_area8->TabIndex = 7;
			this->draw_area8->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area8->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area8->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area4
			// 
			this->draw_area4->BackColor = System::Drawing::Color::White;
			this->draw_area4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area4->Location = System::Drawing::Point(815, 146);
			this->draw_area4->Margin = System::Windows::Forms::Padding(0);
			this->draw_area4->Name = L"draw_area4";
			this->draw_area4->Size = System::Drawing::Size(217, 200);
			this->draw_area4->TabIndex = 3;
			this->draw_area4->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area4->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area16
			// 
			this->draw_area16->BackColor = System::Drawing::Color::White;
			this->draw_area16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area16->Location = System::Drawing::Point(815, 746);
			this->draw_area16->Margin = System::Windows::Forms::Padding(0);
			this->draw_area16->Name = L"draw_area16";
			this->draw_area16->Size = System::Drawing::Size(217, 200);
			this->draw_area16->TabIndex = 15;
			this->draw_area16->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area16->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area16->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area15
			// 
			this->draw_area15->BackColor = System::Drawing::Color::White;
			this->draw_area15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area15->Location = System::Drawing::Point(598, 746);
			this->draw_area15->Margin = System::Windows::Forms::Padding(0);
			this->draw_area15->Name = L"draw_area15";
			this->draw_area15->Size = System::Drawing::Size(217, 200);
			this->draw_area15->TabIndex = 14;
			this->draw_area15->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area15->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area15->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area14
			// 
			this->draw_area14->BackColor = System::Drawing::Color::White;
			this->draw_area14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area14->Location = System::Drawing::Point(381, 746);
			this->draw_area14->Margin = System::Windows::Forms::Padding(0);
			this->draw_area14->Name = L"draw_area14";
			this->draw_area14->Size = System::Drawing::Size(217, 200);
			this->draw_area14->TabIndex = 13;
			this->draw_area14->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area14->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area14->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area13
			// 
			this->draw_area13->BackColor = System::Drawing::Color::White;
			this->draw_area13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area13->Location = System::Drawing::Point(165, 746);
			this->draw_area13->Margin = System::Windows::Forms::Padding(0);
			this->draw_area13->Name = L"draw_area13";
			this->draw_area13->Size = System::Drawing::Size(217, 200);
			this->draw_area13->TabIndex = 12;
			this->draw_area13->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area13->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area13->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// GameWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1937, 1178);
			this->Controls->Add(this->draw_area16);
			this->Controls->Add(this->draw_area12);
			this->Controls->Add(this->draw_area15);
			this->Controls->Add(this->draw_area11);
			this->Controls->Add(this->draw_area14);
			this->Controls->Add(this->draw_area8);
			this->Controls->Add(this->draw_area13);
			this->Controls->Add(this->draw_area10);
			this->Controls->Add(this->draw_area4);
			this->Controls->Add(this->draw_area9);
			this->Controls->Add(this->draw_area7);
			this->Controls->Add(this->draw_area6);
			this->Controls->Add(this->draw_area5);
			this->Controls->Add(this->draw_area3);
			this->Controls->Add(this->draw_area2);
			this->Controls->Add(this->draw_area1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->time_label);
			this->Controls->Add(this->start_btn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"GameWindow";
			this->Text = L"GameWindow";
			this->Load += gcnew System::EventHandler(this, &GameWindow::GameWindow_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GameWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void draw_area_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		Panel^ panel = (Panel^)sender;
		int index = panel->TabIndex;
		int row = index / GAME_SIZE + 1;
		int col = index % GAME_SIZE + 1;
		this->status_label_position->Text = "Mouse Current position: (" + row + ", " + col + ")";
	}

	private: System::Void start_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->start_btn->Text == "START") {
			char newPlayer = PLAYER_1;
			if (this->radioButton_player2->Checked == true) {
				newPlayer = PLAYER_2;
			}
			this->start_btn->Text = "STOP";
			startGame(newPlayer);
		}
		else {
			this->start_btn->Text = "START";
			stopGame();
		}

	}


	private: System::Void draw_area_Click(System::Object^  sender, System::EventArgs^  e) {
		Panel^ panel = (Panel^)sender;
		Graphics^ g = panel->CreateGraphics();

		if (gameStarted == true) {
			int index = panel->TabIndex;
			if (setTable(index) == false) return;
			round++;

			panel->Invalidate();
			
			checkWinner();
			changePlayer();
		}
	}
	private: System::Void draw_area_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Panel^ panel = (Panel^)sender;
		Graphics^ g = panel->CreateGraphics();

		if (circle_table[panel->TabIndex] == 1) {
			g->DrawEllipse(Pens::Blue, Rectangle(10, 10, 80, 80));
		}
		else if (cross_table[panel->TabIndex] == 1) {
			g->DrawLine(Pens::Black, 20, 20, 80, 80);
			g->DrawLine(Pens::Black, 80, 20, 20, 80);
		}

	}

	};

}
