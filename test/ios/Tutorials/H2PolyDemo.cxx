#include "TRandom.h"
#include "TH2Poly.h"
#include "TFile.h"
#include "TMath.h"
#include "TKey.h"

#include "H2PolyDemo.h"

namespace ROOT {
namespace iOS {
namespace Demos {

////////////////////////////////////////////////////////////////////////////////

H2PolyDemo::H2PolyDemo(const char *fileName)
{
   std::auto_ptr<TFile> inputFile(TFile::Open(fileName, "read"));
   if (!inputFile.get())
      return;

   fPoly.reset(dynamic_cast<TH2Poly *>(inputFile->Get("h2poly")));
   if (fPoly.get())
      fPoly->SetDirectory(0);
}

////////////////////////////////////////////////////////////////////////////////
///For auto_ptr's dtor only.

H2PolyDemo::~H2PolyDemo()
{
}

////////////////////////////////////////////////////////////////////////////////

void H2PolyDemo::PresentDemo()
{
   if (fPoly.get())
      fPoly->Draw("COLZ");
}


}
}
}
