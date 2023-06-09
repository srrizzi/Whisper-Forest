#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<windows.h>

#define ESC 27

int ScreenHeight, ScreenWidth;
int ButtonHeight, ButtonWidth;

void *SpriteL[5];
void *MaskL[5];
void *SpriteR[5];
void *MaskR[5];
void *GhostOne[3];
void *MaskGhostOne[3];
void *GhostTwo[3];
void *MaskGhostTwo[3];
void *GhostThree[4];
void *MaskGhostThree[4];
void *Dialog[21];

void ScreenStart();
void PhaseOne();
void PhaseTwo();
void PhaseThree();
void PhaseEnd();
void Credits();
void* LoadBackground(char* Sprite, int Width, int Height);
void LoadSprits(const char spritesheet[50], void **vetorsprite, int largura_ss, int altura_ss, int largura_sprt, int altura_sprt, int n_linhas, int n_colunas);
void SizeSprits(void *Sprite[], int Width, int Height, int Count);
void* LoadButton(char* Sprite, int Width, int Height);

int main()
{
	ScreenWidth = 1200;
	ScreenHeight = 800;
	ButtonWidth = 250;
	ButtonHeight = 80;
	
	char tecla = 0;
	
	int Size = 0;
	initwindow(1800, 400, "Whisper Forest", 10, 10);
	
	SizeSprits(SpriteL, 200, 200, 5);
	SizeSprits(MaskL, 200, 200, 5);
	SizeSprits(SpriteR, 200, 200, 5);
	SizeSprits(MaskR, 200, 200, 5);
	SizeSprits(GhostOne, 200, 200, 3);
	SizeSprits(MaskGhostOne, 200, 200, 3);
	SizeSprits(GhostTwo, 200, 200, 3);
	SizeSprits(MaskGhostTwo, 200, 200, 3);
	SizeSprits(GhostThree, 200, 200, 4);
	SizeSprits(MaskGhostThree, 200, 200, 4);
	
	LoadSprits(".\\sprite sheet\\FoxLeftS.bmp", MaskL, 1000, 200, 200, 200, 1, 5);
	LoadSprits(".\\sprite sheet\\FoxLeftM.bmp", SpriteL, 1000, 200, 200, 200, 1, 5);
	LoadSprits(".\\sprite sheet\\FoxRightS.bmp", MaskR, 1000, 200, 200, 200, 1, 5);
	LoadSprits(".\\sprite sheet\\FoxRightM.bmp", SpriteR, 1000, 200, 200, 200, 1, 5);
	LoadSprits(".\\sprite sheet\\GhostOneS.bmp", MaskGhostOne, 1200, 200, 200, 200, 1, 3);
	LoadSprits(".\\sprite sheet\\GhostOneM.bmp", GhostOne, 1200, 200, 200, 200, 1, 3);
	LoadSprits(".\\sprite sheet\\GhostTwoS.bmp", MaskGhostTwo, 1400, 200, 200, 200, 1, 3);
	LoadSprits(".\\sprite sheet\\GhostTwoM.bmp", GhostTwo, 1400, 200, 200, 200, 1, 3);
	LoadSprits(".\\sprite sheet\\GhostThreeS.bmp", MaskGhostThree, 1600, 200, 200, 200, 1, 4);
	LoadSprits(".\\sprite sheet\\GhostThreeM.bmp", GhostThree, 1600, 200, 200, 200, 1, 4);	
	
	Dialog[0] = LoadBackground(".\\akane\\akane1.bmp", 1175, 300);
	Dialog[1] = LoadBackground(".\\akane\\akane2.bmp", 1175, 300);
	Dialog[2] = LoadBackground(".\\akane\\akane3.bmp", 1175, 300);
	Dialog[3] = LoadBackground(".\\akane\\akane4.bmp", 1175, 300);
	Dialog[4] = LoadBackground(".\\akane\\akane5.bmp", 1175, 300);
	Dialog[5] = LoadBackground(".\\akane\\akane6.bmp", 1175, 300);
	Dialog[6] = LoadBackground(".\\akane\\akane7.bmp", 1175, 300);
	Dialog[7] = LoadBackground(".\\akane\\akane8.bmp", 1175, 300);
	Dialog[8] = LoadBackground(".\\akane\\akane9.bmp", 1175, 300);
	Dialog[9] = LoadBackground(".\\akane\\akane10.bmp", 1175, 300);
	Dialog[10] = LoadBackground(".\\ryuji\\ryuji1.bmp", 1175, 300);
	Dialog[11] = LoadBackground(".\\ryuji\\ryuji2.bmp", 1175, 300);
	Dialog[12] = LoadBackground(".\\ryuji\\ryuji3.bmp", 1175, 300);
	Dialog[13] = LoadBackground(".\\ryuji\\ryuji4.bmp", 1175, 300);
	Dialog[14] = LoadBackground(".\\ryuji\\ryuji5.bmp", 1175, 300);
	Dialog[15] = LoadBackground(".\\ryuji\\ryuji6.bmp", 1175, 300);
	Dialog[16] = LoadBackground(".\\yuno\\yuno1.bmp", 1175, 300);
	Dialog[17] = LoadBackground(".\\yuno\\yuno2.bmp", 1175, 300);
	Dialog[18] = LoadBackground(".\\yuno\\yuno3.bmp", 1175, 300);
	Dialog[19] = LoadBackground(".\\yuno\\yuno4.bmp", 1175, 300);
	Dialog[20] = LoadBackground(".\\yuno\\yuno5.bmp", 1175, 300);
	
	closegraph();
	
	initwindow(ScreenWidth, ScreenHeight, "Whisper Forest", 10, 10);
	
	ScreenStart();
	
	closegraph();
	return(0);
}

