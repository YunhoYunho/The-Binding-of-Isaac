#pragma once
#include "CScene.h"

class CPlayer;
class CMonster;
class CPassiveItem;
class CEndingChest;

class CSceneStage01 : public CScene
{
public:
	CSceneStage01();
	virtual ~CSceneStage01();

private:
	CPlayer* pPlayer;
	CMonster* pMonster;
	CPassiveItem* pPassiveItem;
	CEndingChest* pEndingChest;
	CGameObject* pCreateItem;
	CSound* pBGMSound;
	CSound* pBossRoomSound;
	CSound* pBossClearSound;
	CSound* pCurSound;

	void PlayBGM(CSound* sound, float volume, bool loop);
	void MonsterPool();
	void PositionPool();
	void ItemPool();

	void CreateDoorTeleport();
	void CreateDoorBossTeleport();
	void CreateRock();
	void CreateItem();
	void CreateMonsters(int num);
	void CreateBoss();
	void CreateEndingChest();
	void SpawnRoom();
	void StartBossLoading();
	void StartBossSound();
	void CheckRoomClear();
	void WhatRoomClear();
	void CreateItems();

	vector<CPassiveItem*> m_vecItems;
	vector<CMonster*> m_vecMonsters;
	vector<CMonster*> m_vecSpawnMonsters;
	vector<Vector> m_vecMonsterPositions;
	vector<Vector> m_vecRockPositions;
	vector<Vector> m_vecTeleportPositions;
	vector<Vector> m_vecItemPositions;
	vector<CGameObject*> m_vecCreateItems;

	float m_fSpawnTimer;
	int randomNumber;
	int killCount;
	int enterCount;
	int soundCount;
	int chestCount;

	bool m_bIsSpawnComplete;
	bool m_bIsRoom0Open;
	bool m_bIsRoom1Clear;
	bool m_bIsRoom2Clear;
	bool m_bIsRoom3Clear;
	bool m_bIsRoom4Clear;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
