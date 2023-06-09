#pragma once
#include "CPassiveItem.h"

class CAnimator;
class CImage;
class CPlayer;

class CTripleShot : public CPassiveItem
{
public:
	CTripleShot();
	virtual ~CTripleShot();

private:
	CImage* m_pTripleShotImage;
	CPlayer* pPlayer;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