void ScreenStart()
{
	bool End = false;
	int Page = 1;
	POINT P;
	HWND Window;
	
	bool ButtonPlaySelected = false;
	bool ButtonCreditsSelected = false;
	bool ButtonExitSelected = false;
	
	int Size;
	
	void *Background;
	void *ButtonPlay, *ButtonPlaySelect;
	void *ButtonCredits, *ButtonCreditsSelect;
	void *ButtonExit, *ButtonExitSelect;
	
	Background = LoadBackground(".\\image\\Menu.bmp", ScreenWidth, ScreenHeight);

	cleardevice();

	ButtonPlay = LoadButton(".\\button\\start.bmp", ButtonWidth, ButtonHeight);
	ButtonPlaySelect = LoadButton(".\\button\\startSel.bmp", ButtonWidth, ButtonHeight);
	ButtonCredits = LoadButton(".\\button\\credits.bmp", ButtonWidth, ButtonHeight);
	ButtonCreditsSelect = LoadButton(".\\button\\creditsSel.bmp", ButtonWidth, ButtonHeight);
	ButtonExit = LoadButton(".\\button\\exit.bmp", ButtonWidth, ButtonHeight);
	ButtonExitSelect = LoadButton(".\\button\\exitSel.bmp", ButtonWidth, ButtonHeight);
	
	Window = GetForegroundWindow();
	
	while(!End)
	{
		if(Page == 1) Page = 2; else Page = 1;
		setactivepage(Page);
		
		putimage(0, 0, Background, COPY_PUT);
		
		if(ButtonPlaySelected) putimage(475, 700, ButtonPlaySelect, COPY_PUT);
		else putimage(475, 700, ButtonPlay, COPY_PUT);
		
		if(ButtonCreditsSelected) putimage(875, 700, ButtonCreditsSelect, COPY_PUT);
		else putimage(875, 700, ButtonCredits, COPY_PUT);
		
		if(ButtonExitSelected) putimage(75, 700, ButtonExitSelect, COPY_PUT);
		else putimage(75, 700, ButtonExit, COPY_PUT);
		
		setvisualpage(Page);
		
		if(GetCursorPos(&P))
			if(ScreenToClient(Window, &P))
			{
				ButtonPlaySelected = false;
				if(475 <= P.x && P.x <= 475 + ButtonWidth-1 && 700 <= P.y && P.y <= 700 + ButtonHeight-1) ButtonPlaySelected = true;
				
				ButtonCreditsSelected = false;
				if(875 <= P.x && P.x <= 875 + ButtonWidth-1 && 700 <= P.y && P.y <=  700 + ButtonHeight-1) ButtonCreditsSelected = true;
					
				ButtonExitSelected = false;
				if(75 <= P.x && P.x <= 75 + ButtonWidth-1 && 700 <= P.y && P.y <=  700 + ButtonHeight-1) ButtonExitSelected = true;
			
				if(GetKeyState(VK_LBUTTON)&0X80)
				{
					if(475 <= P.x && P.x <= 475 + ButtonWidth-1 && 700 <= P.y && P.y <=  700 + ScreenHeight-1)
					{
						PhaseOne();
					}

					else if(875 <= P.x && P.x <= 875 + ButtonWidth-1 && 700 <= P.y && P.y <=  700 + ScreenHeight-1)
					{
						Credits();
					}
					else if(75 <= P.x && P.x <= 75 + ButtonWidth-1 && 700 <= P.y && P.y <=  700 + ScreenHeight-1)
						End = true;
				}
			}
	}
}

