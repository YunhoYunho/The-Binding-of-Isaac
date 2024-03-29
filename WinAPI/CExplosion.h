#pragma once
#include "CGameObject.h"

class CBomb;

class CExplosion : public CGameObject
{
	friend CBomb;
public:
	CExplosion();
	virtual ~CExplosion();

private:
	CAnimator* m_pAnimator;
	CImage* m_pExplosionImage;
	CSound* m_pExplosion;

public:
	float m_fDamage;
	float m_fCooltime;

	void Boom();
	void BoomSound();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};

