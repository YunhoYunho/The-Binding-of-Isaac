#pragma once

#include "resource.h"

//========================================
//##    전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			윈도우 설정				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			게임씬 그룹				##
//========================================

enum class GroupScene
{
	Title,

	TileTool,

	Loading,

	Stage01,

	Size,
};

//========================================
//##				레이어				##
//========================================

enum class Layer
{
	Default,
	Tile,
	Ending,
	Loading,
	Title,
	GroundTile,
	Obstacle,
	Door,
	Missile,
	Monster,
	MonsterMissile,
	Player,
	PlayerMissile,
	ItemRock,
	Item,

	HUD,
	Ui,
	Size,
};

//========================================
//##				타일					##
//========================================

enum class TypeTile
{
	None,
	Ground,
	Platform,
	Wall,
	door,

	Size,
};

//========================================
//##				상태				##
//========================================

enum class PlayerState
{
	Idle,
	Move,
	Shot,
	TakeHit,
	Dead,

	Size,
};

enum class MonsterState
{
	Idle,
	Move,
	Jump,
	Shot,
	Dead,

	Size,
};
