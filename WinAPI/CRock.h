#pragma once
#include "CObstacle.h"
#include "CPickupItem.h"

class CRock : public CObstacle
{
public:
	CRock();
	virtual ~CRock();

	CAnimator* m_pAnimator;
	CImage* m_pRockImage;
	CImage* m_pFragmentsImage;
	CSound* pBrokenSound;
	CPickupItem* pItem;

	void Broken();
	void BrokenSound();
	void AppearItem();
	void SelectItem(int num);

	bool m_bIsBroken;
	bool m_bIsSpecial;
	float m_fTimer = 0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

