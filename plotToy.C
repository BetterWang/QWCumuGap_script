#include "../../style.h"
#include "label.h"

void plotToy()
{
	SetStyle();
	int s1 = 404;
	int s2 = 405;
	int s3 = 406;
	TH1D * h2 = new TH1D("h2", "h2", 3, 0, 3);
	TH1D * h3 = new TH1D("h3", "h3", 3, 0, 3);

	TFile * f1 = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	TFile * f2 = new TFile(Form("%s/outGraph.root", ftxt[s2]));
	TFile * f3 = new TFile(Form("%s/outGraph.root", ftxt[s3]));

	TGraphErrors * gr21 = (TGraphErrors*) f1->Get("grV42");
	TGraphErrors * gr22 = (TGraphErrors*) f2->Get("grV42");
	TGraphErrors * gr23 = (TGraphErrors*) f3->Get("grV42");

	TGraphErrors * gr31 = (TGraphErrors*) f1->Get("grV43");
	TGraphErrors * gr32 = (TGraphErrors*) f2->Get("grV43");
	TGraphErrors * gr33 = (TGraphErrors*) f3->Get("grV43");

	h2->SetBinContent(1, gr21->GetY()[11]);
	h2->SetBinContent(2, gr22->GetY()[11]);
	h2->SetBinContent(3, gr23->GetY()[11]);
	h3->SetBinContent(1, gr31->GetY()[11]);
	h3->SetBinContent(2, gr32->GetY()[11]);
	h3->SetBinContent(3, gr33->GetY()[11]);

	h2->SetBinError(1, gr21->GetEY()[11]);
	h2->SetBinError(2, gr22->GetEY()[11]);
	h2->SetBinError(3, gr23->GetEY()[11]);
	h3->SetBinError(1, gr31->GetEY()[11]);
	h3->SetBinError(2, gr32->GetEY()[11]);
	h3->SetBinError(3, gr33->GetEY()[11]);

	h2->GetXaxis()->SetBinLabel(1, "Ideal");
	h2->GetXaxis()->SetBinLabel(2, "AccHole Corrected");
	h2->GetXaxis()->SetBinLabel(3, "AccHole");


	TCanvas * c = MakeCanvas("c", "c", 500, 500);
	InitHist(h2, "", "v_{n}");
	c->SetBottomMargin(0.2);

	TLine * lv2 = new TLine(0., 0.06, 3., 0.06);
	TLine * lv3 = new TLine(0., 0.02, 3., 0.02);

	h2->GetXaxis()->SetLabelSize(0.08);
	h2->GetXaxis()->SetLabelOffset(0.01);

	h2->SetMarkerStyle(kFullSquare);
	h3->SetMarkerStyle(kFullCircle);
	h2->SetMarkerColor(kBlue);
	h3->SetMarkerColor(kRed);
	h2->SetLineColor(kBlue);
	h3->SetLineColor(kRed);
	h2->SetMarkerSize(2);
	h3->SetMarkerSize(2);

	h2->SetMinimum(0.0);
	h2->SetMaximum(0.07);
	h2->Draw("p");
	h3->Draw("same");

	lv2->SetLineColor(kBlack);
	lv3->SetLineColor(kBlack);

	lv2->SetLineStyle(kDashed);
	lv3->SetLineStyle(kDashed);

	lv2->Draw("lsame");
	lv3->Draw("lsame");

	c->SaveAs("Hole.pdf");

	TCanvas * cPhi = MakeCanvas("cPhi", "cPhi", 500, 500);
	TFile * facc = new TFile("AccHole.root");
	TH1D * hIdeal = (TH1D*) facc->Get("vectPhi/hc");
	TH1D * hHole  = (TH1D*) facc->Get("vectPhiAcc/hc");
	TH1D * hHoleW = (TH1D*) facc->Get("vectPhiAccW/hc");

	InitHist(hIdeal, "#phi", "count");

	hIdeal->SetLineColor(kBlack);
	hHole->SetLineColor(kRed);
	hHoleW->SetLineColor(kBlue);

	hIdeal->SetMinimum(0);
	hIdeal->Draw("hist");
	hHole->Draw("histsame");
	hHoleW->Draw("histsame");
	cPhi->SaveAs("phi.pdf");
}

