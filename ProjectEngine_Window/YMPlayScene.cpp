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
		//���� ������Ʈ ����� ���� ���� ���ҽ��� �ε��صθ� ����.
		GameObject* camera = Object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();

		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();

		mPlayer = Object::Instantiate<Player>(enums::eLayerType::Player);
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));*/
		graphcis::Texture* pacman = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreatAnimation(L"CatFrontMove"
			, pacman
			, Vector2(0.0f, 0.0f)
			, Vector2(32.0f, 32.0f)
			, Vector2::Zero
			, 4
			, 0.3f);
		animator->PlayAnimation(L"CatFrontMove", true);
		/*sr->SetTexture(pacman);*/

		mPlayer->AddComponent<PlayerScript>();
	
		GameObject* bg = Object::Instantiate<Player>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(3.0f, 3.0f));
		graphcis::Texture* bgtexture = Resources::Find<graphcis::Texture>(L"PM_BG");
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