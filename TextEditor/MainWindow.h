#pragma once
#ifndef MainWindow_H
#define MainWindow_H
#include <iostream> // cout
#include <string> 
#include <cstdlib> // exit function
using namespace std;
//global variables 
int changed = 0;
char filename[256] = "";
F1_Text_Buffer* textbuf; //class buffer

class EditorWindow : public F1_Double_Window {
public:
	EditorWindow(int w, int h, const char* t); //default const
	~EditorWindow();							//deconstructor

	F1_Window* replace dgl;
	F1_Input* replace find;
	F1_Input* replace with;
	F1_Button* replace all;
	F1_Return_Button* replace_next;
	F1_Button* replace cancel;

	F1_Text_Editor* editor;
	char search[256];
};



F1_Menu_Item menuitems[] = {





};



#endif
