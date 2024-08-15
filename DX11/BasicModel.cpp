#include "pch.h"
#include "BasicModel.h"
#include "LoadM3d.h"

BasicModel::BasicModel(ComPtr<ID3D11Device> device, TextureMgr& texMgr, const std::string& modelFilename, const std::wstring& texturePath)
{
	std::vector<M3dMaterial> mats;

	M3DLoader m3dLoader;
	m3dLoader.LoadM3d(modelFilename, Vertices, Indices, Subsets, mats);

	ModelMesh.SetVertices(device, &Vertices[0], Vertices.size());
	ModelMesh.SetIndices(device, &Indices[0], Indices.size());
	ModelMesh.SetSubsetTable(Subsets);

	SubsetCount = mats.size();

	for (uint32 i = 0; i < SubsetCount; ++i)
	{
		Mat.push_back(mats[i].Mat);

		ComPtr<ID3D11ShaderResourceView> diffuseMapSRV = texMgr.CreateTexture(texturePath + mats[i].DiffuseMapName);
		DiffuseMapSRV.push_back(diffuseMapSRV);

		ComPtr<ID3D11ShaderResourceView> normalMapSRV = texMgr.CreateTexture(texturePath + mats[i].NormalMapName);
		NormalMapSRV.push_back(normalMapSRV);
	}
}

BasicModel::~BasicModel()
{
}
