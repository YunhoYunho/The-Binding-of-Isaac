#include "framework.h"
#include "CSceneSLoading.h"
#include "CSLoadingImage.h"

CSceneSLoading::CSceneSLoading()
{
	fCooltime = 0;
	pSLoading = nullptr;
}

CSceneSLoading::~CSceneSLoading()
{
}

void CSceneSLoading::Init()
{
	pSLoading = RESOURCE->LoadSound(L"SLoading", L"Sound\\Scene\\SLoading.ogg");

	CSLoadingImage* pLoading = new CSLoadingImage;
	pLoading->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	AddGameObject(pLoading);
}

void CSceneSLoading::Enter()
{
	CAMERA->FadeIn(0.25f);

	SOUND->Play(pSLoading, 0.3f, false);
}

void CSceneSLoading::Update()
{
	fCooltime += DT;

	if (fCooltime > 4.0f)
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Stage01, 0.25f);
	}
}

void CSceneSLoading::Render()
{
}

void CSceneSLoading::Exit()
{
	SOUND->Stop(pSLoading);
}

void CSceneSLoading::Release()
{
}
