/*
 * =====================================================================================
 *
 *       Filename:  init.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.11.19 22:46:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vovan (), volodumurkoval0@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */



#include "init.h"

extern const tFont* fontMenu;
extern stateElement startState;
extern stateElement settingState;

void InitMain(void)
{
	fontMenu = &Arial7;	
	CurrState = (stateElement*)&startState;
}
