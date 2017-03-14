#include "../../style.h"
#include "published.h"

void initHist(TH2D* h);

void plot(int n, int sMB, int sHM0, int sHM1, int sHM7)
{
	TFile * f = new TFile(Form("combined_%i_%i_%i_%i_%i.root", sMB, sHM0, sHM1, sHM7, n));

	published();

	double C4Low[7] = {
		0,		// 0
		0, 		// 1
		-0.00005,	// 2
		-0.0000005,	// 3
		-0.0000001,	// 4
		-0.00001,	// 5
		-0.00001,	// 6
	};

	double C4Up[7] = {
		0,		// 0
		0, 		// 1
		0.00005,	// 2
		0.000001,	// 3
		0.000001,	// 4
		0.00001,	// 5
		0.00001,	// 6
	};

	double C6Low[7] = {
		0,		// 0
		0, 		// 1
		-0.0000005,	// 2
		-0.0000005,	// 3
		-0.0000001,	// 4
		-0.00001,	// 5
		-0.00001,	// 6
	};

	double C6Up[7] = {
		0,		// 0
		0, 		// 1
		0.0000005,	// 2
		0.000001,	// 3
		0.000001,	// 4
		0.00001,	// 5
		0.00001,	// 6
	};

	double C8Low[7] = {
		0,		// 0
		0, 		// 1
		-0.000000005,	// 2
		-0.0000005,	// 3
		-0.0000001,	// 4
		-0.00001,	// 5
		-0.00001,	// 6
	};

	double C8Up[7] = {
		0,		// 0
		0, 		// 1
		0.000000005,	// 2
		0.000001,	// 3
		0.000001,	// 4
		0.00001,	// 5
		0.00001,	// 6
	};

	double VLow[7] = {
		0.01,		// 0
		0.01, 		// 1
		0.01,		// 2
		0.01,		// 3
		0.01,		// 4
		0.01,		// 5
		0.01,		// 6
	};

	double VUp[7] = {
		0,		// 0
		0, 		// 1
		0.14,		// 2
		0.05,		// 3
		0.05,		// 4
		0.0,		// 5
		0.0,		// 6
	};

	TGraphErrors * grCn = (TGraphErrors*) f->Get("grCn");
	TGraphErrors * grC4 = (TGraphErrors*) f->Get("grC4");
	TGraphErrors * grC6 = (TGraphErrors*) f->Get("grC6");
	TGraphErrors * grC8 = (TGraphErrors*) f->Get("grC8");

	TGraphErrors * grVn = (TGraphErrors*) f->Get("grVn");
	TGraphErrors * grV4 = (TGraphErrors*) f->Get("grV4");
	TGraphErrors * grV6 = (TGraphErrors*) f->Get("grV6");
	TGraphErrors * grV8 = (TGraphErrors*) f->Get("grV8");

	grV4->SetMarkerStyle(kFullSquare);
	grC4->SetMarkerStyle(kFullSquare);

	grCn->SetMarkerSize(2.0);
	grC4->SetMarkerSize(2.0);
	grC6->SetMarkerSize(2.0);
	grC8->SetMarkerSize(2.0);

	grVn->SetMarkerSize(2.0);
	grV4->SetMarkerSize(2.0);
	grV6->SetMarkerSize(2.0);
	grV8->SetMarkerSize(2.0);

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 600);
	TH2D * hframe = new TH2D("hframe", Form(";N_{trk}^{offline};v_{%i}",n), 1, 0, 399, 1, VLow[n], VUp[n]);
	initHist(hframe);

	hframe->Draw();

