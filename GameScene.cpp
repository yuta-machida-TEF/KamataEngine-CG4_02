#include "GameScene.h"
using namespace KamataEngine;

GameScene::GameScene() {}

// デストラクタ
GameScene::~GameScene() {
	// 3Dモデルデータの解放
	delete model2;

	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	Model2::StaticInitialize();

	// カメラの初期化
	camera_.Initialize();

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.scale_ = {5, 5, 5};

	worldTransform_.rotation_.z = 0.785f;

	// 3Dモデルデータの生成
	model2 = Model2::CreateSquare(1);
}

void GameScene::Update() {
	// 3Dモデルを更新

	worldTransform_.UpdateMatrix();
}

void GameScene::Draw() {
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());

	// 3Dモデルを描画
	model2->Draw(worldTransform_, camera_);//この2つだけ白い四角形を描画する

	// 3Dモデル描画後処理
	Model2::PostDraw();
}