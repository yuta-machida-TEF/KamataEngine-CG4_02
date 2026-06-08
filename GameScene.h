#pragma once

#include <list>

#include <3d/Camera.h>
#include <3d/Model.h>
#include <math/Vector3.h>

#include "Effect.h"

class GameScene {
public:
	GameScene() = default;
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	// エフェクト発生
	void EffectBorn(KamataEngine::Vector3 position);

private:
	// カメラ
	KamataEngine::Camera camera_;

	// エフェクト用モデル
	KamataEngine::Model* modelEffect_ = nullptr;

	// エフェクト一覧
	std::list<Effect*> effects_;
};