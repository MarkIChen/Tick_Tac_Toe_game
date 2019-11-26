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



	//private: Button* buttonList = new Button[GAME_SIZE];

	public:
		char player;
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
		void setImage(Button ^);
		bool setTable(int);
		void stopGame();
		void startGame(char);
		void Timer_Tick(System::Object^, System::EventArgs^);

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
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
			this->panel1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(147, 124);
			this->button1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(217, 200);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button1->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(377, 124);
			this->button2->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(217, 200);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button2->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(607, 124);
			this->button3->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(217, 200);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button3->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(607, 336);
			this->button4->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(217, 200);
			this->button4->TabIndex = 5;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button4->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(377, 336);
			this->button5->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(217, 200);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button5->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(147, 336);
			this->button6->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(217, 200);
			this->button6->TabIndex = 3;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button6->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(607, 548);
			this->button7->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(217, 200);
			this->button7->TabIndex = 8;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button7->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(377, 548);
			this->button8->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(217, 200);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button8->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(147, 548);
			this->button9->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(217, 200);
			this->button9->TabIndex = 6;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &GameWindow::button1_Click);
			this->button9->MouseHover += gcnew System::EventHandler(this, &GameWindow::button1_MouseHover);
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
			this->start_btn->Click += gcnew System::EventHandler(this, &GameWindow::button10_Click);
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
			this->draw_area1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->draw_area1->Location = System::Drawing::Point(1351, 182);
			this->draw_area1->Name = L"draw_area1";
			this->draw_area1->Size = System::Drawing::Size(200, 200);
			this->draw_area1->TabIndex = 16;
			this->draw_area1->Click += gcnew System::EventHandler(this, &GameWindow::draw_area1_Click);
			this->draw_area1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::draw_area1_Paint);
			// 
			// GameWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1774, 1029);
			this->Controls->Add(this->draw_area1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->time_label);
			this->Controls->Add(this->start_btn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
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

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->label1->Text = "Clicked";
		Image ^i = Image::FromFile("image.jpeg");
		this->label1->Size = System::Drawing::Size(i->Width, i->Height);
		this->label1->Image = i;
	}

	private: System::Void GameWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Button^ button = (Button^)sender;
		
		if (gameStarted == true) {
			int index = button->TabIndex;
			if (setTable(index) == false) return;
			round++;
			setImage(button);
			changePlayer();
			checkWinner();
		}
	}

private: System::Void button1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	Button^ button = (Button^)sender;
	int index = button->TabIndex;
	int row = index / 3 + 1;
	int col = index % 3 + 1;
	this->status_label_position->Text ="Mouse Current position: (" + row + ", " + col + ")";
}

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
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


private: System::Void draw_area1_Click(System::Object^  sender, System::EventArgs^  e) {
	Graphics^ g = this->draw_area1->CreateGraphics();

	//Rectangle^ bbox1 = gcnew Rectangle(30, 40, 50, 50);
	g->DrawEllipse(Pens::Red, Rectangle(7, 7, 80, 80));
}
private: System::Void draw_area1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
}
};
}
