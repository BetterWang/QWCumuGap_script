#include "../../style.h"

void splitCanv(TCanvas * c);
void initHist(TH2D* h);

void compare2(TString s1 = "grV2_pPb.root", TString s2 = "grV2_Pbp.root", TString str_gr = "grV4", TString fname = "comp_pPb_v24.pdf", TString str_leg1 = "pPb", TString str_leg2 = "Pbp")
{

	TFile * f1 = new TFile(s1.Data());
	TFile * f2 = new TFile(s2.Data());

	TGraphErrors * gr1 = (TGraphErrors*) f1->Get(str_gr.Data());
	TGraphErrors * gr2 = (TGraphErrors*) f2->Get(str_gr.Data());

	gr1->SetMarkerColor(kRed);
	gr1->SetLineColor(kRed);
	gr2->SetMarkerColor(kBlue);
	gr2->SetLineColor(kBlue);

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 600);
	splitCanv(cT);

	TH2D * hframe = new TH2D("hframe", ";p_{T} (GeV/c);v_{2}", 1, 0, 400, 1, 0.01, 0.14);
	initHist(hframe);
	TH2D * hframeR = new TH2D("hframeR", ";p_{T} (GeV/c);Ratio", 1, 0, 400, 1, 0.9, 1.09);
	initHist(hframeR);

	TLegend * legPt = new TLegend(0.5, 0.7, 0.85, 0.9);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(42);
	legPt->SetTextSize(0.06);
	legPt->SetBorderSize(0);

	legPt->AddEntry(gr1, str_leg1.Data(), "p"); 
	legPt->AddEntry(gr2, str_leg2.Data(), "p"); 

	cT->cd(1);
	hframe->Draw();
	gr1->Draw("Psame");
	gr2->Draw("Psame");
	legPt->Draw();
	cT->cd(2);
	TGraphErrors * grR = (TGraphErrors*) gr1->Clone("grR");
	grR->SetMarkerColor(kBlack);
	grR->SetLineColor(kBlack);
	for ( int i = 0; i < grR->GetN(); i++ ) {
		grR->GetY()[i] = gr1->GetY()[i] / gr2->GetY()[i];
		grR->GetEY()[i] = fabs( grR->GetY()[i] * sqrt( (gr1->GetEY()[i]/gr1->GetY()[i])*(gr1->GetEY()[i]/gr1->GetY()[i]) + (gr2->GetEY()[i]/gr2->GetY()[i])*(gr2->GetEY()[i]/gr2->GetY()[i]) ) );
	}
	hframeR->Draw();
	grR->Draw("Psame");

	cT->SaveAs(fname.Data());

}

void splitCanv(TCanvas * c)
{
	if (!c) return;

	c->cd(0);
	TPad * p1 = new TPad("pad1", "", 0., 0.4, 1., 1.);
	p1->SetLeftMargin(0.15);
	p1->SetRightMargin(0.05);
	p1->SetBottomMargin(0.);
	p1->SetTopMargin(0.05);
	p1->Draw();
	p1->SetNumber(1);

	TPad * p2 = new TPad("pad2", "", 0., 0.0, 1., 0.4);
	p2->SetLeftMargin(0.15);
	p2->SetRightMargin(0.05);
	p2->SetBottomMargin(0.25);
	p2->SetTopMargin(0.);
	p2->SetGrid();
	p2->Draw();
	p2->SetNumber(2);
}

void initHist(TH2D * h)
{
	h->GetXaxis()->SetLabelFont(43);
	h->GetXaxis()->SetLabelSize(20);
	h->GetXaxis()->SetLabelOffset(0.02);
	h->GetXaxis()->SetTitleFont(43);
	h->GetXaxis()->SetTitleSize(22);
	h->GetXaxis()->CenterTitle();
	h->GetXaxis()->SetNdivisions(505);
	h->GetXaxis()->SetTickLength(0.03);
	h->GetXaxis()->SetTitleOffset(3);

	h->GetYaxis()->SetLabelFont(43);
	h->GetYaxis()->SetLabelSize(20);
	h->GetYaxis()->SetLabelOffset(0.02);
	h->GetYaxis()->SetTitleFont(43);
	h->GetYaxis()->SetTitleSize(26);
	h->GetYaxis()->CenterTitle();
	h->GetYaxis()->SetNdivisions(505);
	h->GetYaxis()->SetTickLength(0.03);
	h->GetYaxis()->SetTitleOffset(1.5);
}
