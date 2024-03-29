#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CImageObject : public CGameObject
{
public:
	CImageObject();
	virtual ~CImageObject();

private:
	CImage* m_pImage;
	CAnimator* m_pAnimator;

public:
	CImage* GetIamge();
	void SetImage(CImage* pImage);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

