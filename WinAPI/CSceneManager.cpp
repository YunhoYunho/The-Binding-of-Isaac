#include "framework.h"
#include "CSceneManager.h"

#include "CScene.h"
#include "CSceneTitle.h"
#include "CSceneTileTool.h"
#include "CSceneSLoading.h"
#include "CSceneStage01.h"
#include "CSceneEnding.h"

CSceneManager::CSceneManager()
{
	m_pCurScene = nullptr;
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::Init()
{
	// TODO : 게임에 필요한 씬 추가
	// 게임씬들을 자료구조에 추가

	CScene* pSceneTitle = new CSceneTitle();
	m_mapScene.insert(make_pair(GroupScene::Title, pSceneTitle));

	CSceneTileTool* pSceneTileTool = new CSceneTileTool();
	m_mapScene.insert(make_pair(GroupScene::TileTool, pSceneTileTool));

	CScene* pSceneSLoading = new CSceneSLoading();
	m_mapScene.insert(make_pair(GroupScene::StageLoading, pSceneSLoading));

	CScene* pSceneStage01 = new CSceneStage01();
	m_mapScene.insert(make_pair(GroupScene::Stage01, pSceneStage01));

	CScene* pSceneEnding = new CSceneEnding();
	m_mapScene.insert(make_pair(GroupScene::Ending, pSceneEnding));

	// 게임씬 자료구조를 순회하며 씬을 초기화
	for (pair<GroupScene, CScene*> scene : m_mapScene)
	{
		scene.second->SceneInit();
	}

	// 가장 처음으로 진행해야할 게임씬 시작
	m_pCurScene = pSceneTitle;
	m_pCurScene->SceneEnter();
}

void CSceneManager::Update()
{
	m_pCurScene->SceneUpdate();
	m_pCurScene->ScenePhysicsUpdate();
}

void CSceneManager::Render()
{
	m_pCurScene->SceneRender();
}

void CSceneManager::Release()
{
	// 게임씬 자료구조를 순회하며 동적할당된 씬을 제거
	for (pair<GroupScene, CScene*> scene : m_mapScene)
	{
		scene.second->SceneRelease();
		delete scene.second;
	}
	
	// 모든 동적할당된 씬을 제거한뒤 자료구조를 clear
	m_mapScene.clear();
}

void CSceneManager::ChangeScene(GroupScene scene)
{
	// 이전씬을 Exit, 다음씬을 Enter
	m_pCurScene->SceneExit();
	m_pCurScene = m_mapScene[scene];
	m_pCurScene->SceneEnter();
}

CScene* CSceneManager::GetCurScene()
{
	return m_pCurScene;
}
