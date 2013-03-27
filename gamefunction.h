#ifndef _GAMEFUNCTION_H_
#define _GAMEFUNCTION_H_

void Draw();
void Move( int _x, int _y );
void MoveCursor( int _x, int _y );
void Popup( char _message[] );
void LoadData( char _fileName[] );

#endif //_GAMEFUNCTION_H_