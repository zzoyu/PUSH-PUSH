#ifndef _INITIALIZE_H_
#define _INITIALIZE_H_

void Initialize();
int MainScreen();
void SelectLevel();
void GameStart( char _levelName[] );
void Help();
void Credit();
void ColorChange( char _string[], char _variable[], int _color );
void MoveCursor( int _x, int _y );

#endif //_INITIALIZE_H_