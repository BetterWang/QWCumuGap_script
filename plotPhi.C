#include "../../style.h"
#include "label.h"

void plotPhi()
{
	SetStyle();
//	TFile * facc = new TFile("noff_pPb16_PhiAcc.root");
//	TH1D * hHole  = (TH1D*) facc->Get("vectPhi120/hc");
//	TH1D * hHoleW = (TH1D*) facc->Get("vectPhiW120/hc");
	TFile * facc = new TFile("noff_PbPb15_ppreco_MB67.root");
	TH1D * hHole  = (TH1D*) facc->Get("vectGMOPhi/hc");
	TH1D * hHoleW = (TH1D*) facc->Get("vectGMOPhiAccW/hc");


	TCanvas * cPhi = MakeCanvas("cPhi", "cPhi", 500, 500);

	InitHist(hHoleW, "#phi", "count");

	hHole->SetLineColor(kRed);
	hHoleW->SetLineColor(kBlue);

	hHoleW->SetMinimum(0);
	hHoleW->Draw("hist");
	hHole->Draw("histsame");
	cPhi->SaveAs("PbPb15_phi.pdf");
}
