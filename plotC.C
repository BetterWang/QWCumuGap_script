#include "../../style.h"
#include "HIN-16-022.h"
#include "HIN-14-006.h"
#include "theory.h"
#include "published.h"

TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
TColor *green = new TColor(3002, 0, 1, 0, "green", 0.4);
TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);

void splitCanv(TCanvas * c);

typedef struct
{
	TGraphErrors * grCn;
	TGraphErrors * grVn;
	TGraphErrors * grC4;
	TGraphErrors * grV4;
	TGraphErrors * grC6;
	TGraphErrors * grV6;
	TGraphErrors * grC8;
	TGraphErrors * grV8;
	TGraphErrors * grV64;
	TGraphErrors * grV86;
	TGraphErrors * grV4V2;
	TGraphErrors * grV4V2sub;
} VnGraph;

void overRideE(TGraphErrors* gr, TGraphErrors* gr1, TGraphErrors* gr2)
{
	for ( int i = 0; i < gr->GetN(); i++ ) {
		double x = gr->GetX()[i];
		double y1 = 0;
		double e1 = 0;
		double y2 = 0;
		double e2 = 0;
		for ( int j = 0; j < gr1->GetN(); j++ ) {
			if ( fabs( gr1->GetX()[j]-x ) < 1. ) {
				y1 = gr1->GetY()[j];
				e1 = gr1->GetEY()[j];
			}
		}

		for ( int j = 0; j < gr2->GetN(); j++ ) {
			if ( fabs( gr2->GetX()[j]-x ) < 1. ) {
				y2 = gr2->GetY()[j];
				e2 = gr2->GetEY()[j];
			}
		}

		gr->GetY()[i] = y1/y2;
		gr->GetEY()[i] = sqrt(e1*e1/y1/y1 + e2*e2/y2/y2) * y2 / y1;
	}
}

void getGraph(TFile * f, VnGraph &gr, int n)
{
	gr.grCn = (TGraphErrors*) f->Get(Form("grC%in", n));
	gr.grVn = (TGraphErrors*) f->Get(Form("grV%in", n));

	gr.grC4 = (TGraphErrors*) f->Get(Form("grC%i4", n));
	gr.grV4 = (TGraphErrors*) f->Get(Form("grV%i4", n));

	gr.grC6 = (TGraphErrors*) f->Get(Form("grC%i6", n));
	gr.grV6 = (TGraphErrors*) f->Get(Form("grV%i6", n));

	gr.grC8 = (TGraphErrors*) f->Get(Form("grC%i8", n));
	gr.grV8 = (TGraphErrors*) f->Get(Form("grV%i8", n));

	gr.grV64 = (TGraphErrors*) f->Get(Form("grV%i64", n));
	gr.grV86 = (TGraphErrors*) f->Get(Form("grV%i86", n));

	if ( gr.grV64 != 0 ) {
		if ( gr.grV64->GetN() != gr.grV6->GetN() ) {
			cout << "#V64 != #V6" << endl;
		}

		overRideE(gr.grV64, gr.grV6, gr.grV4);
	}
	if ( gr.grV86 != 0 ) {
		if ( not gr.grV86 and gr.grV86->GetN() != gr.grV8->GetN() ) {
			cout << "#V86 != #V8" << endl;
		}

		overRideE(gr.grV86, gr.grV8, gr.grV6);
	}

	gr.grV4V2= (TGraphErrors*) f->Get(Form("grV4V2%i", n));
	gr.grV4V2sub= (TGraphErrors*) f->Get(Form("grV4V2sub%i", n));
}

TGraphErrors * negGr(TGraphErrors * gr)
{
	TGraphErrors * ret = (TGraphErrors*) gr->Clone();
	for ( int i = 0; i < gr->GetN(); i++ ) {
		ret->GetY()[i] = -1 * ret->GetY()[i];
	}
	return ret;
}

TGraphErrors * sysGr(TGraphErrors * gr, double sys, int k = 3001)
{
	TGraphErrors * ret = (TGraphErrors*) gr->Clone();
	for ( int i = 0; i < ret->GetN(); i++ ) {
		ret->GetEY()[i] = ret->GetY()[i] * sys;
		ret->GetEX()[i] = 0.15;
	}
	ret->SetFillColor(k);
	return ret;
}

TGraphErrors * sysGr2(TGraphErrors * gr, double sysX, double sysY, int k = 3001)
{
	TGraphErrors * ret = (TGraphErrors*) gr->Clone();
	for ( int i = 0; i < ret->GetN(); i++ ) {
		ret->GetEY()[i] = ret->GetY()[i] * sysY;
		ret->GetEX()[i] = ret->GetX()[i] * sysX;
	}
	ret->SetFillColor(k);
	return ret;
}


