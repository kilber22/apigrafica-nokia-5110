#include "APIGrafica.h"

APIGrafica::APIGrafica(PCD8544 n):
nokia(n)
{

}

void APIGrafica::updateDisplay()
{
  nokia.display();
}

void APIGrafica::clearDisplay()
{
  nokia.clear();
}

void APIGrafica::setItem(byte itemID, char * text)
{
  strcpy(itemMenu[itemID].TEXT,text);
}

void APIGrafica::createMenu(char* title, byte nItems)
{
  menu.count = nItems;
  strcpy(menu.title,title);
  menu.iTemSelected = -1;

}
  
void APIGrafica::drawMenu()
{
  drawTitleMenu();

  drawItens();
  
  drawButtons();
 
}

void APIGrafica::drawItens()
{
  byte inc = 9;//Espaco entre os itens - eixo y
  byte tmp;
  byte cons = 12;//Inicio do primeiro item - eixo y
  for(byte i = 0; i < menu.count; i++)
  {
    tmp = inc * i;
    if(menu.iTemSelected == i)
      drawItemMenu(5,cons+tmp,itemMenu[i].TEXT,TRUE);
    else
      drawItemMenu(5,cons+tmp,itemMenu[i].TEXT,FALSE);  
      
  }
}

void APIGrafica::drawButtons()
{
  //desenhando botao do lado esquerdo
  if(menu.enableBtns == 1)
  {
     nokia.setTextColor(BLACK);
     nokia.drawrect(0,38,41,10,BLACK);
     nokia.drawstring(2,39,itemButton[0].TEXT);
  }
  //desenhando os dois botoes
  else if(menu.enableBtns == 2)
  {
     nokia.setTextColor(BLACK);
     nokia.drawrect(0,38,41,10,BLACK);
     nokia.drawstring(2,39,itemButton[0].TEXT);
    
     nokia.setTextColor(BLACK);
     nokia.drawrect(42,38,41,10,BLACK);
     nokia.drawstring(44,39,itemButton[1].TEXT);
  }
  
}

void APIGrafica::drawTitleMenu()
{
    nokia.setTextColor(BLACK);
    nokia.drawrect(0,0,LCDWIDTH,11,BLACK);
    nokia.drawstring(3,2,menu.title);
}
  
  
void APIGrafica::drawItemMenu(byte x, byte y, char * text, byte selected)
{
  nokia.setTextColor(BLACK);
  if(selected == TRUE)
    nokia.setTextColor(WHITE);
  nokia.drawstring(x,y,text);
}

byte APIGrafica::getSelItem()
{
  return menu.iTemSelected;
}

void APIGrafica::selItem(byte idItem)
{
  menu.iTemSelected = idItem;
}


void APIGrafica::unselAll()
{
  menu.iTemSelected = -1;  
}

void APIGrafica::setTitleMenu(char * text)
{
  strcpy(menu.title,text);  
}

void APIGrafica::setTextLeftBTN(char * text)
{
  strcpy(itemButton[0].TEXT,text);
  menu.enableBtns = 1;
}

void APIGrafica::setTextRightBTN(char * text)
{
  strcpy(itemButton[1].TEXT,text);
  menu.enableBtns = 2;
}

void APIGrafica::removeAllBTN(char * text)
{
  menu.enableBtns = 0;
}

void APIGrafica::nextItem()
{
  menu.iTemSelected++;
  
  if(menu.iTemSelected == menu.count)
    menu.iTemSelected = 0;
}

void APIGrafica::previousItem()
{
  menu.iTemSelected = menu.iTemSelected -1;
  
  if(menu.iTemSelected < 0)
    menu.iTemSelected = 2;//menu.count-1;
}
