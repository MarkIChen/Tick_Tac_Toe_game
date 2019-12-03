#pragma once
#define PLAYER_1 0
#define PLAYER_2 1
#define CIRCLE 0
#define CROSS 1
#define GAME_SIZE 3

namespace TickTacToe {

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
	private: System::Windows::Forms::Panel^  draw_area4;
	private: System::Windows::Forms::Panel^  draw_area5;
	private: System::Windows::Forms::Panel^  draw_area6;
	private: System::Windows::Forms::Panel^  draw_area7;
	private: System::Windows::Forms::Panel^  draw_area8;
	private: System::Windows::Forms::Panel^  draw_area9;

	//private: Button* buttonList = new Button[GAME_SIZE];

	public:
		bool player;
		bool first_player;
		GameWindow(void)
		{

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
			this->draw_area4 = (gcnew System::Windows::Forms::Panel());
			this->draw_area5 = (gcnew System::Windows::Forms::Panel());
			this->draw_area6 = (gcnew System::Windows::Forms::Panel());
			this->draw_area7 = (gcnew System::Windows::Forms::Panel());
			this->draw_area8 = (gcnew System::Windows::Forms::Panel());
			this->draw_area9 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->radioButton_player2);
			this->panel1->Controls->Add(this->radioButton_player1);
			this->panel1->Location = System::Drawing::Point(882, 182);
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
			this->label1->Location = System::Drawing::Point(882, 146);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 24);
			this->label1->TabIndex = 12;
			this->label1->Text = L"先手 (o)";
			// 
			// start_btn
			// 
			this->start_btn->Location = System::Drawing::Point(882, 474);
			this->start_btn->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->start_btn->Name = L"start_btn";
			this->start_btn->Size = System::Drawing::Size(429, 62);
			this->start_btn->TabIndex = 13;
			this->start_btn->Text = L"START";
			this->start_btn->UseVisualStyleBackColor = true;
			this->start_btn->Click += gcnew System::EventHandler(this, &GameWindow::start_btn_click);
			// 
			// time_label
			// 
			this->time_label->AutoSize = true;
			this->time_label->BackColor = System::Drawing::SystemColors::Info;
			this->time_label->Font = (gcnew System::Drawing::Font(L"新細明體", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->time_label->Location = System::Drawing::Point(882, 568);
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
			this->statusStrip1->Location = System::Drawing::Point(0, 994);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(2, 0, 30, 0);
			this->statusStrip1->Size = System::Drawing::Size(1774, 35);
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
			this->draw_area2->Location = System::Drawing::Point(382, 146);
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
			this->draw_area3->Location = System::Drawing::Point(599, 146);
			this->draw_area3->Margin = System::Windows::Forms::Padding(0);
			this->draw_area3->Name = L"draw_area3";
			this->draw_area3->Size = System::Drawing::Size(217, 200);
			this->draw_area3->TabIndex = 2;
			this->draw_area3->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area3->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area4
			// 
			this->draw_area4->BackColor = System::Drawing::Color::White;
			this->draw_area4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area4->Location = System::Drawing::Point(165, 346);
			this->draw_area4->Margin = System::Windows::Forms::Padding(0);
			this->draw_area4->Name = L"draw_area4";
			this->draw_area4->Size = System::Drawing::Size(217, 200);
			this->draw_area4->TabIndex = 3;
			this->draw_area4->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area4->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area5
			// 
			this->draw_area5->BackColor = System::Drawing::Color::White;
			this->draw_area5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area5->Location = System::Drawing::Point(382, 346);
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
			this->draw_area6->Location = System::Drawing::Point(599, 346);
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
			this->draw_area7->Location = System::Drawing::Point(165, 546);
			this->draw_area7->Margin = System::Windows::Forms::Padding(0);
			this->draw_area7->Name = L"draw_area7";
			this->draw_area7->Size = System::Drawing::Size(217, 200);
			this->draw_area7->TabIndex = 6;
			this->draw_area7->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area7->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area7->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area8
			// 
			this->draw_area8->BackColor = System::Drawing::Color::White;
			this->draw_area8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area8->Location = System::Drawing::Point(382, 546);
			this->draw_area8->Margin = System::Windows::Forms::Padding(0);
			this->draw_area8->Name = L"draw_area8";
			this->draw_area8->Size = System::Drawing::Size(217, 200);
			this->draw_area8->TabIndex = 7;
			this->draw_area8->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area8->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area8->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// draw_area9
			// 
			this->draw_area9->BackColor = System::Drawing::Color::White;
			this->draw_area9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->draw_area9->Location = System::Drawing::Point(599, 546);
			this->draw_area9->Margin = System::Windows::Forms::Padding(0);
			this->draw_area9->Name = L"draw_area9";
			this->draw_area9->Size = System::Drawing::Size(217, 200);
			this->draw_area9->TabIndex = 8;
			this->draw_area9->Click += gcnew System::EventHandler(this, &GameWindow::draw_area_Click);
			this->draw_area9->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area_Paint);
			this->draw_area9->MouseHover += gcnew System::EventHandler(this, &GameWindow::draw_area_MouseHover);
			// 
			// GameWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1774, 1029);
			this->Controls->Add(this->draw_area9);
			this->Controls->Add(this->draw_area8);
			this->Controls->Add(this->draw_area7);
			this->Controls->Add(this->draw_area6);
			this->Controls->Add(this->draw_area5);
			this->Controls->Add(this->draw_area4);
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
	this->status_label_position->Text ="Mouse Current position: (" + row + ", " + col + ")";
}

private: System::Void start_btn_click(System::Object^  sender, System::EventArgs^  e) {
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
