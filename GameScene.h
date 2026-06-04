#pragma once
#include "KamataEngine.h"
#include "Model2.h"

using namespace KamataEngine;

class GameScene {
public:
	GameScene();
	~GameScene();

	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();

private:
	// カメラ
	KamataEngine::Camera camera_;
	// ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;

	bool isFinished_;

	float counter_;
	
	const float kDuration = 2.0f;

	// 色変更
	KamataEngine::ObjectColor objectColor_;

	// RGBAカラー
	KamataEngine::Vector4 color_ = {1.0f, 1.0f, 1.0f, 1.0f};

	KamataEngine::Model2* model2 = nullptr;
};