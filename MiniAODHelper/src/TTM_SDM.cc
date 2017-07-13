#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>

#include "TH2F.h"
#include "TString.h"
#include "TFile.h"
#include "TH1F.h"
#include "TRandom3.h"


#include "MiniAOD/MiniAODHelper/interface/TTM_SDM.h"

//default constr.
TTMHelper::TTMHelper(){gRandom = new TRandom3(42);}


void TTMHelper::Load_QCDMistag (TString datafile,TString histoname)
{
	TFile *file = new TFile(datafile,"READ");
	if (file->IsZombie()){
	std::cout << "Error opening file " << datafile << std::endl;
	}
	else{
	fQCD = dynamic_cast<TH2F*> (file->Get(histoname));
	}
}

 
TH1F* TTMHelper::Load_DisSDM (TString datafile,TString histoname)
{
	TFile *file = new TFile(datafile,"READ");
        TH1F *fSDM = new TH1F();
	if (file->IsZombie()){
	std::cout << "Error opening file " << datafile << std::endl;
        return fSDM;
	}
	else{
	fSDM = (TH1F*)file->Get(histoname);
	}
        return fSDM;

}


float TTMHelper::GetMistagrate (float pt, float eta)
{
	Int_t xBin = fQCD->GetXaxis()->FindBin(eta);
	Int_t yBin = fQCD->GetYaxis()->FindBin(pt);
	return fQCD->GetBinContent(xBin,yBin);
}

//get random number according to SDM distribution
// float TTMHelper::GetRndmSDM (void)
// {
// 	return fSDM->GetRandom();
// }
	
float TTMHelper::GetRndmSDM (TH1F* histo)
{
	return histo->GetRandom();
}


