
#include "stdafx.h"
#include "GameWindow.h"

using namespace System;
using namespace TickTacToe;

void TickTacToe::GameWindow::initArray(array<int> ^array, int size)
{
	for (int i = 0;i < size;i++) {
		array[i] = 0;
	}
}

void TickTacToe::GameWindow::checkWinner() {
	if (isWin(circle_table) == true) {
		stopGame();
		System::Windows::Forms::MessageBox::Show("Player one Win");
		watch->Stop();
	}
	else if (isWin(cross_table)==true) {
		stopGame();
		System::Windows::Forms::MessageBox::Show("Player two Win");
		watch->Stop();
	}
	else if (round == GAME_SIZE * GAME_SIZE) {
		stopGame();
		System::Windows::Forms::MessageBox::Show("EVEN, restart game.");
		watch->Stop();
	}
}

void TickTacToe::GameWindow::stopGame() {
	this->start_btn->Text = "START";
	watch->Stop();
	gameStarted = false;
	this->radioButton_player1->Enabled = true;
	this->radioButton_player2->Enabled = true;
}

void TickTacToe::GameWindow::startGame(char player) {
	initArray(circle_table, GAME_SIZE*GAME_SIZE);
	initArray(cross_table, GAME_SIZE*GAME_SIZE);
	this->button1->BackgroundImage = nullptr;
	this->button2->BackgroundImage = nullptr;
	this->button3->BackgroundImage = nullptr;
	this->button4->BackgroundImage = nullptr;
	this->button5->BackgroundImage = nullptr;
	this->button6->BackgroundImage = nullptr;
	this->button7->BackgroundImage = nullptr;
	this->button8->BackgroundImage = nullptr;
	this->button9->BackgroundImage = nullptr;
	round = 0;
	this->player = player;
	this->status_label_player->Text = "player " + (player+1);
	turn = CIRCLE;
	gameStarted = true;
	this->radioButton_player1->Enabled = false;
	this->radioButton_player2->Enabled = false;
	
	watch->Start();
	watch->Restart();
}

bool TickTacToe::GameWindow::isWin(const array<int> ^array) {
	// row, check 0, 3, 6
	for (int i = 0;i < GAME_SIZE*GAME_SIZE; i += GAME_SIZE) {
		int count = 0;
		if (array[i] == 1) {
			count++;
			for (int j = i+1;j < i+GAME_SIZE;j++) {
				if (array[ j] == 1) 
					count++;;
			}
		}
		if (count == GAME_SIZE) return true;
	}
	// col
	for (int i = 0;i < GAME_SIZE; i += 1) {
		int count = 0;
		if (array[i] == 1) {
			count++;
			for (int j = i + GAME_SIZE ;j <= i+(GAME_SIZE-1)*GAME_SIZE;j+= GAME_SIZE) {
				if (array[j] == 1)
					count++;
			}
		}
		if (count == GAME_SIZE) return true;
	}
	// cross line
	if (array[0] == 1) {
		int count = 1;
		for (int i = GAME_SIZE + 1;i <= GAME_SIZE*GAME_SIZE-1 ;i += (GAME_SIZE + 1)) {
			if (array[i] == 1)
				count++;
		}
		if (count == GAME_SIZE) return true;
	}
	if (array[GAME_SIZE-1] == 1) {
		int count = 1;
		for (int i = (GAME_SIZE - 1)+GAME_SIZE - 1;i <= GAME_SIZE*(GAME_SIZE-1);i += (GAME_SIZE - 1)) {
			if (array[i] == 1)
				count++;
		}
		if (count == GAME_SIZE) return true;
	}


	return false;
}

void TickTacToe::GameWindow::changePlayer() {
	player = player==PLAYER_1? PLAYER_2 : PLAYER_1; //toggle
	turn = turn == CIRCLE ? CROSS : CIRCLE;
	this->status_label_player->Text = "player " + (player + 1);
}

void TickTacToe::GameWindow::setImage(Button ^button) {
	button->BackgroundImage = turn == CIRCLE ? circle_img : cross_img;
	button->BackgroundImageLayout = ImageLayout::Stretch;
}

bool  TickTacToe::GameWindow::setTable(int index) {


	if (circle_table[index] == 1 || cross_table[index] ==1) return false;

	turn == CIRCLE ? circle_table[index] = 1 : cross_table[index] = 1;

	return true;
}

void  TickTacToe::GameWindow::Timer_Tick(System::Object^  sender, System::EventArgs^  e) {
	TimeSpan ts = watch->Elapsed;

	// Format and display the TimeSpan value.
	String ^elapsedTime = String::Format("{0:00}:{1:00}:{2:00}.{3:0000}",
		ts.Hours, ts.Minutes, ts.Seconds,
		ts.Milliseconds );
	this->time_label->Text = ""+elapsedTime;
}
