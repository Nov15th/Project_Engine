#include "YMPlayScene.h"
#include "YMGameObject.h"
#include "YMPlayer.h"
#include "YMTransform.h"
#include "YMSpriteRenderer.h"
namespace YM
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		
		Player* bg = new Player();
		Transform* tr
			= bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");
		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\Choi_young ming\\source\\repos\\ProjectEngine\\Resources\\CloudOcean.png");
		AddGameObject(bg);
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}