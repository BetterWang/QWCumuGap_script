#include "label.h"
#include "noff.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include "../../style.h"

void genPlot(int s1 =0)
{
	int NCent = NCent8TeV4;
	const double * CentX = CentPPbX4;
	TFile *f;
	f = new TFile(Form("%s/outputE.root", ftxt[s1]));

	SetStyle();

	double dCn[7][20];
	double eCn[7][20];
	double dVn[7][20];
	double eVn[7][20];

	for ( int n = 2; n < 7; n++ ) {
		TH1D * hc = (TH1D*) f->Get(Form("hCnR%i", n));
		TH1D * hv = (TH1D*) f->Get(Form("hVnR%i", n));
		for ( int c = 0; c < 20; c++ ) {
			dCn[n][c] = hc->GetBinContent(c+1);
			eCn[n][c] = hc->GetBinError(c+1);
			dVn[n][c] = hv->GetBinContent(c+1);
			eVn[n][c] = hv->GetBinError(c+1);
		}
	}

	TGraphErrors * grCn[7] = {};
	TGraphErrors * grVn[7] = {};

	for ( int n = 2; n < 7; n++ ) {
		grCn[n] = new TGraphErrors(NCent, CentX, dCn[n], 0, eCn[n]);
		grVn[n] = new TGraphErrors(NCent, CentX, dVn[n], 0, eVn[n]);
		grCn[n]->SetMarkerStyle(kFullSquare);
		grCn[n]->SetMarkerColor(kGreen+2);
		grCn[n]->SetLineColor(kGreen+2);
		grVn[n]->SetMarkerStyle(kFullSquare);
		grVn[n]->SetMarkerColor(kGreen+2);
		grVn[n]->SetLineColor(kGreen+2);
	}

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);
	TH2D * hframe_cent = new TH2D("hframe_cent", "", 1, 0, 400, 1, 0, 0.35);
	InitHist(hframe_cent, "N_{trk}^{offline}", "v_{2}");
	for ( int n = 2; n < 7; n++ ) {
		cT->cd();
		hframe_cent->SetYTitle(Form("v_{%i}{4}", n));
		hframe_cent->Draw();
		grVn[n]->Draw("Psame");
		cT->SaveAs(Form("%s/v%i4.pdf", ftxt[s1], n));
	}

	TH2D * hframe_centC = new TH2D("hframe_centC", "", 1, 0, 400, 1, -0.000009, 0.000005);
	InitHist(hframe_centC, "N_{trk}^{offline}", "c_{2}");
	TLine * zero = new TLine(0., 0., 400., 0.);
	for ( int n = 2; n < 7; n++ ) {
		cT->cd();
		hframe_centC->SetYTitle(Form("c_{%i}{4}", n));
		hframe_centC->Draw();
		zero->Draw();
		grCn[n]->Draw("Psame");
		cT->SaveAs(Form("%s/c%i4.pdf", ftxt[s1], n));
	}
}