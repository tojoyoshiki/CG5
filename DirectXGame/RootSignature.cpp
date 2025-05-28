#include "RootSignature.h"
#include "KamataEngine.h"

using namespace KamataEngine;

	// 生成したRootSignatureを返す
ID3D12RootSignature* RootSignature::Get() { return rootSignature_; }

//コンストラクタ
RootSignature::RootSignature() {}

//デストラクタ
RootSignature::~RootSignature() {
	if (rootSignature_) {
		rootSignature_ -> Release();
		rootSignature_ = nullptr;
	}
}

// RootSignatureを生成する
void RootSignature::Create() {
	// 既にインスタンスがあるなら開放する
	if (rootSignature_) {
		rootSignature_->Release();
		rootSignature_ = nullptr;
	}

	// クラス内で取得するために追加
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//-----RootSignature作成------
	// 構造体にデータを取得する
	D3D12_ROOT_SIGNATURE_DESC descriptionRootSigture{};
	descriptionRootSigture.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	ID3DBlob* signatureBlob = nullptr;
	ID3DBlob* errorBlob = nullptr;
	HRESULT hr = D3D12SerializeRootSignature(&descriptionRootSigture, D3D_ROOT_SIGNATURE_VERSION_1, &signatureBlob, &errorBlob);
	if (FAILED(hr)) {
		DebugText::GetInstance()->ConsolePrintf(reinterpret_cast<char*>(errorBlob->GetBufferPointer()));
		assert(false);
	}

	// バイナリを元に作成
	ID3D12RootSignature* rootSignature = nullptr;
	hr = dxCommon->GetDevice()->CreateRootSignature(0, signatureBlob->GetBufferPointer(), signatureBlob->GetBufferSize(), IID_PPV_ARGS(&rootSignature));
	assert(SUCCEEDED(hr));

	//signatureBlobはRootSignatureの生成後開放してもいい
	signatureBlob->Release();

	//生成したRootSignatureを取っておく
	rootSignature_ = rootSignature;

}