void Credits()
{
	char Key = 0;
	void *Background;
	bool End = false;
	int page = 1;
	
	Background = LoadBackground(".\\image\\credits.bmp", ScreenWidth, ScreenHeight);
	
	mciSendString("open .\\song\\click.mp3 type MPEGVideo alias Button", NULL, 0, 0);
	waveOutSetVolume(0,0xffffffff);
	mciSendString("play Button", NULL, 0, 0);
	
	while (!End)
	{
		if(page == 1) page = 2; else page = 1;
		setactivepage(page);
		putimage(0, 0,Background, COPY_PUT);
		setvisualpage(page);
		if(kbhit())
		{
			Key = getch();
			if(Key == ESC) End = true;
		}
	}
	mciSendString("stop Button", NULL, 0, 0);
}

void PhaseOne()
{
	int Size;
	void *Background;
	bool End = false;
	int x = 0;
	
	double countTime = 0;
	int countTest = 0;
	int countMoviment = 0;
	double countSprite = 0;
	
	int page = 1;
	char Key = 0;
	bool Ghost = true;
	int CurrentDialog = 0;
	
	mciSendString("open .\\song\\musicgame.mp3 type MPEGVideo alias MusicGame", NULL, 0, 0);
	waveOutSetVolume(0,0xffffffff);
	mciSendString("play MusicGame repeat", NULL, 0, 0);
	
	Background = LoadBackground(".\\image\\Scenario.bmp", ScreenWidth, ScreenHeight);
			
	while (!End)
	{
		if(page == 1) page = 2; else page = 1;
		setactivepage(page);
		cleardevice();
		
		if(Ghost)
		{
			putimage(0, 0, Background, COPY_PUT);
		
			putimage(1000, 444, GhostOne[countTest], AND_PUT);
			putimage(1000, 444, MaskGhostOne[countTest], OR_PUT);			
		
			countTime += 0.2;
			if(countTime > 5)
			{
				countTest++;
				countTime = 0;
			}
			if(countTest >= 3)
				countTest = 0;
		}
		
		if(GetKeyState(VK_RIGHT)&0x80)
		{
			putimage(x, 444, SpriteR[countMoviment], AND_PUT);
			putimage(x, 444, MaskR[countMoviment], OR_PUT);
			
			x += 1;
			
			countSprite += 0.2;
			if(countSprite > 3.6)
			{
				countMoviment++;
				countSprite = 0;
			}
			if(countMoviment >= 5)
				countMoviment = 0;
		}		
		else if(GetKeyState(VK_LEFT)&0x80)
		{

			putimage(x, 444, SpriteL[countMoviment], AND_PUT);
			putimage(x, 444, MaskL[countMoviment], OR_PUT);
			
			x -= 1;
			countSprite += 0.2;
			if(countSprite > 3.6)
			{
				countMoviment++;
				countSprite = 0;
			}
			if(countMoviment >= 5)
				countMoviment = 0;
		}
		else 
		{
			putimage(x, 444, SpriteR[0], AND_PUT);
			putimage(x, 444, MaskR[0], OR_PUT);
		}
		
		if(x >= 800)
		{
			putimage(10, 10 , Dialog[CurrentDialog], COPY_PUT);
			if(GetKeyState(VK_SPACE)&0x80)
			{
				CurrentDialog++;
				if(CurrentDialog == 10)
					PhaseTwo();
				delay(300);
			}
		}
		
		setvisualpage(page);
		if(kbhit())
		{
			Key = getch();
			if(Key == ESC) End = true;
		}
	}
	mciSendString("stop MusicGame", NULL, 0, 0);
}

