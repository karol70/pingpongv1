//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;
int leftPlayerPoints =0 ;
int rightPlayerPoints = 0;
int bounceCounter =0;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
  Ball -> Left +=x;
  Ball -> Top +=y;
  LeftPaddle ->Left = tlo ->Left + 40;
  RightPaddle ->Left = tlo ->Width -40 - RightPaddle ->Width;


  //odbij od górnej sciany

  if (Ball ->Top -5 <= tlo->Top) y=-y;

  //odbij od dolnej sciany

  if (Ball -> Top + Ball ->Height +5  >= tlo -> Top  + tlo ->Height ) y = -y;

  //odbicie lub skucha od lewej paletki
  if(Ball -> Left <= LeftPaddle->Left - Ball->Width+15)
  {
  rightPlayerPoints++;
  BallTimer -> Enabled = false;
  Ball-> Visible = false;
  Info ->Caption = "Punkt dla gracza prawego >";
  Info ->Visible = true;
  AnsiString l = IntToStr(leftPlayerPoints) ;
  AnsiString r = IntToStr(rightPlayerPoints) ;
  points ->Caption = l + ":" + r;
  points ->Visible = true;
  AnsiString b = IntToStr(bounceCounter);
  label1 ->Caption = "Bounce Count: " + b;
  label1 ->Visible = true;
  Button1 ->Caption = "Nowa gra";
  Button1 ->Visible =true;
  }
  if (Ball -> Top > LeftPaddle -> Top - Ball -> Height/2 && Ball -> Top <
  LeftPaddle -> Top + LeftPaddle->Height + Ball ->Height /2 && Ball ->Left == LeftPaddle -> Left + LeftPaddle->Width )
  {
  x = -x;
  bounceCounter++;
   }
  //odbicie lub skucha od prawej paletki
  if(Ball -> Left >= RightPaddle->Left + RightPaddle->Width + 15)
  {
  leftPlayerPoints++;
  BallTimer -> Enabled = false;
  Ball-> Visible = false;
  Info ->Caption = "< Punkt dla gracza lewego";
  Info ->Visible = true;
  AnsiString l = IntToStr(leftPlayerPoints) ;
  AnsiString r = IntToStr(rightPlayerPoints) ;
  points ->Caption = l + ":" + r;
  points ->Visible = true;
  AnsiString b = IntToStr(bounceCounter);
  label1 ->Caption = "Bounce Count: " + b;
  label1 ->Visible = true;
  Button1 ->Caption = "Nowa gra";
  Button1 ->Visible =true;
  }
  if (Ball -> Top > RightPaddle -> Top - Ball -> Height/2 && Ball -> Top <
  RightPaddle -> Top + RightPaddle->Height + Ball ->Height /2 && Ball ->Left == RightPaddle -> Left - Ball->Width )
  {

  x = -x;
  bounceCounter++;

  }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleUpTimer(TObject *Sender)
{
  if (LeftPaddle -> Top >10) LeftPaddle ->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleDownTimer(TObject *Sender)
{
 if(LeftPaddle ->Top + LeftPaddle->Height < tlo ->Height -10) LeftPaddle ->Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleUpTimer(TObject *Sender)
{
   if (RightPaddle -> Top >10) RightPaddle ->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleDownTimer(TObject *Sender)
{
    if(RightPaddle -> Top +RightPaddle ->Height < tlo ->Height -10) RightPaddle ->Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_DOWN) RightPaddleDown ->Enabled = true;
        if(Key == VK_UP) RightPaddleUp ->Enabled = true;
        if(Key == 65) LeftPaddleUp ->Enabled = true;
        if(Key == 90) LeftPaddleDown ->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if(Key == VK_DOWN) RightPaddleDown ->Enabled = false;
        if(Key == VK_UP) RightPaddleUp ->Enabled = false;
        if(Key == 65) LeftPaddleUp ->Enabled = false;
        if(Key == 90) LeftPaddleDown ->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

    Ball -> Left = tlo->Width /2;
    Ball -> Top = tlo ->Height /2;
    LeftPaddle ->Left = tlo ->Left + 40;
    LeftPaddle ->Top = tlo->Height/2 - LeftPaddle->Height/2;
  RightPaddle ->Left = tlo ->Width -40 - RightPaddle ->Width;
  RightPaddle ->Top = tlo->Height/2 - RightPaddle->Height/2;
    Ball ->Visible = true;
    x=-8; y=-8;
    BallTimer ->Enabled = true;
    Button1 ->Visible = false;
    Info ->Visible = false;
    points -> Visible = false;
    label1 ->Visible = false;

    bounceCounter =0;
}
//---------------------------------------------------------------------------
