#pragma once
#include <DxLib.h>
#include "BaseScene.h"

class RootScene : public BaseScene {
private:
	int hShader_;
	int hImage_;
	int hModel_;
	VERTEX2DSHADER Vert[6];
protected:
public:
	RootScene();
	~RootScene();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};