TGraphErrors * ratioGr(TGraphErrors* gr1, TGraphErrors* gr2)
{
	TGraphErrors * ret = (TGraphErrors*) gr1->Clone();

	for ( int i = 0; i < ret->GetN(); i++ ) {
		double x1 = gr1->GetX()[i];
		double y2 = -1;
		double e2 = -1;

		for ( int j = 0; j < gr2->GetN(); j++ ) {
			if ( fabs( gr2->GetX()[j] - x1) < 1. ) {
				y2 = gr2->GetY()[j];
				e2 = gr2->GetEY()[j];
			}
		}

		ret->GetX()[i] = y2;
		ret->GetEX()[i] = e2;
	}

	return ret;
}

void plotC(TString s2pPb = "grV2_merged.root",
		TString s3pPb = "grV3_merged.root",
		TString s2PbPb = "grV2PbPb_GMO.root",
		TString s3PbPb = "grV3PbPb_GMO.root",
		TString s2pp = "grV2_pp13.root",
		TString s3pp = "grV3_pp13.root")
{
	TFile *f2pPb = new TFile(s2pPb.Data());
	TFile *f3pPb = new TFile(s3pPb.Data());
	TFile *f2PbPb = new TFile(s2PbPb.Data());
	TFile *f3PbPb = new TFile(s3PbPb.Data());
	TFile *f2pp = new TFile(s2pp.Data());
	TFile *f3pp = new TFile(s3pp.Data());

	HIN_16_022();
	HIN_14_006();
	theory();
	published();

	VnGraph grPA2;
	VnGraph grPA3;
	VnGraph grAA2;
	VnGraph grAA3;
	VnGraph grPP2;
	VnGraph grPP3;

	getGraph( f2pPb, grPA2, 2 );
	getGraph( f3pPb, grPA3, 3 );
	getGraph( f2PbPb, grAA2, 2 );
	getGraph( f3PbPb, grAA3, 3 );
	getGraph( f2pp, grPP2, 2 );
	getGraph( f3pp, grPP3, 3 );

	grAA2.grC4->SetMarkerStyle(kFullSquare);
	grAA3.grC4->SetMarkerStyle(kFullSquare);

	TLatex latexB;
	latexB.SetTextFont(43);
	latexB.SetTextSize(24);
	latexB.SetTextAlign(13);
	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	TCanvas * cC = MakeCanvas("cC", "cC", 900, 500);
//	makeMultiPanelCanvas(cC, 2, 1);
	TLine *l0 = new TLine(0, 0, 399, 0);

	cC->Divide(2, 1);
	TH2D * hframeC2 = new TH2D("hframeC2", "", 1, 0, 399, 1, -0.00009, 0.00005);
	InitHist(hframeC2, "N_{trk}^{offline}", "c_{2}{4}");

	TH2D * hframeC3 = new TH2D("hframeC3", "", 1, 0, 399, 1, -0.0000005, 0.000001);
	InitHist(hframeC3, "N_{trk}^{offline}", "c_{3}{4}");

	auto p = cC->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2->Draw();
	l0->Draw();
	grPA2.grC4->Draw("Psame");
	grAA2.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS Preliminary}");
	latexS.DrawLatexNDC(0.30, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	p = cC->cd(2);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3->Draw();
	l0->Draw();
	grPA3.grC4->Draw("Psame");
	grAA3.grC4->Draw("Psame");

	TLegend * legC = new TLegend(0.4, 0.75, 0.85, 0.9);
	legC->SetFillColor(kWhite);
	legC->SetTextFont(42);
	legC->SetTextSize(0.06);
	legC->SetBorderSize(0);

	legC->AddEntry(grPA3.grC4, "pPb 8.16 TeV", "p");
	legC->AddEntry(grAA3.grC4, "PbPb 5.02 TeV", "p");
	legC->Draw();

	///////////////////////////
	TCanvas * cCgap = MakeCanvas("cCgap", "cCgap", 1500, 500);
//	makeMultiPanelCanvas(cC, 2, 1);

	cCgap->Divide(3, 1);


	TH2D * hframeC2pp = new TH2D("hframeC2pp", "", 1, 0, 399, 1, -0.000019, 0.00001);
	InitHist(hframeC2pp, "N_{trk}^{offline}", "c_{2}{4}");
	p = cCgap->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2pp->Draw();
	l0->Draw();
	grPP2.grCn->Draw("Psame");
	grPP2.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS} Preliminary");
	latexS.DrawLatexNDC(0.30, 0.85, "pp #sqrt{s} = 13 TeV");

	p = cCgap->cd(2);
	TH2D * hframeC2pA = new TH2D("hframeC2pA", "", 1, 0, 399, 1, -0.000019, 0.00002);
	InitHist(hframeC2pA, "N_{trk}^{offline}", "c_{2}{4}");
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2pA->Draw();
	l0->Draw();
	grPA2.grCn->Draw("Psame");
	grPA2.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");
	latexS.DrawLatexNDC(0.30, 0.85, "pPb #sqrt{s_{NN}} = 8.16 TeV");

	p = cCgap->cd(3);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC2->Draw();
	l0->Draw();
	grAA2.grCn->Draw("Psame");
	grAA2.grC4->Draw("Psame");
	latexS.DrawLatexNDC(0.30, 0.85, "PbPb #sqrt{s_{NN}} = 5.02 TeV");

	TLegend * legCgap = new TLegend(0.2, 0.25, 0.45, 0.4);
	legCgap->SetFillColor(kWhite);
	legCgap->SetTextFont(42);
	legCgap->SetTextSize(0.06);
	legCgap->SetBorderSize(0);

	legCgap->AddEntry(grPP2.grCn, "c_{2}{4} 3-sub", "p");
	legCgap->AddEntry(grAA2.grC4, "c_{2}{4}", "p");
	legCgap->Draw();

	///////////////////////////

	TCanvas * cCgap3 = MakeCanvas("cCgap3", "cCgap3", 1500, 500);
