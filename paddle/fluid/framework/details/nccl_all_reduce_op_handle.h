//   Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "paddle/fluid/framework/details/op_handle_base.h"
#include "paddle/fluid/framework/lod_tensor.h"
#include "paddle/fluid/framework/scope.h"
#include "paddle/fluid/platform/nccl_helper.h"

namespace paddle {
namespace framework {
namespace details {

struct NCCLAllReduceOpHandle : public OpHandleBase {
  const std::vector<Scope *> &local_scopes_;
  const std::vector<platform::Place> &places_;
  const platform::NCCLContextMap &nccl_ctxs_;

  NCCLAllReduceOpHandle(const std::vector<Scope *> &local_scopes,
                        const std::vector<platform::Place> &places,
                        const platform::NCCLContextMap &ctxs);

  std::string Name() const override;

 protected:
  void RunImpl() override;
};

}  // namespace details
}  // namespace framework
}  // namespace paddle
