#include "framework.h"
#include "CSceneLoading.h"

#include "CLoadingImage.h"

CSceneLoading::CSceneLoading()
{
}

CSceneLoading::~CSceneLoading()
{
}

void CSceneLoading::Init()
{
	CLoadingImage* pLoading = new CLoadingImage;
	pLoading->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	AddGameObject(pLoading);
}

void CSceneLoading::Enter()
{
	CAMERA->FadeIn(0.25f);

	SOUND->Play(pLoading, 1.0f, false);
}

void CSceneLoading::Update()
{
	if (BUTTONDOWN(VK_SPACE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Stage01, 0.25f);
	}
}

void CSceneLoading::Render()
{
}

void CSceneLoading::Exit()
{
	SOUND->Pause(pLoading);
}

void CSceneLoading::Release()
{
}