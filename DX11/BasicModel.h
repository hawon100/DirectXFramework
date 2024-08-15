#pragma once

#include "MeshGeometry.h"
#include "TextureMgr.h"
#include "Vertex.h"
#include "LightHelper.h"

class BasicModel
{
public:
	BasicModel(ComPtr<ID3D11Device> device, TextureMgr& texMgr, const std::string& modelFilename, const std::wstring& texturePath);
	~BasicModel();

	uint32 SubsetCount;

	std::vector<Material> Mat;
	std::vector<ComPtr<ID3D11ShaderResourceView>> DiffuseMapSRV;
	std::vector<ComPtr<ID3D11ShaderResourceView>> NormalMapSRV;

	// Keep CPU copies of the mesh data to read from.  
	std::vector<Vertex::PosNormalTexTan2> Vertices;
	std::vector<USHORT> Indices;
	std::vector<MeshGeometry::Subset> Subsets;

	MeshGeometry ModelMesh;
};

struct BasicModelInstance
{
	shared_ptr<class BasicModel> Model;
	XMFLOAT4X4 World;
};