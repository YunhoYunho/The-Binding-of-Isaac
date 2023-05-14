#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	CAnimator* m_pAnimatorBody;
	CAnimator* m_pAnimatorHead;

	// 바디
	CImage* m_pBodyImage;

	// 헤드
	CImage* m_pHeadImage;
	CImage* m_pShotImage;

	// 공통
	CImage* m_pHurtImage;
	CImage* m_pDeadImage;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	
	CSound* pHurt = RESOURCE->LoadSound(L"Hurt", L"Sound\\Isaac\\Hurt.wav");
	CSound* pDead = RESOURCE->LoadSound(L"Dead", L"Sound\\Isaac\\Dies.wav");

	PlayerState m_playerState;
	wstring stateBody;
	wstring stateHead;

public:
	bool m_bIsMove;
	bool m_bIsShot;
	bool m_bIsHurt;
	bool m_bIsDead;

	int m_HP;
	float m_fSpeed = 200.0f;
	float m_fDamage = 2;
	float m_fTimer = 0;
	float fCooltime = 0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void HeadLookDir();
	void BodyLookDir();

	void IdleUpdate();
	void MoveUpdate();
	void ShotUpdate();
	void TakeHitUpdate();
	void DeadUpdate();

	void AnimatorUpdate();
	void CreateMissile();

	void MoveState();

	void ShotState();

	Vector GetLookDir();
	void SetLookDir(Vector vecLookDir);
	void SetMoveDir(Vector vecMoveDir);
	void SetStateName(wstring strState);

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

private:
	void PlayerPos();
	void PlayerHP();

	void HeadIdle();
	void HeadMove();
	void HeadShot();
	void HeadTakeHit();
	void HeadDead();

	void BodyIdle();
	void BodyMove();
	void BodyNull();
};
