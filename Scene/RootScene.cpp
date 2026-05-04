#include <DxLib.h>
#include "BaseScene.h"
#include "RootScene.h"
#include <array>
#include "RootScene.h"

namespace {
	std::array< VERTEX2DSHADER, 4 >	vertex;
	std::array< unsigned short, 6 >	vertexIndex;
}

RootScene::RootScene()
	: BaseScene("RootScene") {
	sceneCounter_ = 0;
	hShader_ = -1;
}

RootScene::~RootScene() {
}

void RootScene::Init() {
	ChangeLightTypeDir(VGet(-1.0f, 1.0f, -1.0f));
	hShader_ = LoadPixelShader("../../../Shader/TestPixelShader.pso");
	hImage_ = LoadGraph("../../../Shader/TestTexture.png");
	hModel_ = MV1LoadModel("../../../Shader/iii.mv1");

	auto Settings = [](VERTEX2DSHADER& vtx, float x, float y, float u, float v)
		{
			vtx.pos = VGet(x, y, 0.0f); //座標
			vtx.u = u; // テクスチャ座標（X軸）
			vtx.v = v; // テクスチャ座標（Y軸）
			vtx.su = u; // テクスチャ座標
			vtx.sv = v; // テクスチャ座標
			vtx.rhw = 1.0f;
			vtx.dif = GetColorU8(255, 255, 255, 255); //拡散反射光
			vtx.spc = GetColorU8(0, 0, 0, 0); //鏡面反射光
		};

	//頂点
	Settings(vertex[0], 100.0f, 100.0f, 0.0f, 0.0f); //左上
	Settings(vertex[1], 600.0f, 100.0f, 1.0f, 0.0f); //右上
	Settings(vertex[2], 100.0f, 600.0f, 0.0f, 1.0f); //左下
	Settings(vertex[3], 600.0f, 600.0f, 1.0f, 1.0f); //右下

	vertexIndex = { 0, 1, 2, 1, 2, 3 };
	SetUsePixelShader(hShader_);
	SetUseTextureToShader(0, hImage_);

	int matNum = MV1GetMaterialNum(hModel_);
	

	static int result = 0;
	result = MV1GetMaterialDifMapTexture(hModel_, 0);
	result = MV1SetTextureGraphHandle(hModel_, 0, hImage_, FALSE);
}

void RootScene::Update() {
	sceneCounter_++;

	static VECTOR vector = GetCameraPosition();
	static VECTOR target = GetCameraTarget();

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		vector.y += 10;
		target.y += 10;
	}
	if (CheckHitKey(KEY_INPUT_LSHIFT)) {
		vector.y -= 10;
		target.y -= 10;
	}
	if (CheckHitKey(KEY_INPUT_W)) {
		vector.z -= 10;
		target.z -= 10;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		vector.z += 10;
		target.z += 10;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		vector.x -= 10;
		target.x -= 10;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		vector.x += 10;
		target.x += 10;
	}

	SetCameraPositionAndTarget_UpVecY(vector, target);
}

void RootScene::Draw() {
#ifdef _DEBUG //デバック用（※消しても問題なし）
	static int result = 0;
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);
	result = DrawPolygonIndexed2DToShader(vertex.data(), 4, vertexIndex.data(), 2);
	MV1DrawModel(hModel_);
#endif 
}

void RootScene::Release() {
}
