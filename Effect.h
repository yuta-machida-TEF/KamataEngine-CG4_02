#pragma once
#include <3d/Camera.h>
#include <3d/Model.h>
#include <3d/ObjectColor.h>
#include <3d/WorldTransform.h>
#include <math/Vector3.h>
#include <math/Vector4.h>

class Effect {
public:

	bool IsFinished() const { return isFinished_; }

	void Initialize(KamataEngine::Model* model, float rotate, float size, KamataEngine::Vector3 position, KamataEngine::Vector3 color);

	void Update();

	void Draw(KamataEngine::Camera& camera);

private:
	// モデル
	KamataEngine::Model* model_ = nullptr;

	// ワールド変換
	KamataEngine::WorldTransform worldTransform_;

	// 色
	KamataEngine::ObjectColor objectColor_;
	KamataEngine::Vector4 color_;

	// フェードアウト用
	float counter_ = 0.0f;

	// 存続時間
	const float kDuration = 1.0f;

	// 終了フラグ
	bool isFinished_ = false;
};