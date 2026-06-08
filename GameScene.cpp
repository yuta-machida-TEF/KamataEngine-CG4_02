#include "GameScene.h"
#include <algorithm>

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
	worldTransform_.scale_ = {10, 10, 10};
	worldTransform_.rotation_.z = 0.785f;

	objectColor_.Initialize();
	color_ = {1.0f,1.0f, 1.0f, 1.0f};

	// 3Dモデルデータの生成
	model2 = Model2::CreateSquare(64);
}

void GameScene::Update() {
	
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;

		// 終了扱いにする
		isFinished_ = true;
	}
	worldTransform_.rotation_.y = 3.14f;

	// 色変更オブジェクトに色の数値を設定する
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	objectColor_.SetColor(color_);

	worldTransform_.rotation_.z += 0.1f;
	worldTransform_.scale_.x *= 0.98f;
	worldTransform_.scale_.y *= 0.98f;

	// 3Dモデルを更新
	worldTransform_.UpdateMatrix();
}

void GameScene::Draw() {

	// 終了なら何もしない
	if (isFinished_) {
		return;
	}


	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());

	// 3Dモデルを描画
	model2->Draw(worldTransform_, camera_,&objectColor_);//この2つだけ白い四角形を描画する

	// 3Dモデル描画後処理
	Model2::PostDraw();
}