#ifndef APIGRAFICA_H 
#define APIGRAFICA_H

#include "PCD8544.h"

#define MAX_ITEM_MENU 3
#define MAX_ITEM_BUT 2
#define MAX_MENUS 1
#define TRUE 1
#define FALSE 0

struct item_pcd8544
{
  char TEXT[20]; 
};

typedef struct item_pcd8544 ITEM_PCD8544; 

struct menu_pcd8544
{
    byte count;
    char title[20];
    char iTemSelected;
    byte enableBtns;//0 - sem btn, 1 - esq, 2 - esq e direito
};

typedef struct menu_pcd8544 MENU_PCD8544;

class APIGrafica 
{
  
public:
  APIGrafica(PCD8544 n);

  void createMenu(char* title, byte nItems);
  void setTitleMenu(char * text);
  void setItem(byte itemID, char * text);
  void setTextLeftBTN(char * text);
  void setTextRightBTN(char * text);
  void removeAllBTN(char * text);
  void nextItem();
  void previousItem();
  
  void selItem(byte idItem);
  byte getSelItem();
  void unselAll();

  void updateDisplay();
  void clearDisplay();
  void drawMenu();
 
  
private:
  PCD8544 nokia;
  MENU_PCD8544 menu;
  ITEM_PCD8544 itemMenu[MAX_ITEM_MENU];
  ITEM_PCD8544 itemButton[MAX_ITEM_BUT];
  void drawItemMenu(byte x, byte y, char * text, byte selected);
  void drawTitleMenu();
  void drawButtons();
  void drawItens();
  
};

#endif
