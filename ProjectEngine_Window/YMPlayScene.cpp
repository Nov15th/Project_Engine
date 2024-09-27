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
#include "YMBoxCollider2D.h"
#include "YMCircleCollider2D.h"
#include "YMCollisionManager.h"

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
		CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Animal, true);
		// main Camera
		GameObject* camera = Object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		

		mPlayer = Object::Instantiate<Player>(enums::eLayerType::Player);
		Object::DontDestroyOnLoad(mPlayer);



		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		CircleCollider2D* collider = mPlayer->AddComponent<CircleCollider2D>();
		//BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));

		graphcis::Texture* playerTex = Resources::Find<graphcis::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreatAnimation(L"PlayerIdle", playerTex,
			Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreatAnimation(L"FrontGiveWater", playerTex,
			Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"PlayerIdle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		/*sr->SetTexture(playerTex);*/


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(350.0f, 350.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
		


		//Cat
		Cat* cat = Object::Instantiate<Cat>(enums::eLayerType::Animal);
		//cat->SetActive(false);
		cat->AddComponent<CatScript>();
		//cameraComp->SetTarget(cat);
		graphcis::Texture* catTex = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* catanimator = cat->AddComponent<Animator>();

		//BoxCollider2D* boxCatCollider = cat->AddComponent<BoxCollider2D>();
		CircleCollider2D* circleCatCollider = cat->AddComponent<CircleCollider2D>();

		circleCatCollider->SetOffset(Vector2(-50.0f, -50.0f));
		

		/*catanimator->CreatAnimation(L"CatDownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatRightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatUpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatLeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatSitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatGrooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catanimator->CreatAnimation(L"CatLayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catanimator->PlayAnimation(L"CatSitDown", false);*/

		catanimator->CreatAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);
		catanimator->PlayAnimation(L"MushroomIdle", true);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));


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