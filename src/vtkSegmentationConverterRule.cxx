/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See https://opensource.org/licenses/BSD-2-Clause for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

// Segmentations includes
#include "vtkSegmentationConverterRule.h"

// VTK includes
#include <vtkObjectFactory.h>

//----------------------------------------------------------------------------
vtkSegmentationConverterRule::vtkSegmentationConverterRule()
{
}

//----------------------------------------------------------------------------
vtkSegmentationConverterRule::~vtkSegmentationConverterRule()
{
  this->ConversionParameters.clear();
}

//----------------------------------------------------------------------------
vtkSegmentationConverterRule* vtkSegmentationConverterRule::Clone()
{
  vtkSegmentationConverterRule* clone = this->CreateRuleInstance();
  clone->ConversionParameters = this->ConversionParameters;
  return clone;
}

//----------------------------------------------------------------------------
void vtkSegmentationConverterRule::GetRuleConversionParameters(ConversionParameterListType& conversionParameters)
{
  // Copy rule conversion parameters into aggregated path parameters
  ConversionParameterListType::iterator paramIt;
  for (paramIt = this->ConversionParameters.begin(); paramIt != this->ConversionParameters.end(); ++paramIt)
    {
    conversionParameters[paramIt->first] = paramIt->second;
    }
}

//----------------------------------------------------------------------------
void vtkSegmentationConverterRule::SetConversionParameter(const std::string& name, const std::string& value, const std::string& description/*=""*/)
{
  this->ConversionParameters[name].first = value;

  if (!description.empty())
    {
    this->ConversionParameters[name].second = description;
    }
}

//----------------------------------------------------------------------------
std::string vtkSegmentationConverterRule::GetConversionParameter(const std::string& name)
{
  return this->ConversionParameters[name].first;
}

//----------------------------------------------------------------------------
std::string vtkSegmentationConverterRule::GetConversionParameterDescription(const std::string& name)
{
  return this->ConversionParameters[name].second;
}

//----------------------------------------------------------------------------
bool vtkSegmentationConverterRule::HasConversionParameter(const std::string& name)
{
  return (this->ConversionParameters.count(name) > 0);
}
