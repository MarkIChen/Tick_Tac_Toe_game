/**************************************
* Copyright(c) 2019 ICheng Chen ³¯©ö¦¨ E14046583
* All rights reserved.
***************************************/
#include "stdafx.h"
#include "GameWindow.h"

using namespace System;
using namespace Tick_TacTow4x4;

void GameWindow::initArray(array<int> ^array, int size)
{
	for (int i = 0;i < size;i++) {
		array[i] = 0;
	}
}

void GameWindow::checkWinner() {
	if (player == first_player) {
		if (isWin(circle_table) == true) {
			stopGame();
			System::Windows::Forms::MessageBox::Show("Player " + (first_player + 1) + "  Win");
			watch->Stop();
			return;
		}
	}
	else {
		if (isWin(cross_table) == true) {
			stopGame();
			System::Windows::Forms::MessageBox::Show("Player " + (!first_player + 1) + "  Win");
			watch->Stop();
			return;
		}
	}

	if (round == GAME_SIZE * GAME_SIZE) {
		stopGame();
		System::Windows::Forms::MessageBox::Show("EVEN, restart game.");
		watch->Stop();
	}
}

void GameWindow::stopGame() {
	this->start_btn->Text = "START";
	watch->Stop();
	gameStarted = false;
	this->radioButton_player1->Enabled = true;
	this->radioButton_player2->Enabled = true;
}

void GameWindow::startGame(char player) {
	initArray(circle_table, GAME_SIZE*GAME_SIZE);
	initArray(cross_table, GAME_SIZE*GAME_SIZE);
	this->draw_area1->Invalidate();
	this->draw_area2->Invalidate();
	this->draw_area3->Invalidate();
	this->draw_area4->Invalidate();
	this->draw_area5->Invalidate();
	this->draw_area6->Invalidate();
	this->draw_area7->Invalidate();
	this->draw_area8->Invalidate();
	this->draw_area9->Invalidate();
	this->draw_area10->Invalidate();
	this->draw_area11->Invalidate();
	this->draw_area12->Invalidate();
	this->draw_area13->Invalidate();
	this->draw_area14->Invalidate();
	this->draw_area15->Invalidate();
	this->draw_area16->Invalidate();

	round = 0;
	this->player = player;
	this->first_player = player;
	this->status_label_player->Text = "player " + (player + 1);
	turn = CIRCLE;
	gameStarted = true;
	this->radioButton_player1->Enabled = false;
	this->radioButton_player2->Enabled = false;

	watch->Start();
	watch->Restart();
}

bool GameWindow::isWin(const array<int> ^array) {
	// row, check 0, 3, 6
	for (int i = 0;i < GAME_SIZE*GAME_SIZE; i += GAME_SIZE) {
		int count = 0;
		if (array[i] == 1) {
			count++;
			for (int j = i + 1;j < i + GAME_SIZE;j++) {
				if (array[j] == 1)
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
			for (int j = i + GAME_SIZE;j <= i + (GAME_SIZE - 1)*GAME_SIZE;j += GAME_SIZE) {
				if (array[j] == 1)
					count++;
			}
		}
		if (count == GAME_SIZE) return true;
	}
	// cross line
	if (array[0] == 1) {
		int count = 1;
		for (int i = GAME_SIZE + 1;i <= GAME_SIZE*GAME_SIZE - 1;i += (GAME_SIZE + 1)) {
			if (array[i] == 1)
				count++;
		}
		if (count == GAME_SIZE) return true;
	}
	if (array[GAME_SIZE - 1] == 1) {
		int count = 1;
		for (int i = (GAME_SIZE - 1) + GAME_SIZE - 1;i <= GAME_SIZE*(GAME_SIZE - 1);i += (GAME_SIZE - 1)) {
			if (array[i] == 1)
				count++;
		}
		if (count == GAME_SIZE) return true;
	}


	return false;
}

void GameWindow::changePlayer() {
	player = player == PLAYER_1 ? PLAYER_2 : PLAYER_1; //toggle
	turn = turn == CIRCLE ? CROSS : CIRCLE;
	this->status_label_player->Text = "player " + (player + 1);
}



bool GameWindow::setTable(int index) {
	// the area has already been drawn
	if (circle_table[index] == 1 || cross_table[index] == 1) return false;

	turn == CIRCLE ? circle_table[index] = 1 : cross_table[index] = 1;

	return true;
}

void  GameWindow::Timer_Tick(System::Object^  sender, System::EventArgs^  e) {
	TimeSpan ts = watch->Elapsed;

	// Format and display the TimeSpan value.
	String ^elapsedTime = String::Format("{0:00}:{1:00}:{2:00}.{3:0000}",
		ts.Hours, ts.Minutes, ts.Seconds,
		ts.Milliseconds);
	this->time_label->Text = "" + elapsedTime;
}
