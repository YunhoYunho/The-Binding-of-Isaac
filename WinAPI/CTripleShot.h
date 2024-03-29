#pragma once
#include "CPassiveItem.h"

class CPlayer;

class CTripleShot : public CPassiveItem
{
public:
	CTripleShot();
	virtual ~CTripleShot();

	void Activate(CPlayer* pPlayer) override;

private:
	CImage* m_pTripleShotImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

