#include "../../style.h"
#include "HIN-16-022.h"

void splitCanv(TCanvas * c);
void initHist(TH2D* h);

void compareTF3()
{

	HIN_16_022();

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 600);
	splitCanv(cT);

	TH2D * hframe = new TH2D("hframe", ";N_{trk}^{offline};v_{3}", 1, 0, 399, 1, 0, 0.14);
	initHist(hframe);
	TH2D * hframeR = new TH2D("hframeR", ";N_{trk}^{offline};Ratio", 1, 0, 399, 1, 0.89, 1.09);
	initHist(hframeR);

	TLegend * legPt = new TLegend(0.5, 0.5, 0.85, 0.9);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(42);
	legPt->SetTextSize(0.06);
	legPt->SetBorderSize(0);


	TLine * l0 = new TLine(0, 0, 399, 0);
	cT->cd(1);
	hframe->Draw();
	l0->Draw();
	TGraphErrors * gr1 = grHIN16022pPbV3;
	TGraphErrors * gr2 = grHIN16022PbPbV3;
	TGraphErrors * gr3 = grHIN16022pPbV3sub;
	TGraphErrors * gr4 = grHIN16022PbPbV3sub;
	TF1 * func1 = fHIN16022pPbV3;
	TF1 * func2 = fHIN16022PbPbV3;
	TF1 * func3 = fHIN16022pPbV3sub;
	TF1 * func4 = fHIN16022PbPbV3sub;

	gr1->SetMarkerColor(kRed);
	gr2->SetMarkerColor(kBlue);
	gr3->SetMarkerColor(kBlack);
	gr4->SetMarkerColor(kGreen);
	func1->SetLineColor(kRed);
	func2->SetLineColor(kBlue);
	func3->SetLineColor(kBlack);
	func4->SetLineColor(kGreen);

	legPt->AddEntry(gr1, "pPb v_{3}{2}", "p");
	legPt->AddEntry(gr3, "pPb v_{3}^{sub}{2}", "p");
	legPt->AddEntry(gr2, "PbPb v_{3}{2}", "p");
	legPt->AddEntry(gr4, "PbPb v_{3}^{sub}{2}", "p");

	gr1->Draw("Psame");
	gr2->Draw("Psame");
	gr3->Draw("Psame");
	gr4->Draw("Psame");
	func1->Draw("lsame");
	func2->Draw("lsame");
	func3->Draw("lsame");
	func4->Draw("lsame");
//	grHIN16022pPbV3int->Draw("[]3");
//	grHIN16022PbPbV3int->Draw("[]3");
	legPt->Draw();
	cT->cd(2);

	TGraphErrors * grR1 = (TGraphErrors*) gr1->Clone("grR1");
	TGraphErrors * grR2 = (TGraphErrors*) gr2->Clone("grR2");
	TGraphErrors * grR3 = (TGraphErrors*) gr3->Clone("grR3");
	TGraphErrors * grR4 = (TGraphErrors*) gr4->Clone("grR4");

	for ( int i = 0; i < grR1->GetN(); i++ ) {
		grR1->GetY()[i] = gr1->GetY()[i] / func1->Eval(gr1->GetX()[i]);
		grR1->GetEY()[i] = gr1->GetEY()[i] / func1->Eval(gr1->GetX()[i]);
	}

	for ( int i = 0; i < grR2->GetN(); i++ ) {
		grR2->GetY()[i] = gr2->GetY()[i] / func2->Eval(gr2->GetX()[i]);
		grR2->GetEY()[i] = gr2->GetEY()[i] / func2->Eval(gr2->GetX()[i]);
	}

	for ( int i = 0; i < grR3->GetN(); i++ ) {
		grR3->GetY()[i] = gr3->GetY()[i] / func3->Eval(gr3->GetX()[i]);
		grR3->GetEY()[i] = gr3->GetEY()[i] / func3->Eval(gr3->GetX()[i]);
	}

	for ( int i = 0; i < grR4->GetN(); i++ ) {
		grR4->GetY()[i] = gr4->GetY()[i] / func4->Eval(gr4->GetX()[i]);
		grR4->GetEY()[i] = gr4->GetEY()[i] / func4->Eval(gr4->GetX()[i]);
	}

	hframeR->Draw();
	grR1->Draw("PLsame");
	grR2->Draw("PLsame");
	grR3->Draw("PLsame");
	grR4->Draw("PLsame");

	cT->SaveAs("v3func.pdf");
}

void splitCanv(TCanvas * c)
{
	if (!c) return;

	c->cd(0);
	TPad * p1 = new TPad("pad1", "", 0., 0.4, 1., 1.);
	p1->SetLeftMargin(0.15);
	p1->SetRightMargin(0.05);
	p1->SetBottomMargin(0.);
	p1->SetTopMargin(0.07);
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
