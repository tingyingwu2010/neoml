/* Copyright © 2017-2020 ABBYY Production LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
--------------------------------------------------------------------------------------------------------------*/

#pragma once

#include "../Node.h"

// Forward declaration(s).
namespace onnx {
class NodeProto;
} // namespace onnx

namespace NeoOnnx {

class CConcatNode : public CNode {
public:
	CConcatNode( const onnx::NodeProto& concat, CMap<CString, CInputInfo>& nodeOutputs );

	// CNode methods' realizations.
	void OnnxReshape() override;
	void MarkTensorDims() override;
	void AddLayers( CDnn& dnn ) override;

private:
	const int axis; // axis index along which tensors are concatenated
};

} // namespace NeoOnnx
