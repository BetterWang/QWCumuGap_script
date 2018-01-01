#include "../../style.h"
#include "label.h"

void plotToy()
{
	SetStyle();
	int s1 = 404;
	int s2 = 405;
	int s3 = 406;
	TH1D * h21 = new TH1D("h21", "h21", 3, 0, 3);
	TH1D * h31 = new TH1D("h31", "h31", 3, 0, 3);

	InitHist(h21, "", "v_{n}");

	h21->SetMarkerStyle(kFullSquare);
	h31->SetMarkerStyle(kFullCircle);
	h21->SetMarkerColor(kBlack);
	h31->SetMarkerColor(kBlack);
	h21->SetLineColor(kBlack);
	h31->SetLineColor(kBlack);
	h21->SetMarkerSize(2);
	h31->SetMarkerSize(2);


	TH1D * h22 = (TH1D*) h21->Clone("h22");
	TH1D * h23 = (TH1D*) h21->Clone("h23");

	TH1D * h32 = (TH1D*) h31->Clone("h32");
	TH1D * h33 = (TH1D*) h31->Clone("h33");

	h22->SetMarkerColor(kBlue);
	h32->SetMarkerColor(kBlue);
	h22->SetLineColor(kBlue);
	h32->SetLineColor(kBlue);

	h23->SetMarkerColor(kRed);
	h33->SetMarkerColor(kRed);
	h23->SetLineColor(kRed);
	h33->SetLineColor(kRed);


	TFile * f1 = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	TFile * f2 = new TFile(Form("%s/outGraph.root", ftxt[s2]));
	TFile * f3 = new TFile(Form("%s/outGraph.root", ftxt[s3]));

	TGraphErrors * gr21 = (TGraphErrors*) f1->Get("grV42");
	TGraphErrors * gr22 = (TGraphErrors*) f2->Get("grV42");
	TGraphErrors * gr23 = (TGraphErrors*) f3->Get("grV42");

	TGraphErrors * gr31 = (TGraphErrors*) f1->Get("grV43");
	TGraphErrors * gr32 = (TGraphErrors*) f2->Get("grV43");
	TGraphErrors * gr33 = (TGraphErrors*) f3->Get("grV43");

	h21->SetBinContent(1, gr21->GetY()[11]);
	h22->SetBinContent(2, gr22->GetY()[11]);
	h23->SetBinContent(3, gr23->GetY()[11]);
	h31->SetBinContent(1, gr31->GetY()[11]);
	h32->SetBinContent(2, gr32->GetY()[11]);
	h33->SetBinContent(3, gr33->GetY()[11]);

	h21->SetBinError(1, gr21->GetEY()[11]);
	h22->SetBinError(2, gr22->GetEY()[11]);
	h23->SetBinError(3, gr23->GetEY()[11]);
	h31->SetBinError(1, gr31->GetEY()[11]);
	h32->SetBinError(2, gr32->GetEY()[11]);
	h33->SetBinError(3, gr33->GetEY()[11]);

	h21->GetXaxis()->SetBinLabel(1, "Ideal");
	h21->GetXaxis()->SetBinLabel(2, "AccHole Corrected");
	h21->GetXaxis()->SetBinLabel(3, "AccHole");


	TCanvas * c = MakeCanvas("c", "c", 500, 500);
	c->SetBottomMargin(0.2);

	TLine * lv2 = new TLine(0., 0.06, 3., 0.06);
	TLine * lv3 = new TLine(0., 0.02, 3., 0.02);

	h21->GetXaxis()->SetLabelSize(0.08);
	h21->GetXaxis()->SetLabelOffset(0.01);

	h21->SetMinimum(0.0);
	h21->SetMaximum(0.07);

	h21->Draw("p");
	h31->Draw("same");

	h22->Draw("same");
	h32->Draw("same");
	h23->Draw("same");
	h33->Draw("same");

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

