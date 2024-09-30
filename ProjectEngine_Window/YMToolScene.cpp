#include "YMToolScene.h"
#include "YMObject.h"
#include "YMTile.h"
#include "YMTilemapRenderer.h"
#include "YMResources.h"
#include "YMTexture.h"
#include "YMCamera.h"
#include "YMRenderer.h"
#include "YMInput.h"
namespace YM
{


	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		GameObject* camera = Object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));


		Scene::Initialize();

	}
	void ToolScene::Update()
	{
		Scene::Update();
	}
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKey(eKeyCode::LButton))
		{
			Vector2 pos = Input::GetMousePosition();

			int idxX= pos.x / TilemapRenderer::TileSize.x;
			int idxY= pos.y / TilemapRenderer::TileSize.y;

			Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			
			tile->SetPosition(idxX,idxY);
		}
		
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		for (size_t i = 0; i< 50; i++)
		{
			MoveToEx(hdc, TilemapRenderer::TileSize.x*i, 0, NULL);
			LineTo(hdc, TilemapRenderer::TileSize.x*i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, TilemapRenderer::TileSize.y * i, NULL);
			LineTo(hdc, 1000, TilemapRenderer::TileSize.y * i);
		}
	}
	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
}



LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{

	}
	break;
	case WM_LBUTTONDOWN:
	{

	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		YM::graphics::Texture* texture = YM::Resources::Find<YM::graphics::Texture>(L"SpringFloor");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));


		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}