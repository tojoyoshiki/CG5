#pragma once

#include <d3dx12.h>

class IndexBuffer {
public:
	// indexBuffer定義
	void Create(const UINT size, const UINT stride);

	// Getter
	ID3D12Resource* Get();
	D3D12_INDEX_BUFFER_VIEW* GetView();

	// コンストラクタ
	IndexBuffer();
	// デストラクタ
	~IndexBuffer();

private:
	ID3D12Resource* indexBuffer_ = nullptr;
	D3D12_INDEX_BUFFER_VIEW indexBufferView_{};
};
