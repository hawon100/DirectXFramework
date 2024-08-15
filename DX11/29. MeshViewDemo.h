#pragma once
#include "App.h"
#include "Waves.h"
#include "LightHelper.h"
#include "BlurFilter.h"
#include "Camera.h"
#include "Vertex.h"
#include "Terrain.h"
#include "Octree.h"
#include "TextureMgr.h"
#include "BasicModel.h"

class MeshViewDemo : public App
{
public:
	MeshViewDemo(HINSTANCE hInstance);
	~MeshViewDemo();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

	void OnMouseDown(WPARAM btnState, int32 x, int32 y);
	void OnMouseUp(WPARAM btnState, int32 x, int32 y);
	void OnMouseMove(WPARAM btnState, int32 x, int32 y);

private:
	void DrawSceneToSsaoNormalDepthMap();
	void DrawSceneToShadowMap();
	void DrawScreenQuad(ComPtr<ID3D11ShaderResourceView> srv);
	void BuildShadowTransform();
	void BuildScreenQuadGeometryBuffers();

private:
	TextureMgr _texMgr;

	shared_ptr<class Sky> _sky;

	shared_ptr<class BasicModel> _treeModel;
	shared_ptr<class BasicModel> _baseModel;
	shared_ptr<class BasicModel> _stairsModel;
	shared_ptr<class BasicModel> _pillar1Model;
	shared_ptr<class BasicModel> _pillar2Model;
	shared_ptr<class BasicModel> _pillar3Model;
	shared_ptr<class BasicModel> _pillar4Model;
	shared_ptr<class BasicModel> _rockModel;

	std::vector<BasicModelInstance> _modelInstances;
	std::vector<BasicModelInstance> _alphaClippedModelInstances;

	ComPtr<ID3D11Buffer> _screenQuadVB;
	ComPtr<ID3D11Buffer> _screenQuadIB;

	BoundingSphere _sceneBounds;

	static const int SMapSize = 2048;
	shared_ptr<class ShadowMap> _smap;
	XMFLOAT4X4 _lightView;
	XMFLOAT4X4 _lightProj;
	XMFLOAT4X4 _shadowTransform;

	shared_ptr<class Ssao> _ssao;

	float _lightRotationAngle = 0.f;
	XMFLOAT3 _originalLightDir[3];
	DirectionalLight _dirLights[3];

	Camera _camera;

	POINT _lastMousePos;
};