void PhaseTwo()
{
	int Size;
	void *Background;
	bool End = false;
	int x = 0;
	
	double countTime = 0;
	int countTest = 0;
	int countMoviment = 0;
	double countSprite = 0;
	
	int page = 1;
	char Key = 0;
	bool Ghost = true;
	int CurrentDialog = 10;
	
	mciSendString("open .\\song\\musicgame.mp3 type MPEGVideo alias MusicGame", NULL, 0, 0);
	waveOutSetVolume(0,0xffffffff);
	mciSendString("play MusicGame repeat", NULL, 0, 0);
	
	Background = LoadBackground(".\\image\\Scenario.bmp", ScreenWidth, ScreenHeight);
			
	while (!End)
	{
		if(page == 1) page = 2; else page = 1;
		setactivepage(page);
		cleardevice();
		
		if(Ghost)
		{
			putimage(0, 0, Background, COPY_PUT);
		
			putimage(1000, 444, GhostTwo[countTest], AND_PUT);
			putimage(1000, 444, MaskGhostTwo[countTest], OR_PUT);
		
			countTime += 0.2;
			if(countTime > 5)
			{
				countTest++;
				countTime = 0;
			}
			if(countTest >= 3)
				countTest = 0;
		}

		if(GetKeyState(VK_RIGHT)&0x80)
		{
			putimage(x, 444, SpriteR[countMoviment], AND_PUT);
			putimage(x, 444, MaskR[countMoviment], OR_PUT);
			
			x += 1;
			
			countSprite += 0.2;
			if(countSprite > 3.6)
			{
				countMoviment++;
				countSprite = 0;
			}
			if(countMoviment >= 5)
				countMoviment = 0;
		}		
		else if(GetKeyState(VK_LEFT)&0x80)
		{

			putimage(x, 444, SpriteL[countMoviment], AND_PUT);
			putimage(x, 444, MaskL[countMoviment], OR_PUT);
			
			x -= 1;
			
			countSprite += 0.2;
			if(countSprite > 3.6)
			{
				countMoviment++;
				countSprite = 0;
			}
			if(countMoviment >= 5)
				countMoviment = 0;
		}
		else 
		{
			putimage(x, 444, SpriteR[0], AND_PUT);
			putimage(x, 444, MaskR[0], OR_PUT);
		}
		
		if(x >= 800)
		{
			putimage(10, 10 , Dialog[CurrentDialog], COPY_PUT);
			if(GetKeyState(VK_SPACE)&0x80)
			{
				CurrentDialog++;
				if(CurrentDialog == 16)
					PhaseThree();
				delay(300);
			}	
		}			
		setvisualpage(page);
		if(kbhit())
		{
			Key = getch();
			if(Key == ESC) End = true;
		}
	}
	mciSendString("stop MusicGame", NULL, 0, 0);
}