//	makeMultiPanelCanvas(cC, 2, 1);

	cCgap3->Divide(3, 1);


	TH2D * hframeC3pp = new TH2D("hframeC3pp", "", 1, 0, 399, 1, -0.00001, 0.00001);
	InitHist(hframeC3pp, "N_{trk}^{offline}", "c_{3}{4}");
	p = cCgap3->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3pp->Draw();
	l0->Draw();
	grPP3.grCn->Draw("Psame");
	grPP3.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS} Preliminary");
	latexS.DrawLatexNDC(0.30, 0.85, "pp #sqrt{s} = 13 TeV");

	p = cCgap3->cd(2);
	TH2D * hframeC3pA = new TH2D("hframeC3pA", "", 1, 0, 399, 1, -0.0000019, 0.000005);
	InitHist(hframeC3pA, "N_{trk}^{offline}", "c_{3}{4}");
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3pA->Draw();
	l0->Draw();
	grPA3.grCn->Draw("Psame");
	grPA3.grC4->Draw("Psame");

	latexS.DrawLatexNDC(0.30, 0.92, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");
	latexS.DrawLatexNDC(0.30, 0.85, "pPb #sqrt{s_{NN}} = 8.16 TeV");

	p = cCgap3->cd(3);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeC3->Draw();
	l0->Draw();
	grAA3.grCn->Draw("Psame");
	grAA3.grC4->Draw("Psame");
	latexS.DrawLatexNDC(0.30, 0.85, "PbPb #sqrt{s_{NN}} = 5.02 TeV");

	TLegend * legCgap3 = new TLegend(0.2, 0.25, 0.45, 0.4);
	legCgap3->SetFillColor(kWhite);
	legCgap3->SetTextFont(42);
	legCgap3->SetTextSize(0.06);
	legCgap3->SetBorderSize(0);

	legCgap3->AddEntry(grPP2.grCn, "c_{3}{4} 3-sub", "p");
	legCgap3->AddEntry(grAA2.grC4, "c_{3}{4}", "p");
	legCgap3->Draw();

	////gap///////////////////////////
	TCanvas * cV = MakeCanvas("cV", "cV", 900, 500);
//	makeMultiPanelCanvas(cC, 2, 1);
	cV->Divide(2, 1);

	TH2D * hframeVn = new TH2D("hframeVn", "", 1, 1, 399, 1, 0.0001, 0.14);
	InitHist(hframeVn, "N_{trk}^{offline}", "v_{n}");

	grPA3.grV4->SetMarkerStyle(kOpenCircle);
	grAA3.grV4->SetMarkerStyle(kOpenCircle);

	p = cV->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeVn->Draw();
	grPA2.grV4->Draw("Psame");
	grPA3.grV4->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV = new TLegend(0.4, 0.55, 0.85, 0.7);
	legV->SetFillColor(kWhite);
	legV->SetTextFont(42);
	legV->SetTextSize(0.06);
	legV->SetBorderSize(0);

	legV->AddEntry(grPA2.grV4, "v_{2}{4}", "p");
	legV->AddEntry(grAA3.grV4, "v_{3}{4}", "p");
	legV->Draw();

	p = cV->cd(2);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);
	hframeVn->Draw();
	grAA2.grV4->Draw("Psame");
	grAA3.grV4->Draw("Psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	////////////////////////////////////
	TCanvas * cVn = MakeCanvas("cVn", "cVn", 800, 500);
	makeMultiPanelCanvas(cVn, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	p = cVn->cd(1);
	p->SetTopMargin(0.06);
	hframeVn->Draw();

	grPA3.grV4->SetMarkerStyle(kMultiply);
	grHIN16022pPbV3sub->SetMarkerStyle(kMultiply);
	grHIN16022pPbV3sub->SetMarkerColor(kGreen);
	grHIN16022pPbV3sub->SetLineColor(kGreen);
	grHIN16022pPbV3->SetLineColor(kGreen);
	grHIN16022pPbV3->SetMarkerStyle(kMultiply);

	TGraphErrors * grPAV24sys = sysGr(grPA2.grV4, 0.01 , 3003);
	TGraphErrors * grPAV26sys = sysGr(grPA2.grV6, 0.013, 3003);
	TGraphErrors * grPAV28sys = sysGr(grPA2.grV8, 0.024, 3001);

	TGraphErrors * grPAV34sys = sysGr(grPA3.grV4, 0.05, 3003);

	TGraphErrors * grHIN16022pPbV2sys = sysGr(grHIN16022pPbV2sub, 0.018, 3001);
	TGraphErrors * grHIN16022pPbV3sys = sysGr(grHIN16022pPbV3sub, 0.018, 3002);

	grPAV24sys->Draw("[]3");
	grPAV26sys->Draw("[]3");
	grPAV28sys->Draw("[]3");
	grPAV34sys->Draw("[]3");

	grHIN16022pPbV2sys->Draw("[]3");
	grHIN16022pPbV3sys->Draw("[]3");

	grPA2.grV4->Draw("Psame");
	grPA2.grV6->Draw("Psame");
	grPA2.grV8->Draw("Psame");

	gr1405_3976v34->Draw("lsame");

	grPA3.grV4->SetMarkerSize(1.5);
	grPA3.grV4->Draw("Psame");
	grHIN16022pPbV2sub->Draw("Psame");
	grHIN16022pPbV3sub->Draw("Psame");
	grHIN16022pPbV2->Draw("lxsame");
	grHIN16022pPbV3->Draw("lxsame");

//	grHIN14006pPbV26->Draw("Psame");
//	grHIN14006pPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
	latexS.DrawLatexNDC(0.68, 1.0, "pPb 8.16 TeV");
//	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV2 = new TLegend(0.18, 0.60, 0.60, 0.93);
	legV2->SetFillColor(kWhite);
	legV2->SetTextFont(42);
	legV2->SetTextSize(0.05);
	legV2->SetBorderSize(0);

	legV2->AddEntry(grPA2.grV4, "v_{2}{4}", "p");
	legV2->AddEntry(grPA2.grV6, "v_{2}{6}", "p");
	legV2->AddEntry(grPA2.grV8, "v_{2}{8}", "p");
	legV2->AddEntry(grPA3.grV4, "v_{3}{4}", "p");
	legV2->AddEntry(gr1405_3976v34, "v_{3}{4} hydro 5.02 TeV", "l");
	legV2->Draw();

	TLegend * legV21 = new TLegend(0.58, 0.68, 0.90, 0.93);
	legV21->SetFillColor(kWhite);
	legV21->SetTextFont(42);
	legV21->SetTextSize(0.05);
	legV21->SetBorderSize(0);

	legV21->AddEntry(grHIN16022PbPbV2sub, "v_{2}^{sub}{2, |#Delta#eta|>2}", "p");
	legV21->AddEntry(grHIN16022PbPbV2, "v_{2}{2, |#Delta#eta|>2}", "l");
	legV21->AddEntry(grHIN16022PbPbV3sub, "v_{3}^{sub}{2, |#Delta#eta|>2}", "p");
	legV21->AddEntry(grHIN16022PbPbV3, "v_{3}{2, |#Delta#eta|>2}", "l");
	legV21->Draw();

	p = cVn->cd(2);
	p->SetTopMargin(0.06);
	hframeVn->Draw();

	grAA3.grV4->SetMarkerStyle(kMultiply);
	grHIN16022PbPbV3sub->SetMarkerStyle(kMultiply);
	grHIN16022PbPbV3sub->SetMarkerColor(kGreen);
	grHIN16022PbPbV3sub->SetLineColor(kGreen);
	grHIN16022PbPbV3->SetLineColor(kGreen);

	TGraphErrors * grAAV24sys = sysGr(grAA2.grV4, 0.01, 3003);
	TGraphErrors * grAAV26sys = sysGr(grAA2.grV6, 0.01, 3003);
	TGraphErrors * grAAV28sys = sysGr(grAA2.grV8, 0.01, 3001);

	TGraphErrors * grAAV34sys = sysGr(grAA3.grV4, 0.03, 3003);

	TGraphErrors * grHIN16022PbPbV2sys = sysGr(grHIN16022PbPbV2sub, 0.018, 3001);
	TGraphErrors * grHIN16022PbPbV3sys = sysGr(grHIN16022PbPbV3sub, 0.018, 3002);

	grAAV24sys->Draw("[]3");
	grAAV26sys->Draw("[]3");
	grAAV28sys->Draw("[]3");
	grAAV34sys->Draw("[]3");

	grHIN16022PbPbV2sys->Draw("[]3");
	grHIN16022PbPbV3sys->Draw("[]3");

	grAA2.grV4->Draw("Psame");
	grAA2.grV6->Draw("Psame");
	grAA2.grV8->Draw("Psame");

	grAA3.grV4->SetMarkerSize(1.5);
	grAA3.grV4->Draw("Psame");
	grHIN16022PbPbV2sub->Draw("Psame");
	grHIN16022PbPbV3sub->Draw("Psame");
	grHIN16022PbPbV2->Draw("Lxsame");
	grHIN16022PbPbV3->Draw("Lxsame");
//	grHIN14006PbPbV26->Draw("Psame");
//	grHIN14006PbPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.59, 1.0, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	////////////////////////////////////
	TCanvas * cV2 = MakeCanvas("cV2", "cV2", 800, 500);
	makeMultiPanelCanvas(cV2, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);
	TH2D * hframeV2 = new TH2D("hframeV2", "", 1, 1, 399, 1, 0.0001, 0.14);
	InitHist(hframeV2, "N_{trk}^{offline}", "v_{2}");

	p = cV2->cd(1);
	p->SetTopMargin(0.06);
	hframeV2->Draw();

	grPAV24sys->Draw("[]3");
	grPAV26sys->Draw("[]3");
	grPAV28sys->Draw("[]3");
//	grPAV34sys->Draw("[]3");

	grHIN16022pPbV2sys->Draw("[]3");
//	grHIN16022pPbV3sys->Draw("[]3");

	grPA2.grV4->Draw("Psame");
	grPA2.grV6->Draw("Psame");
	grPA2.grV8->Draw("Psame");

//	gr1405_3976v34->Draw("lsame");

//	grPA3.grV4->Draw("Psame");
	grHIN16022pPbV2->Draw("Psame");
//	grHIN16022pPbV3->Draw("Psame");

//	grHIN14006pPbV26->Draw("Psame");
//	grHIN14006pPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
	latexS.DrawLatexNDC(0.20, 0.92, "pPb 8.16 TeV");
//	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	legV2->Draw();

	p = cV2->cd(2);
	p->SetTopMargin(0.06);
	hframeV2->Draw();

//	grHIN16022PbPbV3->SetMarkerStyle(kMultiply);


//	TGraphErrors * grAAV34sys = sysGr(grAA3.grV4, 0.03, 3003);


	grAAV24sys->Draw("[]3");
	grAAV26sys->Draw("[]3");
	grAAV28sys->Draw("[]3");
//	grAAV34sys->Draw("[]3");

	grHIN16022PbPbV2sys->Draw("[]3");
//	grHIN16022PbPbV3sys->Draw("[]3");

	grAA2.grV4->Draw("Psame");
	grAA2.grV6->Draw("Psame");
	grAA2.grV8->Draw("Psame");

//	grAA3.grV4->SetMarkerSize(1.5);
//	grAA3.grV4->Draw("Psame");
	grHIN16022PbPbV2->Draw("Psame");
//	grHIN16022PbPbV3->Draw("Psame");
//	grHIN14006PbPbV26->Draw("Psame");
//	grHIN14006PbPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.10, 0.92, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	///////// V3
	TCanvas * cV3 = MakeCanvas("cV3", "cV3", 800, 500);
	makeMultiPanelCanvas(cV3, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	TH2D * hframeV3 = new TH2D("hframeV3", "", 1, 1, 399, 1, 0.0001, 0.14);
	InitHist(hframeV3, "N_{trk}^{offline}", "v_{3}");

	p = cV3->cd(1);
	p->SetTopMargin(0.06);
	hframeV3->Draw();

//	grPAV24sys->Draw("[]3");
//	grPAV26sys->Draw("[]3");
//	grPAV28sys->Draw("[]3");
	grPAV34sys->Draw("[]3");

//	grHIN16022pPbV2sys->Draw("[]3");
	grHIN16022pPbV3sys->Draw("[]3");

//	grPA2.grV4->Draw("Psame");
//	grPA2.grV6->Draw("Psame");
//	grPA2.grV8->Draw("Psame");

	gr1405_3976v34->Draw("lsame");

	grPA3.grV4->Draw("Psame");
	grHIN16022pPbV3->Draw("Psame");

//	grHIN14006pPbV26->Draw("Psame");
//	grHIN14006pPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
	latexS.DrawLatexNDC(0.20, 0.92, "pPb 8.16 TeV");
//	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");


	legV21->Draw();

	p = cV3->cd(2);
	p->SetTopMargin(0.06);
	hframeV3->Draw();

	grAA3.grV4->SetMarkerStyle(kMultiply);
	grHIN16022PbPbV3->SetMarkerStyle(kMultiply);


//	grAAV24sys->Draw("[]3");
//	grAAV26sys->Draw("[]3");
//	grAAV28sys->Draw("[]3");
	grAAV34sys->Draw("[]3");

//	grHIN16022PbPbV2sys->Draw("[]3");
	grHIN16022PbPbV3sys->Draw("[]3");

//	grAA2.grV4->Draw("Psame");
//	grAA2.grV6->Draw("Psame");
//	grAA2.grV8->Draw("Psame");

	grAA3.grV4->SetMarkerSize(1.5);
	grAA3.grV4->Draw("Psame");
//	grHIN16022PbPbV2->Draw("Psame");
	grHIN16022PbPbV3->Draw("Psame");
//	grHIN14006PbPbV26->Draw("Psame");
//	grHIN14006PbPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.10, 0.92, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");


	/////////////////////
	TCanvas * cV64 = MakeCanvas("cV64", "cV64", 900, 500);
	cV64->Divide(2, 1);
	TH2D * hframeV64 = new TH2D("hframeV64", "", 1, 0, 399, 1, 0.5, 1.5);
	InitHist(hframeV64, "N_{trk}^{offline}", "Ratio");

	p = cV64->cd(1);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);

	hframeV64->Draw();
	grPA2.grV64->Draw("psame");
	grPA2.grV86->Draw("psame");
	grPA2.grV4V2->Draw("psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	p = cV64->cd(2);
	p->SetBottomMargin(0.15);
	p->SetLeftMargin(0.15);
	p->SetRightMargin(0.02);

	hframeV64->Draw();
	grAA2.grV64->Draw("psame");
	grAA2.grV86->Draw("psame");
	grAA2.grV4V2->Draw("psame");

	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary} PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV64 = new TLegend(0.4, 0.2, 0.85, 0.4);
	legV64->SetFillColor(kWhite);
	legV64->SetTextFont(42);
	legV64->SetTextSize(0.06);
	legV64->SetBorderSize(0);
	legV64->AddEntry(grPA2.grV64, "v_{2}{6}/v_{2}{4}", "p");
	legV64->AddEntry(grPA2.grV86, "v_{2}{8}/v_{2}{6}", "p");
	legV64->Draw();

	///////////////////

	TCanvas * cV42ratio = MakeCanvas("cV42ratio", "cV42ratio", 800, 500);
	makeMultiPanelCanvas(cV42ratio, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	TH2D * hframeV42ratio = new TH2D("hframeV42ratio", "", 1, 1, 399, 1, 0.5, 1.5);
	InitHist(hframeV42ratio, "N_{trk}^{offline}", "v_{n}{4} / v_{n}{2}");


	p = cV42ratio->cd(1);
	p->SetTopMargin(0.06);
	hframeV42ratio->Draw();
	grPA3.grV4V2sub->SetMarkerStyle(kMultiply);

	grPA2.grV4V2sub->SetMarkerColor(kRed);
	grPA2.grV4V2sub->SetLineColor(kRed);
	grPA2.grV4V2->SetMarkerColor(kRed);
	grPA2.grV4V2->SetLineColor(kRed);

	TGraphErrors * grPA2V42sys = sysGr(grPA2.grV4V2sub, 0.03, 3001);
	TGraphErrors * grPA3V42sys = sysGr(grPA3.grV4V2sub, 0.03, 3003);

	grPA2V42sys->Draw("[]3");
	grPA3V42sys->Draw("[]3");

	grPA2.grV4V2sub->Draw("psame");
	grPA3.grV4V2sub->Draw("psame");
	grPA2.grV4V2->Draw("lxsame");
	grPA3.grV4V2->Draw("lxsame");

	gr1702_01730v242_3->SetLineStyle(kDashed);
	gr1702_01730v342_3->SetLineStyle(kDashed);

	gr1702_01730v242_3->Draw("lsame");
	gr1702_01730v342_3->Draw("lsame");

	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
	latexS.DrawLatexNDC(0.68, 1.0, "pPb 8.16 TeV");

	TLegend * legV42 = new TLegend(0.22, 0.60, 0.70, 0.93);
	legV42->SetFillColor(kWhite);
	legV42->SetTextFont(42);
	legV42->SetTextSize(0.05);
	legV42->SetBorderSize(0);

	legV42->AddEntry(grPA2.grV4V2sub, "v_{2}{4} / v_{2}^{sub}{2, |#Delta#eta|>2}", "p");
	legV42->AddEntry(grPA2.grV4V2, "v_{2}{4} / v_{2}{2, |#Delta#eta|>2}", "l");
	legV42->AddEntry(grPA3.grV4V2sub, "v_{3}{4} / v_{3}^{sub}{2, |#Delta#eta|>2}", "p");
	legV42->AddEntry(grPA3.grV4V2, "v_{3}{4} / v_{3}{2, |#Delta#eta|>2}", "l");
	legV42->AddEntry(gr1702_01730v242_3, "#epsilon_{2}{4} / #epsilon_{3}{2}, 5.02 TeV", "l");
	legV42->AddEntry(gr1702_01730v342_3, "#epsilon_{3}{4} / #epsilon_{3}{2}, 5.02 TeV", "l");
	legV42->Draw();

	p = cV42ratio->cd(2);
	p->SetTopMargin(0.06);
	hframeV42ratio->Draw();
	grAA3.grV4V2sub->SetMarkerStyle(kMultiply);

	grAA2.grV4V2sub->SetMarkerColor(kRed);
	grAA2.grV4V2sub->SetLineColor(kRed);
	grAA2.grV4V2->SetMarkerColor(kRed);
	grAA2.grV4V2->SetLineColor(kRed);

	TGraphErrors * grAA2V42sys = sysGr(grAA2.grV4V2sub, 0.01, 3001);
	TGraphErrors * grAA3V42sys = sysGr(grAA3.grV4V2sub, 0.01, 3003);

	grAA2V42sys->Draw("[]3");
	grAA3V42sys->Draw("[]3");

	grAA2.grV4V2sub->Draw("psame");
	grAA3.grV4V2sub->Draw("psame");
	grAA2.grV4V2->Draw("lxsame");
	grAA3.grV4V2->Draw("lxsame");

	latexS.DrawLatexNDC(0.59, 1.0, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");
	///////////////////

	TCanvas * cVratio = MakeCanvas("cVratio", "cVratio", 500, 900);
	splitCanv(cVratio);
//	makeMultiPanelCanvas(cVratio, 1, 2, 0.0, 0.05, 0.01, 0.05, 0.03);
	TH2D * hframeVratio = new TH2D("hframeVratio", "", 1, 0.55, 0.99, 1, 0.7, 1.5);
	InitHist(hframeVratio, "v_{2}{4} / v_{2}{2}", "v_{2}{6} / v_{2}{4}");

	p = cVratio->cd(1);
	hframeVratio->DrawClone();
	ffit64->Draw("same");
	TGraphErrors * grPAVratio64 = ratioGr(grPA2.grV64, grPA2.grV4V2);
	TGraphErrors * grAAVratio64 = ratioGr(grAA2.grV64, grAA2.grV4V2);

	grPAVratio64->SetMarkerStyle(kFullSquare);
	grAAVratio64->SetMarkerStyle(kOpenSquare);

	TGraphErrors * grPAVratio64sys = sysGr2(grPAVratio64, 0.014, 0.03, 3003);
	TGraphErrors * grAAVratio64sys = sysGr2(grAAVratio64, 0.014, 0.02, kBlue);
	grAAVratio64sys->SetFillStyle(3004);

	grPAVratio64sys->Draw("[]2");
	grAAVratio64sys->Draw("[]2");
	grPAVratio64->Draw("psame");
	grAAVratio64->Draw("psame");

	p = cVratio->cd(2);
	hframeVratio->GetYaxis()->SetTitle("v_{2}{8} / v_{2}{6}");
	hframeVratio->Draw();
	ffit86->Draw("same");
	TGraphErrors * grPAVratio86 = ratioGr(grPA2.grV86, grPA2.grV4V2);
	TGraphErrors * grAAVratio86 = ratioGr(grAA2.grV86, grAA2.grV4V2);

	grPAVratio86->SetMarkerStyle(kFullCircle);
	grAAVratio86->SetMarkerStyle(kOpenCircle);

	TGraphErrors * grPAVratio86sys = sysGr2(grPAVratio86, 0.014, 0.03, 3001);
	TGraphErrors * grAAVratio86sys = sysGr2(grAAVratio86, 0.014, 0.02, kRed);
	grAAVratio86sys->SetFillStyle(3004);

	grPAVratio86sys->Draw("[]2");
	grAAVratio86sys->Draw("[]2");
	grPAVratio86->Draw("psame");
	grAAVratio86->Draw("psame");

	cVratio->cd(1);
	latexS.DrawLatexNDC(0.15, 0.96, "#bf{CMS}");
	latexS.DrawLatexNDC(0.20, 0.85, "pPb 8.16 TeV, PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.20, 0.77, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legVratio1 = new TLegend(0.2, 0.5, 0.55, 0.65);
	legVratio1->SetFillColor(kWhite);
	legVratio1->SetTextFont(42);
	legVratio1->SetTextSize(0.06);
	legVratio1->SetBorderSize(0);
	legVratio1->AddEntry(grPAVratio64, "pPb", "p");
	legVratio1->AddEntry(grAAVratio64, "PbPb", "p");
	legVratio1->Draw();

	cVratio->cd(2);

	TLegend * legVratio2 = new TLegend(0.2, 0.75, 0.55, 0.9);
	legVratio2->SetFillColor(kWhite);
	legVratio2->SetTextFont(42);
	legVratio2->SetTextSize(0.06);
	legVratio2->SetBorderSize(0);
	legVratio2->AddEntry(grPAVratio86, "pPb", "p");
	legVratio2->AddEntry(grAAVratio86, "PbPb", "p");
	legVratio2->Draw();

	TLine * lred  = new TLine(0.6, 0.78, 0.65, 0.78);
	TLine * lblue = new TLine(0.6, 0.80, 0.65, 0.80);

	lred->SetLineColor(kRed);
	lblue->SetLineColor(kBlue);

	lred->SetLineWidth(2.0);
	lblue->SetLineWidth(2.0);

	lred->Draw("lsame");
	lblue->Draw("lsame");
	latexS.DrawLatex(0.66, 0.81, "Fluctuation-Driven Eccentricities");

	////////////////////
	TCanvas * cC8 = MakeCanvas("cC8", "cC8", 500, 600);
	cC8->SetLeftMargin(0.18);
	cC8->SetRightMargin(0.05);
	cC8->SetLogy();

	TH2D * hframeC8 = new TH2D("hframeC8", "", 1, 0, 399, 1, 0.0000000001, 0.0001);
	InitHist(hframeC8, "N_{trk}^{offline}", "-c_{2}{8} and c_{2}{6}");
	hframeC8->SetTitleOffset(1.5, "Y");

	hframeC8->Draw();

	grPA2.grC6->SetMarkerStyle(kOpenDiamond);

	grAA2.grC6->Draw("psame");
	grPA2.grC6->Draw("psame");

	auto AAC28 = negGr(grAA2.grC8);
	auto PAC28 = negGr(grPA2.grC8);
	PAC28->SetMarkerStyle(kOpenDiamond);

	AAC28->Draw("psame");
	PAC28->Draw("psame");

	TLegend * legC8 = new TLegend(0.65, 0.74, 0.9, 0.93);
	legC8->SetFillColor(kWhite);
	legC8->SetTextFont(42);
	legC8->SetTextSize(0.04);
	legC8->SetBorderSize(0);
	legC8->AddEntry(grAA2.grC6, "PbPb c_{2}{6}", "p");
	legC8->AddEntry(grPA2.grC6, "pPb c_{2}{6}", "p");
	legC8->AddEntry(AAC28, "PbPb c_{2}{8}", "p");
	legC8->AddEntry(PAC28, "pPb c_{2}{8}", "p");
	legC8->Draw();
	latexS.DrawLatexNDC(0.20, 0.92, "#bf{CMS Preliminary}");
	latexS.DrawLatexNDC(0.20, 0.87, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");



	///// save
	cC->SaveAs("c4.pdf");
	cCgap->SaveAs("c24gap.pdf");
	cCgap3->SaveAs("c34gap.pdf");
	cV->SaveAs("v23.pdf");
	cV2->SaveAs("v2.pdf");
	cVn->SaveAs("vn.pdf");
	cV3->SaveAs("v3.pdf");
	cV64->SaveAs("v2ratio.pdf");
	cVratio->SaveAs("v2rs.pdf");
	cV42ratio->SaveAs("v42.pdf");
	/////

	//
	///// ratio compare PA
	TCanvas * cVratioPA = MakeCanvas("cVratioPA", "cVratioPA", 500, 900);
	splitCanv(cVratioPA);

	p = cVratioPA->cd(1);
	hframeVratio->DrawClone();
	ffit64->Draw("same");
	grPAVratio64->SetMarkerColor(kRed);
	grPAVratio64->SetLineColor(kRed);
	grPAVratio64->Draw("psame");

	gr_pPb_v264->SetMarkerColor(kBlue);
	gr_pPb_v264->SetLineColor(kBlue);
	gr_pPb_v264->Draw("psame");

	p = cVratioPA->cd(2);
	hframeVratio->Draw();
	ffit86->Draw("same");
	grPAVratio86->SetMarkerColor(kRed);
	grPAVratio86->SetLineColor(kRed);
	grPAVratio86->Draw("psame");

	gr_pPb_v286->SetMarkerColor(kBlue);
	gr_pPb_v286->SetLineColor(kBlue);
	gr_pPb_v286->Draw("psame");

	///// ratio compare AA
	TCanvas * cVratioAA = MakeCanvas("cVratioAA", "cVratioAA", 500, 900);
	splitCanv(cVratioAA);

	p = cVratioAA->cd(1);
	hframeVratio->DrawClone();
	ffit64->Draw("same");
	grAAVratio64->SetMarkerColor(kRed);
	grAAVratio64->SetLineColor(kRed);
	grAAVratio64->Draw("psame");

	gr_PbPb_v264->SetMarkerColor(kBlue);
	gr_PbPb_v264->SetLineColor(kBlue);
	gr_PbPb_v264->Draw("psame");

	p = cVratioAA->cd(2);
	hframeVratio->Draw();
	ffit86->Draw("same");
	grAAVratio86->SetMarkerColor(kRed);
	grAAVratio86->SetLineColor(kRed);
	grAAVratio86->Draw("psame");

	gr_PbPb_v286->SetMarkerColor(kBlue);
	gr_PbPb_v286->SetLineColor(kBlue);
	gr_PbPb_v286->Draw("psame");

	cVratioPA->SaveAs("v2rsPA.pdf");
	cVratioAA->SaveAs("v2rsAA.pdf");
}

void splitCanv(TCanvas * c)
{
	if (!c) return;

	c->cd(0);
	TPad * p1 = new TPad("pad2", "", 0., 0.52, 1., 1.);
	p1->SetLeftMargin(0.15);
	p1->SetRightMargin(0.03);
	p1->SetBottomMargin(0.0);
	p1->SetTopMargin(0.1);
	p1->Draw();
	p1->SetNumber(1);

	TPad * p2 = new TPad("pad1", "", 0., 0., 1., 0.52);
	p2->SetLeftMargin(0.15);
	p2->SetRightMargin(0.03);
	p2->SetBottomMargin(0.15);
	p2->SetTopMargin(0.0);
//	p2->SetGrid();
	p2->Draw();
	p2->SetNumber(2);
}