//	grVn->Draw("Psame");
//	mgr_pPb_v22.Draw();
//	mgr_pPb_v24.Draw();
//	mgr_pPb_v26.Draw();
//	mgr_pPb_v28.Draw();
	grV4->Draw("Psame");
	grV6->Draw("Psame");
	grV8->Draw("Psame");

	TLegend * leg = new TLegend(0.7, 0.7, 0.85, 0.9);
	leg->SetFillColor(kWhite);
	leg->SetTextFont(42);
	leg->SetTextSize(0.06);
	leg->SetBorderSize(0);
	leg->AddEntry(grV4, Form("v_{%i}{4}", n), "p");
	leg->AddEntry(grV6, Form("v_{%i}{6}", n), "p");
	leg->AddEntry(grV8, Form("v_{%i}{8}", n), "p");
	leg->Draw();

	TCanvas * cTC4 = MakeCanvas("cTC4", "cTC4", 600, 600);
	TH2D * hframeC4 = new TH2D("hframeC4", Form(";N_{trk}^{offline};c_{%i}{4}",n), 1, 0, 399, 1, C4Low[n], C4Up[n]);
	initHist(hframeC4);
	hframeC4->Draw();
	TLine *l0 = new TLine(0, 0, 399, 0);
	l0->Draw();
//	grCn->Draw("Psame");
	grC4->Draw("Psame");

	TLegend * legC4 = new TLegend(0.5, 0.7, 0.85, 0.9);
	legC4->SetFillColor(kWhite);
	legC4->SetTextFont(42);
	legC4->SetTextSize(0.06);
	legC4->SetBorderSize(0);
	legC4->AddEntry(grC4, Form("c_{%i}{4}", n), "p");
	legC4->Draw();

	TCanvas * cTC6 = MakeCanvas("cTC6", "cTC6", 600, 600);
	TH2D * hframeC6 = new TH2D("hframeC6", Form(";N_{trk}^{offline};c_{%i}{6}",n), 1, 0, 399, 1, C6Low[n], C6Up[n]);
	initHist(hframeC6);
	hframeC6->Draw();
	l0->Draw();
	grC6->Draw("Psame");

	TLegend * legC6 = new TLegend(0.5, 0.7, 0.85, 0.9);
	legC6->SetFillColor(kWhite);
	legC6->SetTextFont(42);
	legC6->SetTextSize(0.06);
	legC6->SetBorderSize(0);
	legC6->AddEntry(grC6, Form("c_{%i}{6}", n), "p");
	legC6->Draw();

	TCanvas * cTC8 = MakeCanvas("cTC8", "cTC8", 600, 600);
	TH2D * hframeC8 = new TH2D("hframeC8", Form(";N_{trk}^{offline};c_{%i}{8}",n), 1, 0, 399, 1, C8Low[n], C8Up[n]);
	initHist(hframeC8);
	hframeC8->Draw();
	l0->Draw();
	grC8->Draw("Psame");

	TLegend * legC8 = new TLegend(0.5, 0.7, 0.85, 0.9);
	legC8->SetFillColor(kWhite);
	legC8->SetTextFont(42);
	legC8->SetTextSize(0.06);
	legC8->SetBorderSize(0);
	legC8->AddEntry(grC8, Form("c_{%i}{8}", n), "p");
	legC8->Draw();
}

void initHist(TH2D * h)
{
	h->GetXaxis()->CenterTitle();
	h->GetXaxis()->SetTitleOffset(1.3);

	h->GetYaxis()->CenterTitle();
	h->GetYaxis()->SetTitleOffset(1.3);

//	h->GetXaxis()->SetLabelFont(43);
//	h->GetXaxis()->SetLabelSize(20);
//	h->GetXaxis()->SetLabelOffset(0.02);
//	h->GetXaxis()->SetTitleFont(43);
//	h->GetXaxis()->SetTitleSize(22);
//	h->GetXaxis()->SetNdivisions(505);
//	h->GetXaxis()->SetTickLength(0.03);
//	h->GetXaxis()->SetTitleOffset(3);
//
//	h->GetYaxis()->SetLabelFont(43);
//	h->GetYaxis()->SetLabelSize(20);
//	h->GetYaxis()->SetLabelOffset(0.02);
//	h->GetYaxis()->SetTitleFont(43);
//	h->GetYaxis()->SetTitleSize(26);
//	h->GetYaxis()->CenterTitle();
//	h->GetYaxis()->SetNdivisions(505);
//	h->GetYaxis()->SetTickLength(0.03);
//	h->GetYaxis()->SetTitleOffset(1.5);
}
