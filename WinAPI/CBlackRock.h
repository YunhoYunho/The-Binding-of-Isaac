#pragma once
#include "CRock.h"

class CBlackRock : public CRock
{
public:
	CBlackRock();
	virtual ~CBlackRock();

	CImage* m_pBlackRockImage;
	CImage* m_pBlackFragmentsImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

