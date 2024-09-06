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
		//camera->AddComponent<PlayerScript>();

		mPlayer = Object::Instantiate<Player>(enums::eLayerType::Player);
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));*/
		mPlayer->AddComponent<PlayerScript>();

		/*graphcis::Texture* pacman = Resources::Find<graphcis::Texture>(L"MapleEffect");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreatAnimation(L"CatFrontMove"
			, pacman
			, Vector2(0.0f, 0.0f)
			, Vector2(386.0f, 246.0f)
			, Vector2::Zero
			, 8
			, 0.05f);

		animator->PlayAnimation(L"CatFrontMove", true);*/

		graphcis::Texture* pacman = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreatAnimation(L"CatDownWalk"
			, pacman
			, Vector2(0.0f, 0.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		animator->CreatAnimation(L"CatRightWalk"
			, pacman
			, Vector2(0.0f, 32.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		animator->CreatAnimation(L"CatUpWalk"
			, pacman
			, Vector2(0.0f, 64.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		animator->CreatAnimation(L"CatLeftWalk"
			, pacman
			, Vector2(0.0f, 96.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		animator->CreatAnimation(L"CatSitDown"
			, pacman
			, Vector2(0.0f, 128.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		animator->CreatAnimation(L"CatGrooming"
			, pacman
			, Vector2(0.0f, 160.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.1f);

		animator->PlayAnimation(L"CatSitDown", false);

		/*sr->SetTexture(pacman);*/


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 300.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
		


		GameObject* bg = Object::Instantiate<Player>(enums::eLayerType::Particle);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		//bgsr->SetSize(Vector2::One);
		graphcis::Texture* bgtexture = Resources::Find<graphcis::Texture>(L"Bubble");
		bgsr->SetTexture(bgtexture);

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