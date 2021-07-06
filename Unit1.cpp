//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


int x = -10;
int y = -10;
int leftPlayerPoints =0 ;
int rightPlayerPoints = 0;
int bounceCounter =0;
int currentBounceCount = -2;





//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
AnsiString hello = "Witaj w grze PingPong.";
AnsiString left = "Lewy gracz steruje wciskaj¹c klawisze A oraz Z" ;
AnsiString right = "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.";
AnsiString l3 = "Dla urozmaicenia zabawy:";
AnsiString l4 = "Kiedy odbijesz pi³eczkê na œrodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyœpieszy.";
AnsiString l5 = "Im d³u¿ej odbijasz, tym pi³ka szybciej siê przemieszcza." ;
AnsiString l6 = "Mi³ej zabawy!";
ShowMessage( hello + sLineBreak+sLineBreak + left + sLineBreak +right+sLineBreak+sLineBreak+l3+sLineBreak+l4+sLineBreak+l5+
sLineBreak+sLineBreak+l6);

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
  if(Ball -> Left + Ball->Width <= LeftPaddle->Left)
  {
  rightPlayerPoints++;
  x=-x;
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
  if(rightPlayerPoints >0 || leftPlayerPoints >0)
  {
  Button1 ->Caption = "Nastêpna runda";
  Form1 ->Button1 ->Font->Color=clGreen;
  Button1 ->Visible =true;
  }
  Button2 ->Visible = true;
  }
 else if ((Ball -> Top  > LeftPaddle -> Top -20) &&
 (Ball -> Top <LeftPaddle -> Top + LeftPaddle->Height -20  ) &&
 (Ball ->Left < LeftPaddle -> Left + LeftPaddle->Width) )
  {
  if (x<0)
  {
  x = -x;
  bounceCounter++;
  }
  if (bounceCounter  == currentBounceCount +2)
  {
  if(x>0)
  x=10;
  if (x<0)
  x=-10;
  }
  if ((Ball ->Top +20< LeftPaddle -> Top + 115)&&(Ball ->Top +20> LeftPaddle ->Top +85))
 {

    if (x<0)
    x= -25;
    if (x>0)
    x= 25;
    currentBounceCount = bounceCounter;

  }
  }


  //odbicie lub skucha od prawej paletki
  if(Ball -> Left + Ball -> Width >= RightPaddle->Left +RightPaddle->Width)
  {
  leftPlayerPoints++;
  x=-x;
  BallTimer -> Enabled = false;
  Ball-> Visible = false;
  Info ->Caption = "< Punkt dla gracza lewego";
  Info ->Visible = true;
  AnsiString l = IntToStr(leftPlayerPoints) ;
  AnsiString r = IntToStr(rightPlayerPoints) ;
  points ->Caption = l + ":" + r;
  points ->Visible = true;
  AnsiString b = IntToStr(bounceCounter);
  label1 ->Caption = "Iloœæ odbiæ: " + b;
  label1 ->Visible = true;
   if(rightPlayerPoints >0 || leftPlayerPoints >0)
  {
  Button1 ->Caption = "Nastêpna runda";
 Form1 -> Button1 ->Font->Color=clGreen;
  Button1 ->Visible =true;
  }
  Button2 ->Visible = true;
  }
  else if ((Ball -> Top > RightPaddle -> Top -20) &&
  (Ball -> Top <RightPaddle -> Top + RightPaddle->Height -20 ) &&
  (Ball ->Left > RightPaddle -> Left - Ball->Width) )
  {
  if (x >0)
  {
  x = -x;
  bounceCounter++;

  }
  if (bounceCounter  == currentBounceCount +2)
  {
  if(x>0)
  x=10;
  if (x<0)
  x=-10;
  }
  if ((Ball ->Top +20 < RightPaddle -> Top + 115)&&(Ball ->Top +20 > RightPaddle ->Top +85))
 {

     if (x<0)
    x= -25;
    if (x>0)
    x= 25;
     currentBounceCount = bounceCounter ;
  }
  }
  int increaseSpeed;

  increaseSpeed = bounceCounter /5;
  if(increaseSpeed==1)
  {
      BallTimer->Interval = 19;
  }
  if(increaseSpeed==2)
  {
    BallTimer->Interval = 18;
  }
  if(increaseSpeed==3)
  {
     BallTimer->Interval = 17;
  }
  if(increaseSpeed==4)
  {
     BallTimer->Interval = 16;
  }
  if(increaseSpeed==5)
  {
     BallTimer->Interval = 15;
  }

  }




//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleUpTimer(TObject *Sender)
{
  if (LeftPaddle -> Top >10) LeftPaddle ->Top -=15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPaddleDownTimer(TObject *Sender)
{
 if(LeftPaddle ->Top + LeftPaddle->Height < tlo ->Height -10) LeftPaddle ->Top +=15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleUpTimer(TObject *Sender)
{
   if (RightPaddle -> Top >10) RightPaddle ->Top -=15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPaddleDownTimer(TObject *Sender)
{
    if(RightPaddle -> Top +RightPaddle ->Height < tlo ->Height -10) RightPaddle ->Top +=15;
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
    x=-10; y=-10;
    BallTimer ->Enabled = true;
    Button1 ->Visible = false;
    Button2->Visible = false;
    Info ->Visible = false;
    points -> Visible = false;
    label1 ->Visible = false;
    BallTimer->Interval=20;

    bounceCounter =0;
}
//-----------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Ball -> Left = tlo->Width /2;
    Ball -> Top = tlo ->Height /2;
    LeftPaddle ->Left = tlo ->Left + 40;
    LeftPaddle ->Top = tlo->Height/2 - LeftPaddle->Height/2;
  RightPaddle ->Left = tlo ->Width -40 - RightPaddle ->Width;
  RightPaddle ->Top = tlo->Height/2 - RightPaddle->Height/2;
    Ball ->Visible = true;
    x=-10; y=-10;
    BallTimer ->Enabled = true;
    Button1 ->Visible = false;
    Button2->Visible = false;
    Info ->Visible = false;
    points -> Visible = false;
    label1 ->Visible = false;
    leftPlayerPoints =0 ;
    rightPlayerPoints = 0;
    BallTimer->Interval=20;
    bounceCounter =0;
}
//---------------------------------------------------------------------------




