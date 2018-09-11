#include "../../style.h"
#include "HIN-16-022.h"
#include "HIN-14-006.h"
#include "theory.h"
#include "published.h"

bool bPrelim = true;

TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
TColor *green = new TColor(3002, 0, 0.5, 0, "green", 0.4);
TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);
TColor *gray = new TColor(3005, 0, 0, 0, "black", 0.4);
//TColor *gray = new TColor(3005, 0, 0, 1, "black", 0.4);

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

void ratio2fluct(TGraphErrors* gr)
{
  for ( int i = 0; i < gr->GetN(); i++ )
  {
    double r = gr->GetY()[i];
    double e = gr->GetEY()[i];
    double er2 = 2*e*r;
    gr->GetY()[i] = sqrt( (1-r*r) / (1+r*r) );
    gr->GetEY()[i] = 2 * er2 / (1+r*r) / (1+r*r);
  }
}

TGraphErrors * sysGr(TGraphErrors * gr, double sys, int k = 3001)
{
	TGraphErrors * ret = (TGraphErrors*) gr->Clone();
	for ( int i = 0; i < ret->GetN(); i++ ) {
		ret->GetEY()[i] = ret->GetY()[i] * sys;
		ret->GetEX()[i] = 10;
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

void plotFinal(TString s2pPb = "grV2_sysPhiAcc.root",
		TString s3pPb = "grV3_sysPhiAcc.root",
		TString s2PbPb = "grV2PbPb_sysPhiAcc.root",
		TString s3PbPb = "grV3PbPb_sysPhiAcc.root",
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

	///////////////////////////

	TCanvas * cVn = MakeCanvas("cVn", "cVn", 800, 500);
	makeMultiPanelCanvas(cVn, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	TH2D * hframeVn = new TH2D("hframeVn", "", 1, 1, 399, 1, 0.0001, 0.14);
	InitHist(hframeVn, "N_{trk}^{offline}", "v_{n}");
//	hframeVn->SetLabelFont(43, "Y");
	hframeVn->GetXaxis()->SetLabelFont(43);
	hframeVn->GetXaxis()->SetTitleFont(43);
	hframeVn->GetXaxis()->SetLabelSize(20);
	hframeVn->GetXaxis()->SetTitleSize(25);
//	hframeVn->GetXaxis()->SetLabelSize(1);
//	cout << " --> LabelSize() = " << hframeVn->GetXaxis()->GetLabelSize() << endl;;
//	cout << " --> TitleSize() = " << hframeVn->GetXaxis()->GetTitleSize() << endl;;

	auto p = cVn->cd(1);
	p->SetTopMargin(0.06);
	hframeVn->Draw();

	grPA3.grV4->SetMarkerStyle(kMultiply);
	grHIN16022pPbV3sub->SetMarkerStyle(kMultiply);
	grHIN16022pPbV3sub->SetMarkerColor(kGreen+3);
	grHIN16022pPbV3sub->SetLineColor(kGreen+3);
	grHIN16022pPbV3->SetLineColor(kGreen+3);
	grHIN16022pPbV3->SetMarkerStyle(kMultiply);

	TGraphErrors * grPAV24sys = sysGr(grPA2.grV4, 0.01 , 3003);
	TGraphErrors * grPAV26sys = sysGr(grPA2.grV6, 0.013, 3003);
	TGraphErrors * grPAV28sys = sysGr(grPA2.grV8, 0.024, 3001);

	TGraphErrors * grPAV34sys = sysGr(grPA3.grV4, 0.05, 3003);

	TGraphErrors * grHIN16022pPbV2sys = sysGr(grHIN16022pPbV2sub, 0.018, 3001);
	TGraphErrors * grHIN16022pPbV3sys = sysGr(grHIN16022pPbV3sub, 0.018, 3002);

	gr1405_3976v34->SetFillColor(3005);
	gr1405_3976v34->Draw("[]3");

	grPAV24sys->Draw("[]2");
	grPAV26sys->Draw("[]2");
	grPAV28sys->Draw("[]2");
	grPAV34sys->Draw("[]2");

	grHIN16022pPbV2sys->Draw("[]2");
	grHIN16022pPbV3sys->Draw("[]2");

	grPA2.grV4->Draw("Psame");
	grPA2.grV6->Draw("Psame");
	grPA2.grV8->Draw("Psame");


	grPA3.grV4->SetMarkerSize(1.5);
	grPA3.grV4->Draw("Psame");
	grHIN16022pPbV2sub->Draw("Psame");
	grHIN16022pPbV3sub->Draw("Psame");
//	grHIN16022pPbV2->Draw("lxsame");
//	grHIN16022pPbV3->Draw("lxsame");

//	grHIN14006pPbV26->Draw("Psame");
//	grHIN14006pPbV28->Draw("Psame");

	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");
//	latexS.DrawLatexNDC(0.20, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

	TLegend * legV2 = new TLegend(0.18, 0.61, 0.60, 0.93);
	legV2->SetFillColor(kWhite);
	legV2->SetTextFont(42);
	legV2->SetTextSize(0.05);
	legV2->SetBorderSize(0);

	legV2->AddEntry(grPA2.grV4, "v_{2}{4}", "p");
	legV2->AddEntry(grPA2.grV6, "v_{2}{6}", "p");
	legV2->AddEntry(grPA2.grV8, "v_{2}{8}", "p");
	legV2->AddEntry(grPA3.grV4, "v_{3}{4}", "p");
	legV2->Draw();

	TLegend * legV21 = new TLegend(0.43, 0.69, 0.90, 0.93);
	legV21->SetFillColor(kWhite);
	legV21->SetTextFont(42);
	legV21->SetTextSize(0.05);
	legV21->SetBorderSize(0);

	legV21->AddEntry(grHIN16022PbPbV2sub, "v_{2}^{sub}{2}(|#Delta#eta|>2)", "p");
//	legV21->AddEntry(grHIN16022PbPbV2, "v_{2}{2, |#Delta#eta|>2}", "l");
	legV21->AddEntry(grHIN16022PbPbV3sub, "v_{3}^{sub}{2}(|#Delta#eta|>2)", "p");
//	legV21->AddEntry(grHIN16022PbPbV3, "v_{3}{2, |#Delta#eta|>2}", "l");
	legV21->AddEntry(gr1405_3976v34, "v_{3}{4} hydro 5.02 TeV", "");
	legV21->Draw();

	TBox * box = new TBox();
	box->SetFillColor(3005);
//	box->SetFillColor(kRed);
	box->DrawBox(146, 0.099, 174, 0.105);

	p = cVn->cd(2);
	p->SetTopMargin(0.06);
	hframeVn->Draw();

	grAA3.grV4->SetMarkerStyle(kMultiply);
	grHIN16022PbPbV3sub->SetMarkerStyle(kMultiply);
	grHIN16022PbPbV3sub->SetMarkerColor(kGreen+3);
	grHIN16022PbPbV3sub->SetLineColor(kGreen+3);
	grHIN16022PbPbV3->SetLineColor(kGreen+3);

	TGraphErrors * grAAV24sys = sysGr(grAA2.grV4, 0.01, 3003);
	TGraphErrors * grAAV26sys = sysGr(grAA2.grV6, 0.01, 3003);
	TGraphErrors * grAAV28sys = sysGr(grAA2.grV8, 0.01, 3001);

	TGraphErrors * grAAV34sys = sysGr(grAA3.grV4, 0.03, 3003);

	TGraphErrors * grHIN16022PbPbV2sys = sysGr(grHIN16022PbPbV2sub, 0.018, 3001);
	TGraphErrors * grHIN16022PbPbV3sys = sysGr(grHIN16022PbPbV3sub, 0.018, 3002);

	grAAV24sys->Draw("[]2");
	grAAV26sys->Draw("[]2");
	grAAV28sys->Draw("[]2");
	grAAV34sys->Draw("[]2");

	grHIN16022PbPbV2sys->Draw("[]2");
	grHIN16022PbPbV3sys->Draw("[]2");

	grAA2.grV4->Draw("Psame");
	grAA2.grV6->Draw("Psame");
	grAA2.grV8->Draw("Psame");

	grAA3.grV4->SetMarkerSize(1.5);
	grAA3.grV4->Draw("Psame");
	grHIN16022PbPbV2sub->Draw("Psame");
	grHIN16022PbPbV3sub->Draw("Psame");
//	grHIN16022PbPbV2->Draw("Lxsame");
//	grHIN16022PbPbV3->Draw("Lxsame");
//	grHIN14006PbPbV26->Draw("Psame");
//	grHIN14006PbPbV28->Draw("Psame");

	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");

	////////////////////////////////////

	TCanvas * cV3 = MakeCanvas("cV3", "cV3", 800, 500);
	makeMultiPanelCanvas(cV3, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	TH2D * hframeV3 = new TH2D("hframeV3", "", 1, 1, 399, 1, 0.0001, 0.049);
	InitHist(hframeV3, "N_{trk}^{offline}", "v_{3}");
	hframeV3->GetXaxis()->SetLabelFont(43);
	hframeV3->GetXaxis()->SetTitleFont(43);
	hframeV3->GetXaxis()->SetLabelSize(20);
	hframeV3->GetXaxis()->SetTitleSize(25);

	p = cV3->cd(1);
	p->SetTopMargin(0.06);
	hframeV3->Draw();

	gr1405_3976v34->Draw("[]3");

	grPAV34sys->Draw("[]2");
	grHIN16022pPbV3sys->Draw("[]2");

	grPA3.grV4->Draw("Psame");
	grHIN16022pPbV3sub->Draw("Psame");

	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");

	TLegend * legV3 = new TLegend(0.18, 0.71, 0.60, 0.93);
	legV3->SetFillColor(kWhite);
	legV3->SetTextFont(42);
	legV3->SetTextSize(0.05);
	legV3->SetBorderSize(0);

	legV3->AddEntry(grHIN16022PbPbV3sub, "v_{3}^{sub}{2}(|#Delta#eta|>2)", "p");
	legV3->AddEntry(grPA3.grV4, "v_{3}{4}", "p");
	legV3->AddEntry(gr1405_3976v34, "v_{3}{4} hydro 5.02 TeV", "");

	legV3->Draw();
	box->DrawBox(25, 0.0355, 55, 0.038);

	p = cV3->cd(2);
	p->SetTopMargin(0.06);
	hframeV3->Draw();

	grHIN16022PbPbV3sys->Draw("[]2");
	grAAV34sys->Draw("[]2");

	grHIN16022PbPbV3sub->Draw("Psame");
	grAA3.grV4->Draw("Psame");
	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");


	///////////////////

	TCanvas * cV2 = MakeCanvas("cV2", "cV2", 800, 500);
	makeMultiPanelCanvas(cV2, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	TH2D * hframeV2 = new TH2D("hframeV2", "", 1, 1, 399, 1, 0.0001, 0.14);
	InitHist(hframeV2, "N_{trk}^{offline}", "v_{2}");
	hframeV2->GetXaxis()->SetLabelFont(43);
	hframeV2->GetXaxis()->SetTitleFont(43);
	hframeV2->GetXaxis()->SetLabelSize(20);
	hframeV2->GetXaxis()->SetTitleSize(25);

	p = cV2->cd(1);
	p->SetTopMargin(0.06);
	hframeV2->Draw();

	grPAV24sys->Draw("[]2");
	grPAV26sys->Draw("[]2");
	grPAV28sys->Draw("[]2");

	grHIN16022pPbV2sys->Draw("[]2");

	grPA2.grV4->Draw("Psame");
	grPA2.grV6->Draw("Psame");
	grPA2.grV8->Draw("Psame");

	grHIN16022pPbV2sub->Draw("Psame");

	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");

	TLegend * legV22 = new TLegend(0.18, 0.61, 0.60, 0.93);
	legV22->SetFillColor(kWhite);
	legV22->SetTextFont(42);
	legV22->SetTextSize(0.05);
	legV22->SetBorderSize(0);

	legV22->AddEntry(grHIN16022pPbV2sub, "v_{2}^{sub}{2}(|#Delta#eta|>2)", "p");
	legV22->AddEntry(grPA2.grV4, "v_{2}{4}", "p");
	legV22->AddEntry(grPA2.grV6, "v_{2}{6}", "p");
	legV22->AddEntry(grPA2.grV8, "v_{2}{8}", "p");
	legV22->Draw();

	p = cV2->cd(2);
	p->SetTopMargin(0.06);
	hframeV2->Draw();


	grAAV24sys->Draw("[]2");
	grAAV26sys->Draw("[]2");
	grAAV28sys->Draw("[]2");

	grHIN16022PbPbV2sys->Draw("[]2");

	grAA2.grV4->Draw("Psame");
	grAA2.grV6->Draw("Psame");
	grAA2.grV8->Draw("Psame");

	grHIN16022PbPbV2sub->Draw("Psame");

	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");
	///////////////////
	TCanvas * cV42ratio = MakeCanvas("cV42ratio", "cV42ratio", 800, 500);
	makeMultiPanelCanvas(cV42ratio, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	TH2D * hframeV42ratio = new TH2D("hframeV42ratio", "", 1, 1, 399, 1, 0.0, 1.5);
	InitHist(hframeV42ratio, "N_{trk}^{offline}", "v_{n}{4} / v_{n}{2}");
	hframeV42ratio->GetXaxis()->SetLabelFont(43);
	hframeV42ratio->GetXaxis()->SetTitleFont(43);
	hframeV42ratio->GetXaxis()->SetLabelSize(20);
	hframeV42ratio->GetXaxis()->SetTitleSize(25);


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

	grPA2V42sys->Draw("[]2");
	grPA3V42sys->Draw("[]2");

	grPA2.grV4V2sub->Draw("psame");
	grPA3.grV4V2sub->Draw("psame");
//	grPA2.grV4V2->Draw("lxsame");
//	grPA3.grV4V2->Draw("lxsame");

	gr1702_01730v242_3->SetLineStyle(kDashed);
	gr1702_01730v342_3->SetLineStyle(kDashed);
	gr1702_01730v242_3->SetLineWidth(2.0);
	gr1702_01730v342_3->SetLineWidth(2.0);

	gr1702_01730v242_3->Draw("lsame");
	gr1702_01730v342_3->Draw("lsame");

	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
//	latexS.DrawLatexNDC(0.38, 1.003, "pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");

	TLegend * legV42 = new TLegend(0.22, 0.20, 0.67, 0.35);
	legV42->SetFillColor(kWhite);
	legV42->SetTextFont(43);
	legV42->SetTextSize(22);
	legV42->SetBorderSize(0);

//	legV42->AddEntry(grPA2.grV4V2sub, "v_{2}{4} / v_{2}^{sub}{2, |#Delta#eta|>2}", "p");
//	legV42->AddEntry(grPA3.grV4V2sub, "v_{3}{4} / v_{3}^{sub}{2, |#Delta#eta|>2}", "p");
	legV42->AddEntry(gr1702_01730v242_3, "#varepsilon_{2}{4} /#varepsilon_{2}{2} pPb 5.02 TeV", "l");
	legV42->AddEntry(gr1702_01730v342_3, "#varepsilon_{3}{4} /#varepsilon_{3}{2} pPb 5.02 TeV", "l");
//	legV42->AddEntry(grPA2.grV4V2, "v_{2}{4} / v_{2}{2, |#Delta#eta|>2}", "l");
//	legV42->AddEntry(grPA3.grV4V2, "v_{3}{4} / v_{3}{2, |#Delta#eta|>2}", "l");

	legV42->Draw();

//	latexS.DrawLatexNDC(0.20, 0.90, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");
	latexS.DrawLatexNDC(0.20, 0.90, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");

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

	grAA2V42sys->Draw("[]2");
	grAA3V42sys->Draw("[]2");

	grAA2.grV4V2sub->Draw("psame");
	grAA3.grV4V2sub->Draw("psame");
//	grAA2.grV4V2->Draw("lxsame");
//	grAA3.grV4V2->Draw("lxsame");

	TLegend * legV42b = new TLegend(0.20, 0.20, 0.65, 0.35);
	legV42b->SetFillColor(kWhite);
	legV42b->SetTextFont(43);
	legV42b->SetTextSize(22);
	legV42b->SetBorderSize(0);

	legV42b->AddEntry(grPA2.grV4V2sub, "v_{2}{4} / v_{2}^{sub}{2}(|#Delta#eta|>2)", "p");
	legV42b->AddEntry(grPA3.grV4V2sub, "v_{3}{4} / v_{3}^{sub}{2}(|#Delta#eta|>2)", "p");
//	legV42b->AddEntry(gr1702_01730v242_3, "#varepsilon_{2}{4} /#varepsilon_{2}{2} 5.02 TeV", "l");
//	legV42b->AddEntry(gr1702_01730v342_3, "#varepsilon_{3}{4} /#varepsilon_{3}{2} 5.02 TeV", "l");
//	legV42b->AddEntry(grPA2.grV4V2, "v_{2}{4} / v_{2}{2, |#Delta#eta|>2}", "l");
//	legV42b->AddEntry(grPA3.grV4V2, "v_{3}{4} / v_{3}{2, |#Delta#eta|>2}", "l");

	legV42b->Draw();
//	latexS.DrawLatexNDC(0.25, 1.003, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	///////////////////

	TCanvas * cVratio = MakeCanvas("cVratio", "cVratio", 500, 900);
	splitCanv(cVratio);
//	makeMultiPanelCanvas(cVratio, 1, 2, 0.0, 0.05, 0.01, 0.05, 0.03);
	TH2D * hframeVratio = new TH2D("hframeVratio", "", 1, 0.58, 0.92, 1, 0.7, 1.5);
	InitHist(hframeVratio, "v_{2}{4} / v_{2}^{sub}{2}(|#Delta#eta|>2)", "v_{2}{6} / v_{2}{4}");

	p = cVratio->cd(1);
	hframeVratio->DrawClone();
//	ffit64->SetLineColor(kBlack);
	ffit64->Draw("same");
	TGraphErrors * grPAVratio64 = ratioGr(grPA2.grV64, grPA2.grV4V2);
	TGraphErrors * grAAVratio64 = ratioGr(grAA2.grV64, grAA2.grV4V2);

	grPAVratio64->SetMarkerStyle(kFullSquare);
	grAAVratio64->SetMarkerStyle(kOpenSquare);

	gr_pPb_v264->SetMarkerStyle(kOpenSquare);
	gr_pPb_v264->SetMarkerColor(kRed);
	gr_pPb_v264->SetMarkerSize(2);
	gr_pPb_v264->SetLineColor(kRed);

	TGraphErrors * grPAVratio64sys = sysGr2(grPAVratio64, 0.014, 0.03, 3003);
	TGraphErrors * grAAVratio64sys = sysGr2(grAAVratio64, 0.014, 0.02, kBlue);
	grAAVratio64sys->SetFillStyle(3004);
	TGraphErrors * gr_pPb_v264sys = sysGr2(gr_pPb_v264, 0.028, 0.01, 3001);

	grPAVratio64sys->Draw("[]2");
	gr_pPb_v264sys->Draw("[]2");
	grPAVratio64->Draw("psame");
	gr_pPb_v264->Draw("psame");

	p = cVratio->cd(2);
	hframeVratio->GetYaxis()->SetTitle("v_{2}{8} / v_{2}{6}");
	hframeVratio->Draw();
//	ffit86->SetLineColor(kBlack);
	ffit86->Draw("same");
	TGraphErrors * grPAVratio86 = ratioGr(grPA2.grV86, grPA2.grV4V2);
	TGraphErrors * grAAVratio86 = ratioGr(grAA2.grV86, grAA2.grV4V2);

	grPAVratio86->SetMarkerStyle(kFullCircle);
	grAAVratio86->SetMarkerStyle(kOpenCircle);
	grPAVratio86->SetMarkerColor(kBlue);
	grPAVratio86->SetLineColor(kBlue);

	gr_pPb_v286->SetMarkerStyle(kOpenCircle);
	gr_pPb_v286->SetMarkerColor(kRed);
	gr_pPb_v286->SetMarkerSize(2);
	gr_pPb_v286->SetLineColor(kRed);

	TGraphErrors * grPAVratio86sys = sysGr2(grPAVratio86, 0.014, 0.03, 3003);
	TGraphErrors * gr_pPb_v286sys  = sysGr2(gr_pPb_v286, 0.028, 0.036, 3001);
	TGraphErrors * grAAVratio86sys = sysGr2(grAAVratio86, 0.014, 0.02, kRed);
	grAAVratio86sys->SetFillStyle(3004);

	grPAVratio86sys->Draw("[]2");
	gr_pPb_v286sys->Draw("[]2");
	grPAVratio86->Draw("psame");
	gr_pPb_v286->Draw("psame");

	cVratio->cd(1);
	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 0.96, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 0.96, "#bf{CMS}");
	latexS.DrawLatexNDC(0.22, 0.87, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");

	TLegend * legVratio1 = new TLegend(0.2, 0.56, 0.55, 0.71);
	legVratio1->SetFillColor(kWhite);
	legVratio1->SetTextFont(42);
	legVratio1->SetTextSize(0.06);
	legVratio1->SetBorderSize(0);
	legVratio1->AddEntry(gr_pPb_v264,  "pPb 5.02 TeV", "p");
	legVratio1->AddEntry(grPAVratio64, "pPb 8.16 TeV", "p");
	legVratio1->Draw();

	cVratio->cd(2);

	TLegend * legVratio2 = new TLegend(0.2, 0.80, 0.55, 0.95);
	legVratio2->SetFillColor(kWhite);
	legVratio2->SetTextFont(42);
	legVratio2->SetTextSize(0.06);
	legVratio2->SetBorderSize(0);
	legVratio2->AddEntry(gr_pPb_v286,  "pPb 5.02 TeV", "p");
	legVratio2->AddEntry(grPAVratio86, "pPb 8.16 TeV", "p");
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
	// gamma1

	TCanvas * cGamma = MakeCanvas("cGamma", "cGamma", 800, 500);
	makeMultiPanelCanvas(cGamma, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);
	TH2D * hframeG = new TH2D("hframeG", "", 1, 1, 399, 1, -5, 0.5);
	InitHist(hframeG, "N_{trk}^{offline}", "#gamma_{1}^{exp}");

	p = cGamma->cd(1);
	p->SetTopMargin(0.06);
	hframeG->Draw();

	TGraphErrors * grPAGamma1 = (TGraphErrors*) grPA2.grV64->Clone();
	for ( int i = 0; i < grPAGamma1->GetN(); i++ ) {
		double x6 = grPAGamma1->GetX()[i];
		double x2 = grPA2.grV4V2sub->GetX()[i+3];

		double v24 = 1./grPA2.grV4V2sub->GetY()[i+3];
		double v64 = grPA2.grV64->GetY()[i];

		double e24 = grPA2.grV4V2sub->GetEY()[i+3]*v24*v24;
		double e64 = grPA2.grV64->GetEY()[i];

		grPAGamma1->GetY()[i] = -6.*sqrt(2.)*(1-v64)/pow( (v24*v24 -1), 1.5);
		grPAGamma1->GetEY()[i] = 72.*( (e64/(1-v64))*(e64/(1-v64)) +
			9.*v24*v24*e24*e24/(v24*v24-1)/(v24*v24-1) );

		cout << " -> i = " << i << " x6 = " << x6 << " x2 = " << x2 << endl;
	}

	grPAGamma1->SetMarkerStyle(kStar);
	grPAGamma1->Draw("p");

	p = cGamma->cd(2);
	p->SetTopMargin(0.06);
	hframeG->Draw();

	TGraphErrors * grAAGamma1 = (TGraphErrors*) grAA2.grV64->Clone();
	for ( int i = 0; i < grAAGamma1->GetN(); i++ ) {
		double x6 = grAAGamma1->GetX()[i];
		double x2 = grAA2.grV4V2sub->GetX()[i+1];

		double v24 = 1./grAA2.grV4V2sub->GetY()[i+1];
		double v64 = grAA2.grV64->GetY()[i];

		double e24 = grAA2.grV4V2sub->GetEY()[i+1]*v24*v24;
		double e64 = grAA2.grV64->GetEY()[i];

		grAAGamma1->GetY()[i] = -6.*sqrt(2.)*(1-v64)/pow( (v24*v24 -1), 1.5);
		grAAGamma1->GetEY()[i] = 72.*( (e64/(1-v64))*(e64/(1-v64)) +
			9.*v24*v24*e24*e24/(v24*v24-1)/(v24*v24-1) );

		cout << " -> i = " << i << " x6 = " << x6 << " x2 = " << x2 << endl;
	}
	grAAGamma1->SetMarkerStyle(kStar);
	grAAGamma1->Draw("p");

	////////////////////
  // sigma/vn

	TCanvas * cFluct = MakeCanvas("cFluct", "cFluct", 800, 500);
	makeMultiPanelCanvas(cFluct, 2, 1, 0.0, 0., 0.15, 0.15, 0.03);

	TH2D * hframeFluct = new TH2D("hframeFluct", "", 1, 1, 399, 1, 0.0, 1.1);
	InitHist(hframeFluct, "N_{trk}^{offline}", "#sigma_{v} / <v_{n}>");
	hframeFluct->GetXaxis()->SetLabelFont(43);
	hframeFluct->GetXaxis()->SetTitleFont(43);
	hframeFluct->GetXaxis()->SetLabelSize(20);
	hframeFluct->GetXaxis()->SetTitleSize(25);

  TGraphErrors * grPA2Fluct = (TGraphErrors*) grPA2.grV4V2sub->Clone();
  TGraphErrors * grPA3Fluct = (TGraphErrors*) grPA3.grV4V2sub->Clone();
  TGraphErrors * grAA2Fluct = (TGraphErrors*) grAA2.grV4V2sub->Clone();
  TGraphErrors * grAA3Fluct = (TGraphErrors*) grAA3.grV4V2sub->Clone();

  TGraphErrors * grPA2Fluct_sys = (TGraphErrors*) grPA2V42sys->Clone();
  TGraphErrors * grPA3Fluct_sys = (TGraphErrors*) grPA3V42sys->Clone();
  TGraphErrors * grAA2Fluct_sys = (TGraphErrors*) grAA2V42sys->Clone();
  TGraphErrors * grAA3Fluct_sys = (TGraphErrors*) grAA3V42sys->Clone();

  ratio2fluct(grPA2Fluct);
  ratio2fluct(grPA3Fluct);
  ratio2fluct(grAA2Fluct);
  ratio2fluct(grAA3Fluct);

  ratio2fluct(grPA2Fluct_sys);
  ratio2fluct(grPA3Fluct_sys);
  ratio2fluct(grAA2Fluct_sys);
  ratio2fluct(grAA3Fluct_sys);

	p = cFluct->cd(1);
	p->SetTopMargin(0.06);
  hframeFluct->Draw();

  grPA2Fluct_sys->Draw("[]2");
  grPA3Fluct_sys->Draw("[]2");
  grPA2Fluct->Draw("psame");
  grPA3Fluct->Draw("psame");

	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");

	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");

	TLegend * legFluct = new TLegend(0.18, 0.75, 0.7, 0.93);
	legFluct->SetFillColor(kWhite);
	legFluct->SetTextFont(43);
	legFluct->SetTextSize(22);
	legFluct->SetBorderSize(0);

  legFluct->AddEntry(grPA2Fluct, "n = 2", "p");
  legFluct->AddEntry(grPA3Fluct, "n = 3", "p");
  legFluct->Draw();


	p = cFluct->cd(2);
	p->SetTopMargin(0.06);
  hframeFluct->Draw();

  grAA2Fluct_sys->Draw("[]2");
  grAA3Fluct_sys->Draw("[]2");
  grAA2Fluct->Draw("psame");
  grAA3Fluct->Draw("psame");

	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");

	///// save
	cVn->SaveAs("vn.pdf");
	cV2->SaveAs("v2.pdf");
	cV3->SaveAs("v3.pdf");
	cVratio->SaveAs("v2rs.pdf");
	cV42ratio->SaveAs("v42.pdf");
	cGamma->SaveAs("gamma1.pdf");
  cFluct->SaveAs("fluct.pdf");
	/////
	// anime
	p = cV2->cd(1);
	p->SetTopMargin(0.06);
	hframeV2->Draw();

	legV22->Draw();
	grHIN16022pPbV2sys->Draw("[]2");
	grHIN16022pPbV2sub->Draw("Psame");

	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
//	latexS.DrawLatexNDC(0.38, 1.003, "pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");

	p = cV2->cd(2);
	p->SetTopMargin(0.06);
	hframeV2->Draw();
	grHIN16022PbPbV2sys->Draw("[]2");
	grHIN16022PbPbV2sub->Draw("Psame");
//	latexS.DrawLatexNDC(0.25, 1.003, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");

	cV2->SaveAs("v2_0.pdf");

	p = cV2->cd(1);
	grPAV24sys->Draw("[]2");
	grPA2.grV4->Draw("Psame");
	p = cV2->cd(2);
	grAAV24sys->Draw("[]2");
	grAA2.grV4->Draw("Psame");
	cV2->SaveAs("v2_1.pdf");

	p = cV2->cd(1);
	grPAV26sys->Draw("[]2");
	grPA2.grV6->Draw("Psame");
	p = cV2->cd(2);
	grAAV26sys->Draw("[]2");
	grAA2.grV6->Draw("Psame");
	cV2->SaveAs("v2_2.pdf");

	p = cV2->cd(1);
	grPAV28sys->Draw("[]2");
	grPA2.grV8->Draw("Psame");
	p = cV2->cd(2);
	grAAV28sys->Draw("[]2");
	grAA2.grV8->Draw("Psame");
	cV2->SaveAs("v2_3.pdf");

	// v3
	p = cV3->cd(1);
	hframeV3->Draw();
	grHIN16022pPbV3sys->Draw("[]2");
	grHIN16022pPbV3sub->Draw("Psame");
	legV3->Draw();

	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
//	latexS.DrawLatexNDC(0.38, 1.003, "pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");

	p = cV3->cd(2);
	hframeV3->Draw();
	grHIN16022PbPbV3sys->Draw("[]2");
	grHIN16022PbPbV3sub->Draw("Psame");
//	latexS.DrawLatexNDC(0.25, 1.003, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.10, 0.92, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");
	cV3->SaveAs("v3_0.pdf");

	p = cV3->cd(1);
	grPAV34sys->Draw("[]2");
	grPA3.grV4->Draw("Psame");
	p = cV3->cd(2);
	grAAV34sys->Draw("[]2");
	grAA3.grV4->Draw("Psame");
	cV3->SaveAs("v3_1.pdf");

	// v42
	p = cV42ratio->cd(1);
	hframeV42ratio->Draw();
	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 1.0, "#bf{CMS}");
//	latexS.DrawLatexNDC(0.38, 1.003, "pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.68, 1.000, "pPb 8.16 TeV");
	grPA2V42sys->Draw("[]2");
	grPA2.grV4V2sub->Draw("psame");
	latexS.DrawLatexNDC(0.20, 0.90, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");
	p = cV42ratio->cd(2);
	hframeV42ratio->Draw();
	grAA2V42sys->Draw("[]2");
	grAA2.grV4V2sub->Draw("psame");
//	latexS.DrawLatexNDC(0.25, 1.003, "PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 1.000, "PbPb 5.02 TeV");
	legV42b->Draw();
	cV42ratio->SaveAs("v42_0.pdf");
	p = cV42ratio->cd(1);
	grPA3V42sys->Draw("[]2");
	grPA3.grV4V2sub->Draw("psame");
	p = cV42ratio->cd(2);
	grAA3V42sys->Draw("[]2");
	grAA3.grV4V2sub->Draw("psame");
	cV42ratio->SaveAs("v42_1.pdf");

	// v2rs
	cVratio->cd(1);
	hframeVratio->GetYaxis()->SetTitle("v_{2}{6} / v_{2}{4}");
	hframeVratio->DrawClone();
	ffit64->Draw("same");
	if ( bPrelim )
	latexS.DrawLatexNDC(0.15, 0.96, "#bf{CMS} #it{Preliminary}");
	else
	latexS.DrawLatexNDC(0.15, 0.96, "#bf{CMS}");
	latexS.DrawLatexNDC(0.22, 0.87, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{|#eta| < 2.4}");
//	legVratio1->Draw();
	cVratio->cd(2);
	hframeVratio->GetYaxis()->SetTitle("v_{2}{8} / v_{2}{6}");
	hframeVratio->Draw();
	ffit86->Draw("same");
	lred->Draw("lsame");
	lblue->Draw("lsame");
	latexS.DrawLatex(0.66, 0.81, "Fluctuation-Driven Eccentricities");
//	legVratio2->Draw();
	cVratio->SaveAs("v2rs_0.pdf");
	cVratio->cd(1);
	gr_pPb_v264sys->Draw("[]2");
	gr_pPb_v264->Draw("psame");
	legVratio1->Draw();
	cVratio->cd(2);
	gr_pPb_v286sys->Draw("[]2");
	gr_pPb_v286->Draw("psame");
	legVratio2->Draw();
	cVratio->SaveAs("v2rs_1.pdf");
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