void PhaseThree()
{
	int Size;
	void *Background;
	bool End = false;
	int x = 0;
	
	double countTime = 0;
	int countTest = 0;
	int countMoviment = 0;
	double countSprite = 0;
	
	int page = 1;
	char Key = 0;
	bool Ghost = true;
	int CurrentDialog = 16;
	
	mciSendString("open .\\song\\musicgame.mp3 type MPEGVideo alias MusicGame", NULL, 0, 0);
	waveOutSetVolume(0,0xffffffff);
	mciSendString("play MusicGame repeat", NULL, 0, 0);
	
	Background = LoadBackground(".\\image\\Scenario.bmp", ScreenWidth, ScreenHeight);
			
	while (!End)
	{
		if(page == 1) page = 2; else page = 1;
		setactivepage(page);
		cleardevice();
		
		if(Ghost)
		{
			putimage(0, 0, Background, COPY_PUT);
		
			putimage(1000, 444, GhostThree[countTest], AND_PUT);
			putimage(1000, 444, MaskGhostThree[countTest], OR_PUT);

			countTime += 0.2;
			if(countTime > 5)
			{
				countTest++;
				countTime = 0;
			}
			if(countTest >= 4)
				countTest = 0;
		}
		
		if(GetKeyState(VK_RIGHT)&0x80)
		{
			putimage(x, 444, SpriteR[countMoviment], AND_PUT);
			putimage(x, 444, MaskR[countMoviment], OR_PUT);
			
			x += 1;
			
			countSprite += 0.2;
			if(countSprite > 3.6)
			{
				countMoviment++;
				countSprite = 0;
			}
			if(countMoviment >= 5)
				countMoviment = 0;
		}		
		else if(GetKeyState(VK_LEFT)&0x80)
		{

			putimage(x, 444, SpriteL[countMoviment], AND_PUT);
			putimage(x, 444, MaskL[countMoviment], OR_PUT);
			
			x -= 1;
			countSprite += 0.2;
			if(countSprite > 3.6)
			{
				countMoviment++;
				countSprite = 0;
			}
			if(countMoviment >= 5)
				countMoviment = 0;
		}
		else 
		{
			putimage(x, 444, SpriteR[0], AND_PUT);
			putimage(x, 444, MaskR[0], OR_PUT);
		}
			
		if(x >= 800)
		{
			putimage(10, 10 , Dialog[CurrentDialog], COPY_PUT);
			if(GetKeyState(VK_SPACE)&0x80)
			{
				CurrentDialog++;
				if(CurrentDialog == 21)
					PhaseEnd();
				delay(300);
			}
		}			
		setvisualpage(page);
		if(kbhit())
		{
			Key = getch();
			if(Key == ESC) End = true;
		}
	}
	mciSendString("stop MusicGame", NULL, 0, 0);
}

void PhaseEnd()
{
	char Key = 0;
	void *Background;
	bool End = false;
	int page = 1;
	
	Background = LoadBackground(".\\image\\end.bmp", ScreenWidth, ScreenHeight);
	
	while (!End)
	{
		if(page == 1) page = 2; else page = 1;
		setactivepage(page);
		putimage(0, 0,Background, COPY_PUT);
		setvisualpage(page);
		if(kbhit())
		{
			Key = getch();
			if(Key == ESC) ScreenStart();
		}
	}
}

void* LoadBackground(char* Sprite, int Width, int Height)
{
	int size = imagesize(0, 0, Width-1, Height-1);
	
	void* Memory = malloc(size);
	readimagefile(Sprite, 0, 0, Width-1, Height-1);
	getimage(0, 0, Width-1, Height-1, Memory);
	
	cleardevice();
	return Memory;
}

void* LoadButton(char* Sprite, int Width, int Height)
{
	int size = imagesize(0, 0, Width-1, Height-1);
	
	void* Memory = malloc(size);
	readimagefile(Sprite, 0, 0, Width-1, Height-1);
	getimage(10, 11, 240, 70, Memory);
	
	cleardevice();
	return Memory;
}

void SizeSprits(void *Sprite[], int Width, int Height, int Count)
{
	
	int Size = imagesize(0, 0, Width-1, Height-1);
	for(int i = 0; i < Count; i++)
	{
		Sprite[i] = malloc(Size);
	}
}

void LoadSprits(const char spritesheet[50], void **vetorsprite, int largura_ss, int altura_ss, int largura_sprt, int altura_sprt, int n_linhas, int n_colunas)
{
	int linha, coluna;
	readimagefile(spritesheet, 0, 0, (largura_ss - 1), (altura_ss - 1)); // carrega a imagem no programa
    for (linha = 0; linha < n_linhas; linha++)
      for (coluna = 0; coluna < n_colunas; coluna++)
        getimage(coluna * largura_sprt, linha * altura_sprt, (coluna + 1) * largura_sprt - 1, (linha + 1) * altura_sprt - 1, vetorsprite[linha * n_colunas + coluna]);
}
