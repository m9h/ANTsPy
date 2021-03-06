/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkMGHImageIOFactory_h
#define itkMGHImageIOFactory_h

#include "itkVersion.h"
#include "itkMGHImageIO.h"
#include "itkObjectFactoryBase.h"
#include "itkImageIOBase.h"


//#include "MGHIOExport.h"

namespace itk
{
/** \class MGHImageIOFactory
   * \brief Create instances of MGHImageIO objects using an object factory.
   * \ingroup MGHIO
   */
class MGHImageIOFactory : public ObjectFactoryBase
{
public:
  /** Standard class typedefs */
  typedef MGHImageIOFactory        Self;
  typedef ObjectFactoryBase        Superclass;
  typedef SmartPointer<Self>       Pointer;
  typedef SmartPointer<const Self> ConstPointer;

  /** Class methods used to interface with the registered factories **/
  virtual const char * GetITKSourceVersion(void) const ITK_OVERRIDE;

  virtual const char * GetDescription(void)  const ITK_OVERRIDE;

  /** Method for class instantiation **/
  itkFactorylessNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(MGHImageIOFactory, ObjectFactoryBase);

  /** Register one factory of this type */
  static void RegisterOneFactory(void)
  {
    MGHImageIOFactory::Pointer MGHFactory = MGHImageIOFactory::New();

    ObjectFactoryBase::RegisterFactoryInternal(MGHFactory);
  }

protected:
  MGHImageIOFactory();
  ~MGHImageIOFactory();
  virtual void PrintSelf(std::ostream & os, Indent indent) const ITK_OVERRIDE;

private:
  ITK_DISALLOW_COPY_AND_ASSIGN(MGHImageIOFactory);
};

void MGHImageIOFactory::PrintSelf(std::ostream &, Indent) const
{}

MGHImageIOFactory::MGHImageIOFactory()
{
  this->RegisterOverride("itkImageIOBase",
                         "itkMGHImageIO",
                         "MGH Image IO",
                         1,
                         CreateObjectFunction<MGHImageIO>::New() );
}

MGHImageIOFactory::~MGHImageIOFactory()
{}

const char *
MGHImageIOFactory::GetITKSourceVersion(void) const
{
  return ITK_SOURCE_VERSION;
}

const char *
MGHImageIOFactory::GetDescription() const
{
  return "MGH ImageIO Factory, allows the loading of MGH/MGZ images into Insight";
}
// Undocumented API used to register during static initialization.
// DO NOT CALL DIRECTLY.

static bool MGHImageIOFactoryHasBeenRegistered=false;

void  MGHImageIOFactoryRegister__Private(void)
{
  if( ! MGHImageIOFactoryHasBeenRegistered )
    {
    MGHImageIOFactoryHasBeenRegistered = true;
    MGHImageIOFactory::RegisterOneFactory();
    }
}
} // end namespace itk

#endif /// itkMGHImageIOFactory_h