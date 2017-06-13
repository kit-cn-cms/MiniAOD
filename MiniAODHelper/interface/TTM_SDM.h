#ifndef TTM_SDM_H
#define TTM_SDM_H

#include <iostream>
#include <cstring>
#include <vector>

#include "TH1F.h"
#include "TH2F.h"
#include "TString.h"



class TTMHelper
{
	private:
		TH2F* fQCD{0};
// 		TH1F* fSDM{0};
                
                
	public:
		TTMHelper();
		void Load_QCDMistag(TString datafile,TString histoname);
// 		void Load_DisSDM(TString datafile,TString histoname);
		TH1F* Load_DisSDM(TString datafile,TString histoname);
		float GetMistagrate (float pt,float eta);
// 		float GetRndmSDM (void);
		float GetRndmSDM (TH1F* histo);
};


#endif
