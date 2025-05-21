#pragma once
#include <d3d12.h>
#include <d3dcompiler.h> // dxcapi が依存している
#include <dxcapi.h>      // IDxcBlob を使うため
#include <string>
#pragma comment(lib, "dxcompiler.lib")

class Shader {
public:
	// シェーダーモデルを読み込み、コンパイル済みデータを生成する
	void Load(const std::wstring& filePath, const std::wstring& shaderModel);
	void LoadDxc(const std::wstring& filePath, const std::wstring& shaderModel);

	// 生成したコンパイル済みデータを取得する
	ID3DBlob* GetBlob();
	IDxcBlob* GetDxcBlob();

	// コンストラクタ
	Shader();
	// デストラクタ
	~Shader();

private:
	ID3D10Blob* blob_ = nullptr; // コンストラクタで初期化しなくてもいい (C++11以降)
	IDxcBlob* dxcBlob_ = nullptr;
};
