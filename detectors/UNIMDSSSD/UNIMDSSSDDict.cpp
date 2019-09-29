// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME UNIMDSSSDDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "UNIMDSSSDRootEvent.h"
#include "UNIMStripArray.h"
#include "UNIMDSSSD.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_UNIMDSSSDData(void *p);
   static void deleteArray_UNIMDSSSDData(void *p);
   static void destruct_UNIMDSSSDData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::UNIMDSSSDData*)
   {
      ::UNIMDSSSDData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::UNIMDSSSDData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("UNIMDSSSDData", ::UNIMDSSSDData::Class_Version(), "UNIMDSSSDRootEvent.h", 6,
                  typeid(::UNIMDSSSDData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::UNIMDSSSDData::Dictionary, isa_proxy, 4,
                  sizeof(::UNIMDSSSDData) );
      instance.SetDelete(&delete_UNIMDSSSDData);
      instance.SetDeleteArray(&deleteArray_UNIMDSSSDData);
      instance.SetDestructor(&destruct_UNIMDSSSDData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::UNIMDSSSDData*)
   {
      return GenerateInitInstanceLocal((::UNIMDSSSDData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::UNIMDSSSDData*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_UNIMDSSSDRootEvent(void *p);
   static void deleteArray_UNIMDSSSDRootEvent(void *p);
   static void destruct_UNIMDSSSDRootEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::UNIMDSSSDRootEvent*)
   {
      ::UNIMDSSSDRootEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::UNIMDSSSDRootEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("UNIMDSSSDRootEvent", ::UNIMDSSSDRootEvent::Class_Version(), "UNIMDSSSDRootEvent.h", 26,
                  typeid(::UNIMDSSSDRootEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::UNIMDSSSDRootEvent::Dictionary, isa_proxy, 4,
                  sizeof(::UNIMDSSSDRootEvent) );
      instance.SetDelete(&delete_UNIMDSSSDRootEvent);
      instance.SetDeleteArray(&deleteArray_UNIMDSSSDRootEvent);
      instance.SetDestructor(&destruct_UNIMDSSSDRootEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::UNIMDSSSDRootEvent*)
   {
      return GenerateInitInstanceLocal((::UNIMDSSSDRootEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::UNIMDSSSDRootEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr UNIMDSSSDData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *UNIMDSSSDData::Class_Name()
{
   return "UNIMDSSSDData";
}

//______________________________________________________________________________
const char *UNIMDSSSDData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int UNIMDSSSDData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UNIMDSSSDData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UNIMDSSSDData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr UNIMDSSSDRootEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *UNIMDSSSDRootEvent::Class_Name()
{
   return "UNIMDSSSDRootEvent";
}

//______________________________________________________________________________
const char *UNIMDSSSDRootEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDRootEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int UNIMDSSSDRootEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDRootEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UNIMDSSSDRootEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDRootEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UNIMDSSSDRootEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::UNIMDSSSDRootEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void UNIMDSSSDData::Streamer(TBuffer &R__b)
{
   // Stream an object of class UNIMDSSSDData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(UNIMDSSSDData::Class(),this);
   } else {
      R__b.WriteClassBuffer(UNIMDSSSDData::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_UNIMDSSSDData(void *p) {
      delete ((::UNIMDSSSDData*)p);
   }
   static void deleteArray_UNIMDSSSDData(void *p) {
      delete [] ((::UNIMDSSSDData*)p);
   }
   static void destruct_UNIMDSSSDData(void *p) {
      typedef ::UNIMDSSSDData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::UNIMDSSSDData

//______________________________________________________________________________
void UNIMDSSSDRootEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class UNIMDSSSDRootEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(UNIMDSSSDRootEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(UNIMDSSSDRootEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_UNIMDSSSDRootEvent(void *p) {
      delete ((::UNIMDSSSDRootEvent*)p);
   }
   static void deleteArray_UNIMDSSSDRootEvent(void *p) {
      delete [] ((::UNIMDSSSDRootEvent*)p);
   }
   static void destruct_UNIMDSSSDRootEvent(void *p) {
      typedef ::UNIMDSSSDRootEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::UNIMDSSSDRootEvent

namespace {
  void TriggerDictionaryInitialization_UNIMDSSSDDict_Impl() {
    static const char* headers[] = {
"UNIMDSSSDRootEvent.h",
"UNIMStripArray.h",
"UNIMDSSSD.h",
0
    };
    static const char* includePaths[] = {
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/UNIMRawDataReader",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/detectors/UNIMDetector",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/detectors/UNIMDSSSD",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/detectors/UNIMLampWedge",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/UNIMRunInfo",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/UNIMExperimentalSetup",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/UNIMDetectorMap",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/UNIMCalibration",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/UNIMShared",
"/opt/ROOT/buildroot61804/include",
"/home/daniele/Dropbox/Ricerca/Ruder_Boskovic/software/UNIMapper/detectors/UNIMDSSSD/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "UNIMDSSSDDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$UNIMDSSSDRootEvent.h")))  UNIMDSSSDData;
class __attribute__((annotate("$clingAutoload$UNIMDSSSDRootEvent.h")))  UNIMDSSSDRootEvent;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "UNIMDSSSDDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "UNIMDSSSDRootEvent.h"
#include "UNIMStripArray.h"
#include "UNIMDSSSD.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"UNIMDSSSDData", payloadCode, "@",
"UNIMDSSSDRootEvent", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("UNIMDSSSDDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_UNIMDSSSDDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_UNIMDSSSDDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_UNIMDSSSDDict() {
  TriggerDictionaryInitialization_UNIMDSSSDDict_Impl();
}
