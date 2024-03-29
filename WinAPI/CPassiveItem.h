#pragma once
#include "CItem.h"

class CPassiveItem : public CItem
{
public:
	CPassiveItem();
	virtual ~CPassiveItem();

protected:
	int m_iCount = 0;
	bool m_bIsGetItem = false;

	void GetItem();
	void CheckColl(CCollider* pOtherCollider);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

