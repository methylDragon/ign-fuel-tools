/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <ignition/fuel-tools/Model.hh>
#include <ignition/fuel-tools/ModelPrivate.hh>

namespace ignft = ignition::fuel_tools;
using namespace ignition;
using namespace ignft;

//////////////////////////////////////////////////
Model::Model() : dataPtr(new ModelPrivate)
{
}

//////////////////////////////////////////////////
Model::Model(std::shared_ptr<ModelPrivate> _dptr)
{
  this->dataPtr = _dptr;
}

//////////////////////////////////////////////////
ModelIdentifier Model::Identification()
{
  return this->dataPtr->id;
}

//////////////////////////////////////////////////
Result Model::Fetch()
{
  if (this->PathToModel().empty())
  {
    // TODO look for models on servers
    return Result(Result::FETCH_ERROR);
  }
  return Result(Result::FETCH_ALREADY_EXISTS);
}

//////////////////////////////////////////////////
std::string Model::PathToModel()
{
  if (this->dataPtr->pathOnDisk.empty())
  {
    // TODO check if model is in cache, store path
  }
  return this->dataPtr->pathOnDisk;
}
