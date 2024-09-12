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
#include "YMPlayerScript.h"
#include "YMCamera.h"
#include "YMRenderer.h"
#include "YMAnimator.h"
#include "YMCat.h"
#include "YMCatScript.h"

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
		//게임 오브젝트 만들기 전에 전부 리소스를 로드해두면 좋다.
		GameObject* camera = Object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = Object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();

		graphcis::Texture* playerTex = Resources::Find<graphcis::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreatAnimation(L"PlayerIdle", playerTex,
			Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreatAnimation(L"PlantGiveWater", playerTex,
			Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"PlayerIdle", false);

		/*sr->SetTexture(playerTex);*/


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
		


		///Cat
		Cat* cat = Object::Instantiate<Cat>(enums::eLayerType::Animal);
		cat->AddComponent<CatScript>();


		graphcis::Texture* catTex = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* catanimator = cat->AddComponent<Animator>();
		catanimator->CreatAnimation(L"CatDownWalk"
			, catTex
			, Vector2(0.0f, 0.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		catanimator->CreatAnimation(L"CatRightWalk"
			, catTex
			, Vector2(0.0f, 32.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		catanimator->CreatAnimation(L"CatUpWalk"
			, catTex
			, Vector2(0.0f, 64.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		catanimator->CreatAnimation(L"CatLeftWalk"
			, catTex
			, Vector2(0.0f, 96.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		catanimator->CreatAnimation(L"CatSitDown"
			, catTex
			, Vector2(0.0f, 128.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		catanimator->CreatAnimation(L"CatGrooming"
			, catTex
			, Vector2(0.0f, 160.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		catanimator->CreatAnimation(L"CatLayDown"
			, catTex
			, Vector2(0.0f, 192.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);


		catanimator->PlayAnimation(L"CatSitDown", false);

		cat->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 300.0f));

		/*sr->SetTexture(playerTex);*/





		Scene::Initialize();
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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 20, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		Transform* tr = mPlayer->GetComponent<Transform>();
		tr->SetPosition(Vector2( 0, 0 ));
	}
}