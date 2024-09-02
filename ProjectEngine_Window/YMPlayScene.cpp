#include "YMPlayScene.h"
#include "YMGameObject.h"
#include "YMPlayer.h"
#include "YMTransform.h"
#include "YMSpriteRenderer.h"
#include "YMInput.h"
#include "YMTitleScene.h"
#include "YMSceneManager.h"
#include "YMObject.h"
#include "YMTexture.h"
#include "YMResources.h"
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
		//bg = new Player();
		//Transform* tr
		//	= bg->AddComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
		//tr->SetName(L"TR");
		//SpriteRenderer* sr
		//	= bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"C:\\Users\\Choi_young ming\\source\\repos\\ProjectEngine\\Resources\\CloudOcean.png");
		//AddGameObject(bg, enums::eLayerType::BackGround);

		//게임 오브젝트 만들기 전에 전부 리소스를 로드해두면 좋다.


		bg = Object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(500.0f,500.0f));
		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG");
		sr->SetTexture(bg);
		//graphcis::Texture* tex = new graphcis::Texture();
		//tex->Load(L"C:\\Users\\Choi_young ming\\source\\repos\\ProjectEngine\\Resources\\CloudOcean.png");


		//sr->SetName(L"SR");
		//sr->ImageLoad(L"C:\\Users\\Choi_young ming\\source\\repos\\ProjectEngine\\Resources\\CloudOcean.png");
		//AddGameObject(bg, enums::eLayerType::BackGround);
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"Title Scene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 100, 100, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2( 0, 0 ));
	}
}